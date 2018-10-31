#include "../include/configData.hpp"

float ConfigData::deltaT = 0.4;
int ConfigData::capitalT = 200;
vector< vector<TileData*> > ConfigData::tilesVector;
size_t ConfigData::NX = 0;
size_t ConfigData::NY = 0;

void ConfigData::setDeltaT(float deltaT) {
    ConfigData::deltaT = deltaT;
}

float ConfigData::getDeltaT() {
    return ConfigData::deltaT;
}

void ConfigData::setCapitalT(int capitalT) {
    ConfigData::capitalT = capitalT;
}

int ConfigData::getCapitalT() {
    return ConfigData::capitalT;
}

void ConfigData::initLandscapeData(vector< vector<TileData*> > tilesVector, size_t NX, size_t NY) {
    ConfigData::tilesVector = tilesVector;
    ConfigData::NX = NX;
    ConfigData::NY = NY;

}
