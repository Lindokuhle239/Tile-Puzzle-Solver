#ifndef TILEMANAGER_H
#define TILEMANAGER_H
#include "Tile.h"
#include "PGMimage.h"
#include <vector>

class TileManager{
    public:
        TileManager(int size, const std::string& image); //constructor
        ~TileManager(); //destructor
}