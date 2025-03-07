#ifndef TILE_H
#define TILE_H

class Tile{
    public:
        Tile(int tileWd, int tileHt); //Constructor
        Tile(); //Destructor  

        unsigned char getPixel(int x, int y) const; //get pixel value
        void setPixel(int x, int y, unsigned char val); //set pixel value
};