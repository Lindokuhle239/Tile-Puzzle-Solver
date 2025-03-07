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

unsigned char Tile::getPixel(int x, int y) const{
    return data[y * wd + x]; //return pixel value
}

void Tile::setPixel(int x, int y, unsigned char val){
    data[y * wd + x] = val; //set pixel data
}