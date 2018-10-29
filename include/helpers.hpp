#ifndef HELPERS_HPP
#define HELPERS_HPP

#include "output.hpp"
#include "landscape.hpp"
#include "parser.hpp"
#include "configData.hpp"

#define MAX_STEP 500

class Helpers {
private:
    static void initRandomGenerator();

public:
    static void init(string file);

    /**
     * @brief ...
     */
    static void simulationLoop();

    /**
     * @brief ...
     */
    static void close();

    /**
     * @brief ...
     * @return ...
     */
    static vector< vector<int>> initTilesVector(ifstream &landFile);
};

#endif
