#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

/**
 * @brief Read a matrix from a file.
 *
 * @param filename The name of the file to read.
 * @return A matrix read from the file.
 */
std::vector<std::vector<int>> input(const std::string& filename) {
    // Open the file for reading
    std::ifstream file(filename);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return {};
    }

    // Initialize a 2D vector to store the matrix
    std::vector<std::vector<int>> matrix;
    std::string line;

    // Read each line from the file
    while (std::getline(file, line)) {
        // Initialize a vector to store values in the current row
        std::vector<int> row;
        std::istringstream iss(line);

        int value;

        // Read values from the current line and add them to the row vector
        while (iss >> value) {
            row.push_back(value);
        }

        // Add the row vector to the matrix
        matrix.push_back(row);
    }

    // Close the file after reading
    file.close();

    // Return the matrix read from the file
    return matrix;
}
