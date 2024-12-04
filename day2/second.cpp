#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

bool isSafe(const std::vector<int>& row) {
    int previous = -1;
    int direction = 0;

    for (const auto& val : row) {
        if (previous != -1) {
            if (previous - val == 0 || 
                (previous - val > 0 && direction < 0) || 
                (previous - val < 0 && direction > 0) || 
                std::abs(previous - val) > 3) {
                return false;
            }
            direction += previous - val;
        }
        previous = val;
    }
    return true;
}

bool isSafeWithOneRemoval(const std::vector<int>& row) {
    for (size_t i = 0; i < row.size(); ++i) {
        std::vector<int> modifiedRow = row;
        modifiedRow.erase(modifiedRow.begin() + i);
        if (isSafe(modifiedRow)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream inputFile("data.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file data.txt" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> data;
    std::string line;

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

    int occurence = 0;

    for (const auto& row : data) {
        if (isSafe(row) || isSafeWithOneRemoval(row)) {
            occurence++;
        }
    }

    std::cout << "Result: " << occurence << std::endl;

    return 0;
}