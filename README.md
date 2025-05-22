## Tile Puzzle Solver

This program generates a tile puzzle solver from a pgm image and simulates random moves to solve it. It outputs the intermediate board states and a summary image.

## Directory Structure

Assignment/
|--src/

|    |--PGMimage.h	

|    |--PGMimage.cpp

|    |--Tile.h

|    |--Tile.cpp

|    |--TileManager.h

|    |--TileManager.cpp

|    |--tileManagerTest

|--test_file/

|    |--mona512.pgm

|    |--raytrace.pgm

|    |--steelb.pgm

|--Makefile

|--README.md

## File Descriptions

### src/Tile.h and src/Tile.cpp
- **Purpose**: These files define and implement the 'Tile' class, which represents a single tile in the puzzle.
- **Key Features**:
    - 'getPixel(int x, int y)': Returns pixel value at the specified coordinates
    - 'setPixel(int x, int y, unsigned char val)': Sets the pixel value at the specified coordinates.
    - copyData(const unsigned char* source, int sourceWd, int sourceHt)': Copied pixel data from a source buffer.
- **Roles in Program**: This class is used to manage the pixel data of each tile in the puzzle.

### src/TileManager.h and src/TileManager.cpp
- **Purpose**: Manages the grid of tiles and simulates the puzzle.
- **Key Functions**: 
    - 'generateRandMove()': Generates a random valid move in the puzzle
    - 'writeBoardState(const std::string& fileName)': Writes the current board state to a PGM file. 
- **Roles in Program**: Handles the core logic of the puzzle, including tile movement and image generation.

### src.tileManagerTest.cpp
- **Purpose**: Contains the main method, and serves as the starting point of the program.
- **Key Functions**: 
    - Parses command line arguments to configure the puzzle.
    - Initializes the 'TileManager' and runs the puzzle simulation.
- **Roles in Program**: Ties everthing together and allows the program to be executed with user-defined parameters.

### test_files/
- **Purpose**: Contains sample pgm files for testing the program.
- **Files**:
    - 'mona512.pgm', 'raytrace.pgm' and 'steelb.pgm'.

### Makefile
- **Purpose**: Automates the compilation of the program.

## Requirements

- C++ compiler
- 'make' utility

## Building the Program

1. Navigate to the "MDLLIN028" directory.
2. Run the following command to compile the program
    'make'
    
- This will create an executable in the bin/ directory.

## Running the Program

- You can run the program using this argument format:
    ./bin/program -s <gridSize> -o <output_base_image> -n <num_moves> -x <summary_image_name> <input_image>

- **Example:**
    ./bin/program -s 3 -o output -n 5 -x summary.pgm test_files/raytrace.pgm

## Cleaning the Build

- To remove all build artifacts and generated files: 
    'make clean'

## Note

- The program generates intermediate board states (output-0.pgm, output-1.pgm, etc) and a summary image (summary.pgm).
