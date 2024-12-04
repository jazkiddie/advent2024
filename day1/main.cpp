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
    int x, y;
    int result = 0;

    while (inputFile >> x >> y) {
        xValues.push_back(x);
        yValues.push_back(y);
    }

    inputFile.close();

    std::sort(xValues.begin(), xValues.end());
    std::sort(yValues.begin(), yValues.end());

    for(size_t i = 0 ; i < xValues.size(); ++i) {
        result += std::abs(yValues[i] - xValues[i]);
    }
    std::cout << "Result: " << result << std::endl;

    return 0;
}