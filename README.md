# Tile Puzzle Solver

This program generates a tile puzzle solver from a pgm image and simulates random moves to solve it. It outputs the intermediate board states and a summary image.

# Directory Structure

Assignment/
|--src/
|  |--PGMimage.h	
|  |--PGMimage.cpp
|  |--Tile.h
|  |--Tile.cpp
|  |--TileManager.h
|  |--TileManager.cpp
|  |--tileManagerTest
|--test_file/
|  |--mona512.pgm
|  |--raytrace.pgm
|  |--steelb.pgm
|--Makefile
|--README.md

# Requirements

- C++ compiler
- 'make' utility

# Building the Program

1. Navigate to the "MDLLIN028" directory.
2. Run the following command to compile the program
    'make'
- This will create an executable in the bin/ directory.

# Running the Program

You can run the program using this argument format:
    ./bin/program -s <gridSize> -o <output_base_image> -n <num_moves> -x <summary_image_name> <input_image>

Example:
    ./bin/program -s 3 -o output -n 5 -x summary.pgm test_files/raytrace.pgm

# Cleaning the Build

- To remove all build artifacts and generated files: 
    'make clean'

# Note

- The program generates intermediate board states (output-0.pgm, output-1.pgm, etc) and a summary image (summary.pgm).