#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file data.txt" << std::endl;
        return 1;
    }

    std::vector<int> xValues;
    std::vector<int> yValues;
    int x, y, occurence;
    int result = 0;

    while (inputFile >> x >> y) {
        xValues.push_back(x);
        yValues.push_back(y);
    }

    inputFile.close();

    std::sort(xValues.begin(), xValues.end());
    std::sort(yValues.begin(), yValues.end());
    for (const int& value : xValues) {
        occurence = 0;
        for (size_t i = 0; i < yValues.size(); i++) {
            if (yValues[i] == value) {
                occurence++;
            }
        }
        result += value * occurence;
    }
    std::cout << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}