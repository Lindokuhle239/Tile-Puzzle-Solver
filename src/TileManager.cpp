#include "TileManager.h"
#include <cstdlib>

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

    TileManager::~TileManager(){
        //grid will be managed by std::vector -- so no need dynamic memory to clean up
    }

    bool TileManager::isValidMove(int row, int col) const {
        return (row >= 0 && row < gridSize && col >= 0 && col < gridSize);
    }
}

void TileManager::move(int nextRow, int nextCol){
    if (!isValidMove(nextRow, nextCol)){
        return;
    }
    //swap empty tile with the tile at (nextRow, nextCol)
    std::swap(grid[emptyRow][emptyCol], grid[nextRow][nextCol]);

    //update the position of the empty tile
    emptyRow = nextRow;
    emptyCol = nextCol;
}