/**
 * @file main.cpp
 *
 * @brief ...
 *
 * @defgroup input
 * @defgroup pumas_and_hares
 * @defgroup output
 *
 * @author Nikolaos Xenakis http://github.com/nikosxenakis nikosxenakis94@gmail.com
 * @author ...
 * @author ...
 * @author ...
 *
 */

#include "include/helpers.hpp"
#include "include/log.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    
    string inputFile = string(RESOURCES_PATH) + "/land_generator2000x2000_densities_in_the_corners.dat";

    Log::startLogTime("main");
    
    if(argc == 2) {
        string arg = string(argv[1]);
        if(arg == "--help" || arg == "-h"){
            printf("Usage: ./pumas_and_hares path/to/file.dat\n");
            inputFile.clear();
        } else{
            inputFile = arg;
        }
    }
    else if(argc > 2){
        inputFile.clear();
    }

    if(!inputFile.empty()) {
        Helpers::init(inputFile);
        Helpers::simulationLoop();
        Helpers::close();
    }

    Log::endLogTime("main");
    printf("\nThe program has finished. All output files have been placed in output folder\n");
    return 0;
}
