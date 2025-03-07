#include "TileManager.h"
#include <sctdlib>

TileManager::TileManager(int size, const std::string& name) : gridSize(size), emptyRow(size - 1), emptyCol(size - 1){
    //load input image
    PGMimage image;
    image.read(name);

    //get  image dimensions
    image.getDims(imageWd, imageHt);

    tileWd = imageWd / gridSize;
    tileHt = imageHt / gridSize;

    //initialize the grid tiles
    grid.resize(gridSize, std::vector<Tile>(gridSize, Tile(tileWd, tileHt)));

    //divide image into tiles and store them in the grid
    const unsigned char* imageData = image.getBuffer();
    for (int y = 0; y < gridSize; ++y){
        for (int x = 0; x < gridSize; ++x){
            grid[y][x].copyData(imageData + (y * tileHt * imageWd + x * tileWd), imageWd, imageHt);
        }
    }
}