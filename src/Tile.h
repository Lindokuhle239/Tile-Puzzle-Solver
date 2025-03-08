#ifndef TILE_H
#define TILE_H

class Tile{
    public:
        Tile(int tileWd, int tileHt); //Constructor
        ~Tile(); //Destructor  

        //disable copy constructor and assign operator
        Tile(const Tile&) = delete;
        Tile& operator=(const Tile&) = delete;

        unsigned char getPixel(int x, int y) const; //get pixel value
        void setPixel(int x, int y, unsigned char val); //set pixel value

        void copyData(const unsigned char* source, int sourceWd, int sourceHt); //copy pixels

        bool isEmpty() const; //check if tile is empty
        void printTile() const; //print tile data -- for debugging!!!

    private:
        unsigned char* data; //pixel data
        int wd; //tile width
        int ht; //tile height
};
#endif