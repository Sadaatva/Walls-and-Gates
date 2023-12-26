#include <vector>


std::vector<std::pair<int, int>> findGates(const std::vector<std::vector<int>>& matrix) {
    std::vector<std::pair<int, int>> gates;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == GATE) {
                gates.push_back(std::make_pair(i, j));
            }
        }
    }

    return gates;
}