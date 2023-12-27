#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

std::vector<std::vector<int>> readDataFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return {};
    }

    std::vector<std::vector<int>> matrix;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);

        int value;
        while (iss >> value) {
              row.push_back(value);
        }
        
        matrix.push_back(row);
    }

    file.close();
    return matrix;
}

