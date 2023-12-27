#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

std::vector<std::vector<int>> input(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return -1;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        file.close();
        return { { } };
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

    // Check for an empty matrix
    if (matrix.empty()) {
        std::cerr << "Error: Empty matrix in file " << filename << std::endl;
        return {  };
    }

    // Check for matrix size exceeding 250x250
    const size_t numRows = matrix.size();
    const size_t numCols = row.size();

    if (numRows > 250 || numCols > 250) {
        std::cerr << "Error: Matrix size exceeds the limit of 250x250 in file " << filename << std::endl;
        return -1;
    }

    return matrix;
}
