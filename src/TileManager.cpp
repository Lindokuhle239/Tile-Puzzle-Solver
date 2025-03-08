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
    grid.resize(gridSize);

    //divide image into tiles and store them in the grid
    //const unsigned char* imageData = image.getBuffer();
    for (int y = 0; y < gridSize; ++y){
        grid[y].reserve(gridSize); //reserve space for each row
        for (int x = 0; x < gridSize; ++x){
            //grid[y][x].copyData(imageData + (y * tileHt * imageWd + x * tileWd), imageWd, imageHt);
            grid[y].emplace_back(tileWd, tileHt); //constructs tile obejects in place
        }
    }
    //divide image into tiles and store them in the grid
    const unsigned char* imageData = image.getBuffer();
    for (int y = 0; y < gridSize; ++y){
        for (int x = 0; x < gridSize; ++x){
            grid[y][x].copyData(imageData + (y * tileHt * imageWd + x * tileWd), imageWd, imageHt);
        }
    }    
}

TileManager::~TileManager(){
    //grid will be managed by std::vector -- so no need dynamic memory to clean up
}

bool TileManager::isValidMove(int row, int col) const {
    return (row >= 0 && row < gridSize && col >= 0 && col < gridSize);
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

void TileManager::generateRandMove(){
    //generate a random direction -> up/down/left/right
    int directions[4][2] = {{-1,0}, {1,0}, {0, -1}, {0,1}};
    int randIndex = rand() % 4;

    int nextRow = emptyRow + directions[randIndex][0];
    int nextCol = emptyCol + directions[randIndex][1];

    if (isValidMove(nextRow, nextCol)){
        move(nextRow, nextCol);
    }
}

void TileManager::writeBoardState(const std::string& filename) const{
    //create buffer for the output file
    unsigned char* outputImageData = new unsigned char[imageWd * imageHt];

    //copy each tile's data into the output buffer
    for (int row = 0; row < gridSize; ++row){
        for (int col = 0; col < gridSize; ++col){
            for (int y = 0; y < tileHt; ++y){
                for (int x = 0; x < tileWd; ++x){
                    int outputX = col * tileWd + x;
                    int outputY = row * tileHt + y;

                    if (outputY < imageHt && outputX < imageWd){
                        outputImageData[outputY * imageWd + outputX] = grid[row][col].getPixel(x, y);
                    }
                }
            }
        }
    }
//write the output image
PGMimage outputImage;
outputImage.setImageData(outputImageData, imageWd, imageHt);
outputImage.write(filename);

//clean up
delete[] outputImageData;
}

