#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
//#include "output.h"

void output(const std::vector<std::vector<int>>& matrix, std::ofstream& output) {
    for (const auto& row : matrix) {
        for (int value : row) {
            output << value << " ";
        }
        output << "\n";
    }
}
