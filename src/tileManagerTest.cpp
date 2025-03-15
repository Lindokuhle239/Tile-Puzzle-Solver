#include "TileManager.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

int main(int argc, char* argv[]){
    //default vals
    std::string inputImageName = "input.pgm";
    std::string outputBaseName = "output";
    std::string summaryImageName = "";
    int gridSize = 3;
    int numMoves = 5;

    //parse command-line arguments
    for (int i = 1; i < argc; ++i){
        std::string arg = argv[i];
        if ((arg == "-s") && (i + 1 < argc)){
            gridSize = std::stoi(argv[++i]);
        }
        else if ((arg == "-o") && (i + 1 < argc)){
            outputBaseName = argv[++i];
        }
        else if ((arg == "-n") && (i + 1 < argc)){
            numMoves = std::stoi(argv[++i]);
        }
        else if ((arg == "-x") && (i + 1 < argc)){
            summaryImageName = argv[++i];
        }
        else{
            inputImageName = arg;
        }
    }

    //seed the random num generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    TileManager manager(5, "test_files/mona512.pgm");

    manager.writeBoardState("output-0.pgm");

    for (int i = 1; i <= 10; ++i){
        manager.generateRandMove();
        manager.writeBoardState("output-" + std::to_string(i) + ".pgm");
    }

    std::cout << "Generated 5 random moves and write output images" << std::endl;
    return 0;
}