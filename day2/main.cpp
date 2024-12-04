#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file data.txt" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> data;
    std::string line;
    int previous, direction, cnd;
    int occurence = 0;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<int> values;
        int value;
        while (iss >> value) {
            values.push_back(value);
        }
        data.push_back(values);
    }

    inputFile.close();

    for (const auto& row : data) {
        previous = -1;
        direction = 0;
        cnd = 1;
        for (const auto& val : row) {
            if(previous != -1) {
                if(previous - val == 0) {
                    cnd = 0;
                    break;
                }
                else if ((previous - val > 0) && (direction < 0)) {
                    cnd = 0;
                    break;
                } else if ((previous - val < 0) && (direction > 0)) {
                    cnd = 0;
                    break;
                } else if (abs(previous - val) > 3) {
                    cnd = 0;
                    break;
                } else {
                    direction += previous - val;
                }
                previous = val;
            } else {
                previous = val;
            }
        }
        if (cnd) {
            occurence++;
        }
    }

    std::cout << "Result: " << occurence << std::endl;

    return 0;
}