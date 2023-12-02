/*
 * Advent of Code
 * Deepak Shenoy
 *
 * Day 01 - Part 1
 * December 1st, 2023
 *
 */

#include <iostream>
#include <fstream>

int main(int argc, char** argv) {

    // Check parameters before processing
    if(argc != 2) {
        std::cout << "Please enter the file input file name.  Usage " << argv[2] << " <input filename> " << std::endl;
        return 0;
    } else {
        std::ifstream inputFile;
        std::string rawCalibrationValue;
        inputFile.open(argv[1]);
        int total = 0;
        while(std::getline(inputFile, rawCalibrationValue)) {
            if(rawCalibrationValue.length()>1) {
                bool foundLeftDelimiter = false, foundRightDelimeter = false;
                int i, j;
                for(i=0, j=rawCalibrationValue.length() - 1; i<=j; !foundLeftDelimiter || !foundRightDelimeter) {
                    if (!foundLeftDelimiter && std::isdigit(rawCalibrationValue[i])) foundLeftDelimiter = true;
                    else if(!foundLeftDelimiter) i++;
                    if (!foundRightDelimeter && std::isdigit(rawCalibrationValue[j])) foundRightDelimeter = true;
                    else if(!foundRightDelimeter) j--;
                    if (foundLeftDelimiter && foundRightDelimeter) break;
                }
                std::string test = rawCalibrationValue.substr(i, 1) + rawCalibrationValue.substr(j, 1);
                if(foundLeftDelimiter && foundRightDelimeter) total += std::stoi(rawCalibrationValue.substr(i, 1) + rawCalibrationValue.substr(j, 1));
            }
        }
        std::cout << total << std::endl;
    }
    return 0;
}
