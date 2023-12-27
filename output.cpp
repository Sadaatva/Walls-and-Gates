#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

/**
 * @brief Output the matrix to a file.
 *
 * @param matrix The input matrix to be written to the output file.
 * @param output An ofstream object representing the output file stream.
 */

void output(const std::vector<std::vector<int>>& matrix, std::ofstream& output) {
    // Iterate through each row in the matrix
    for (const auto& row : matrix) {
        // Iterate through each value in the row and write it to the output file
        for (int value : row) {
            output << value << " ";
        }
        // Move to the next line after writing a complete row
        output << "\n";
    }
}
