#include "TileManager.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
    //seed the random num generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    TileManager manager(3, "test_files/mona512.pgm");

    manager.writeBoardState("output-0.pgm");

    for (int i = 1; i <= 5; ++i){
        manager.generateRandMove();
        manager.writeBoardState("output-" + std::to_string(i) + ".pgm");
    }

    std::cout << "Generated 5 random moves and write output images" << std::endl;
    return 0;
}