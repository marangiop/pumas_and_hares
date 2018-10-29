#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <iostream>
#include <vector>
#include <assert.h>
#include "tile.hpp"
#include "tileData.hpp"
#include "log.hpp"

#define MAX_NEIGHBOURS 4

using namespace std;

typedef Tile*** TilesArray;

class Landscape {
    
private :
    static Landscape* instance;
    Landscape(vector< vector<TileData*> > tilesVector, int rows, int cols);
    ~Landscape();
    static void getNeighbours(Tile** tilesVector, int row, int col);
    static void getNeighboursInfo(Tile** tilesVector, TileData* tileData, int row, int col);
    TilesArray tiles;
    int rows;
    int cols;
public :
    static void init(vector< vector<TileData*> > tilesVector, int rows, int cols) ;
    static void destroy();
    static void calculate();
    static void update();
    static void print();
    static int const getRows();
    static int const getCols();
    static Tile* getTile(int row, int col);
    static Density const getMaxPumas();
    static Density const getMaxHares();
    static Density const getAveragePumas();
    static Density const getAverageHares();
    static TileData const getRegion(int row, int col, int m, int n);
};

#endif
