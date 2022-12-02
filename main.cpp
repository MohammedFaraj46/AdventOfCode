#include <iostream>
#include <fstream>
#include <string>

void calcHighestCalories() {
    std::fstream inputFile;
    std::string line;
    int currentCalc;
    int finalCalc;
    inputFile.open("../input.txt");

    if(inputFile.is_open()){
        while (getline(inputFile, line)){
            if(line.empty()){
                if (currentCalc > finalCalc) finalCalc = currentCalc;

                currentCalc = 0;
                continue;
            }
            currentCalc += std::stoi(line);
        }
        std::cout << "Elf with highest calories: ";
        std::cout << finalCalc << std::endl;
    }
    inputFile.close();
}

void calcTopThreeElves() {
    std::fstream inputFile;
    std::string line;
    int tripleElfCalc[3] = { 0 };
    int currentCalc;
    inputFile.open("../input.txt");

    if(inputFile.is_open()) {
        while (getline(inputFile, line)) {
            if (line.empty()) {
                if (currentCalc > tripleElfCalc[2]) {
                    if (currentCalc > tripleElfCalc[1]) {
                        if (currentCalc > tripleElfCalc[0]) {
                            tripleElfCalc[2] = tripleElfCalc[1];
                            tripleElfCalc[1] = tripleElfCalc[0];
                            tripleElfCalc[0] = currentCalc;
                        } else {
                            tripleElfCalc[2] = tripleElfCalc[1];
                            tripleElfCalc[1] = currentCalc;
                        }
                    } else {
                        tripleElfCalc[2] = currentCalc;
                    }
                }
                currentCalc = 0;
                continue;
            }
            currentCalc += std::stoi(line);
        }
        std::cout << "Top 3 elves with highest calories: ";
        std::cout << tripleElfCalc[0] + tripleElfCalc[1] + tripleElfCalc[2] << std::endl;
    }

    inputFile.close();
}

int main() {
    calcHighestCalories();
    calcTopThreeElves();
}
