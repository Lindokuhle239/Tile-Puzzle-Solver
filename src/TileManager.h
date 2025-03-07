#ifndef TILEMANAGER_H
#define TILEMANAGER_H
#include "Tile.h"
#include "PGMimage.h"
#include <vector>

class TileManager{
    public:
        TileManager(int size, const std::string& image); //constructor
        ~TileManager(); //destructor

        void generateRandMove(); //generate a random valid move
        void writeBoardState(const std::string& fileName) const; //write the board state to a pgm file

    private:
        std::vector<std::vector<Tile>> grid; //grid of tiles
        int emptyRow, emptyCol; //position of the empty file
        int gridSize; //size of the grid
        int imageWd, imageHt; //dimensions of the input image
        int tileWd, tileHt; //dimensions of each tile
}