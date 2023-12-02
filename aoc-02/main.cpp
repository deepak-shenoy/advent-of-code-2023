/*
 * Advent of Code
 * Deepak Shenoy
 *
 * Day 02 - Part 1 and Part 2
 * December 2nd, 2023
 *
 */

#include <iostream>
#include <fstream>

#define NUMBERS_AND_SPACES "01234567890 "
#define COMMA___SEMI_COLON ",;"

#define RED___COLOR "red"
#define BLUE__COLOR "blue"
#define GREEN_COLOR "green"

class Cube {
public:
    // Add getters/settlers later
    Cube(std::string color) {
        this->color = color;
    }
    // Can access directly for now
    std::string color;
};

class Set {
public:
    // Add getter/setters during refactor - for now access can access directly
    Set (int numberOfReds, int numberOfGreens, int numberOfBlues): red(numberOfReds,redCube), blue(numberOfBlues,blueCube), green(numberOfGreens, greenCube) {
        // Empty constructor
    }
    std::vector<Cube> red ;
    std::vector<Cube> green;
    std::vector<Cube> blue;
    inline static const Cube redCube = Cube(RED___COLOR);
    inline static const Cube blueCube = Cube(BLUE__COLOR);
    inline static const Cube greenCube = Cube(GREEN_COLOR);
};

class Game {
public:
    Game(int id) {
        gameId = id;
    }
    int gameId;
    std::vector<Set> sets;
    std::vector<Set> addSet(Set set) {
        sets.push_back(set);
        return sets;
    }
};

int getIdSumFromConstraints(int redConstraintCount, int greenConstraintCount, int blueConstraintCount, std::vector<Game> games) {
    int sumOfIds = 0;
        for(Game g : games) {
            bool isApossibleCombination = true;
            for(Set s: g.sets) {
                if (s.red.size() > redConstraintCount || s.green.size() > greenConstraintCount || s.blue.size() > blueConstraintCount) isApossibleCombination = false;
            }
            if (isApossibleCombination) sumOfIds += g.gameId;
        }
    return sumOfIds;
}

int getPowerSetMinCubesNeeded(std::vector<Game> games) {
    int powerSetTotal = 0;
    for(Game g : games) {
        bool isApossibleCombination = true;
        int maxReds = 0;
        int maxGreens = 0;
        int maxBlues = 0;
        for(Set s: g.sets) {
            if(s.red.size()>maxReds) maxReds = s.red.size();
            if(s.green.size()>maxGreens) maxGreens = s.green.size();
            if(s.blue.size()>maxBlues) maxBlues = s.blue.size();
        }
        int powerSet = maxReds * maxGreens * maxBlues;
        powerSetTotal += powerSet;
    }
    return powerSetTotal;
}

Game getGameData(std::string line) {
    int redCubeCount = 0, greenCubeCount = 0, blueCubeCount = 0;
    int indexOfNonNumber, indexOfNonLetter;

    int lastIndexOfGameIdNumer = line.find_first_of(':', 4);
    Game game = Game(stoi(line.substr(4, lastIndexOfGameIdNumer)));
    int startIndex = lastIndexOfGameIdNumer + 1;
    while(startIndex<line.length()) {
        indexOfNonNumber = line.find_first_not_of(NUMBERS_AND_SPACES, startIndex);
        if (indexOfNonNumber != std::string::npos) {
            indexOfNonLetter = line.find_first_of(COMMA___SEMI_COLON, indexOfNonNumber);
            //std::cout<<line[indexOfNonLetter]<<std::endl;
            int numberOfCubes = std::stoi(line.substr(startIndex, indexOfNonNumber - startIndex));
            std::string cubeColor = line.substr(indexOfNonNumber, indexOfNonLetter - indexOfNonNumber);
            if (cubeColor == RED___COLOR) redCubeCount = numberOfCubes;
            else if (cubeColor == BLUE__COLOR) blueCubeCount = numberOfCubes;
            else if (cubeColor == GREEN_COLOR) greenCubeCount = numberOfCubes;
            else std::cout << "Unknown color " << cubeColor << std::endl;
        } else {
            game.addSet(Set(redCubeCount, greenCubeCount, blueCubeCount));
            return game;
        }
        if (line[indexOfNonLetter] == ';') {
            game.addSet(Set(redCubeCount, greenCubeCount, blueCubeCount));
            redCubeCount = greenCubeCount = blueCubeCount = 0;
        } else if (indexOfNonLetter == std::string::npos) {
            game.addSet(Set(redCubeCount, greenCubeCount, blueCubeCount));
            return game;
        }
        startIndex = indexOfNonLetter + 1;
    }
    printf("end");
}

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Please enter the file input file name.  Usage " << argv[2] << " <input filename> " << std::endl;
        return 0;
    }
    std::ifstream inputFile;
    inputFile.open(argv[1]);
    std::string rawLine;
    std::vector<Game> games;
    while(std::getline(inputFile, rawLine)) {
        // Assume that each line begins with "Game" followed by a number starting at the sixth index and then a game id
        Game game = getGameData(rawLine);
        games.push_back(game);
    }
    std::cout << std::endl<< "Id sum using the constraints of 12 red cubes, 13 green cubes, and 14 blue cubes: ";
    std::cout << getIdSumFromConstraints(12,13,14, games) << std::endl;

    std::cout << std::endl<< std::endl<< "Power set of totals: " << getPowerSetMinCubesNeeded(games) << std::endl;
    return 0;
}
