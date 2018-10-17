#include "../include/tile.hpp"

Tile::Tile(bool land): Tile(
    land,
    static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5)),
    static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5))
){}

Tile::Tile(bool land, Density hares, Density pumas): land(land) {
	this->clear();
    
    if(this->isLand()) {
        this->oldHares = hares;
        this->oldPumas = pumas;
    }
}

Tile::~Tile() {
	this->clear();
}

void Tile::clear() {
    this->oldHares = 0;
    this->oldPumas = 0;
    this->newHares = 0;
    this->newPumas = 0;
}

void const Tile::print() {
    cout << this->land << ", H" << std::fixed << setprecision(1) << this->oldHares << ", P" << this->oldPumas << "\t";
}

void Tile::calculate(int tile_neighbours, float hare_neighbour_sume, float puma_neighbour_sume) {
    this->newHares = Hare::calculateNewDensity(this->oldHares, this->oldPumas, tile_neighbours, hare_neighbour_sume);
    this->newPumas = Puma::calculateNewDensity(this->oldPumas, this->oldHares, tile_neighbours, puma_neighbour_sume);
}

void Tile::update() {
    this->oldHares = this->newHares;
    this->oldPumas = this->newPumas;
    this->newHares = 0;
    this->newPumas = 0;
}

bool const Tile::isLand() {
    return this->land;
}

Density const Tile::getOldHares() {
    return this->oldHares;
}

Density const Tile::getOldPumas() {
    return this->oldPumas;
}

Density const Tile::getDensity(string animal) {
    if(animal == Puma::getName())
        return getOldPumas();
    else if(animal == Hare::getName())
        return getOldHares();
    return 0;
}
