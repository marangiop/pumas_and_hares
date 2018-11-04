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

#ifndef STR
#define XSTR(x) #x
#define STR(x) XSTR(x)
#endif

#ifndef RESOURCES_PATH
#define RESOURCES_PATH ./resources
#define INPUT_FILES_PATH ./resources/input_files
#define CONFIG_PATH ./resources/configurations
#endif

using namespace std;

int main(int argc, char* argv[]) {
    
    string inputFile = STR(INPUT_FILES_PATH/islands.dat);
    string configFile = STR(CONFIG_PATH/param.json);

    if(argc == 3) {
        inputFile = string(argv[1]);
        configFile = string(argv[2]);
    }
    else if(argc == 2) {
        inputFile = string(argv[1]);
    }
    else if(argc > 3) {
        cerr << "Exception in main: wrong arguments" << endl;
        return 0;
    }

    try {
        Helpers::init(inputFile, configFile);
    }
    catch (const runtime_error& re) {
        cerr << re.what() << endl;
        return 0;
    }

    Log::startLogTime("simulation");
    Helpers::simulationLoop();
    Helpers::close();
    cout << endl;
    Log::endLogTime("simulation");
    cout << "The program has finished. All output files have been placed in output folder" << endl << endl;
    return 0;
}
