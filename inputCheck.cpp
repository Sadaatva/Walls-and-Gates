#include <iostream>
#include <vector>
#include <queue>
#include <fstream>


int inputCheck(std::vector<std::vector<int>>& matrix, std::ifstream& input) {
    int rows, cols;

    if (!(input >> rows >> cols)) {
        std::cerr << "Error" << "\n";
        return -1;
    }

    if (rows <= 0 || cols <= 0 || rows > 250 || cols > 250) {
        std::cerr << "Error" << "\n";
        return -1;
    }

    matrix.resize(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(input >> matrix[i][j])) {
                std::cerr << "Error" << "\n";
                return -1;
            }

            if (matrix[i][j] != -1 && matrix[i][j] != 0 && matrix[i][j] != 2147483647) {
                std::cerr << "Error" << std::endl;
                return -1;
            }
        }
    }
}
