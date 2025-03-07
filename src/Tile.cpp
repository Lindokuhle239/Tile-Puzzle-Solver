#include "Tile.h"
#include <iostream>

Tile::Tile(int tileWd, int tileHt){
    wd = tileWd;
    ht = tileHt;
    data = new unsigned char[wd * ht]; //allocate memory
}

Tile::~Tile(){
    delete[] data; //free memory
}