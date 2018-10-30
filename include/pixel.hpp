/**
 * @file pixel.hpp
 * @author Group 9
 * @date Oct 2018
 * @brief file containing class Pixel
 * @code{.hpp}
 */
#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>
#include <fstream>
#include <sstream>

enum Color { sea, pumas, hares };

using namespace std;

/**
 * @class Pixel
 * @brief ..
 * @details A class for setting the color of a pixel as given in r,g,b format
 */
class Pixel {

	private:
		int red; /**< value of red */
		int green; /**< value of green */
		int blue; /**< value of blue */

        /**
         * @brief sets the rgb color of a pixel
         * @param[in] c type of the color (pumas, hares, or sea)
         * @param[in] opacity color opacity corresponding to density
         */
		void setRgb(Color c, float opacity);
	public:

        /**
         * @brief creates a new pixel with sea color
         */
		Pixel();

        /** 
         * @brief determines the opacity based on the max values and calls set_rgb
         * @param[in] c type for the color
         * @param[in] density density of either pumas or hares for given tile
         * @param[in] maxPumas maximum density of pumas from the whole grid
         * @param[in] maxHares maximum density of hares from the whole grid
         */
		void setColour(Color c, double density, double maxPumas, double maxHares);

        /**
         * @return returns the value of the g rgb value
         */
		int const getGreen();

        /**
         * @return returns the value of the r rgb value
         */
        int const getRed();

        /**
         * @return returns the value of the b rgb value
         */
		int const getBlue();

        /** 
         * @brief writes rgb value to a file
         * @param[in] file ppm file object
         */
        void const write(ofstream &file);
        /**
         * @brief reads rgb string stream
         */
        string read();
};

#endif
