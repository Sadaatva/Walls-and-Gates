#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<int>> input(const std::string& filename) {
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

int main() {
    std::string filename = "example.txt"; // Укажите имя вашего файла

    std::vector<std::vector<int>> myMatrix = readDataFromFile(filename);

    return 0;
}
