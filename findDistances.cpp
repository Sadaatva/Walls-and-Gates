#include <vector>
#include "bfs.cpp"

void findDistances(std::vector<std::vector<int>>& matrix, const std::vector<std::pair<int, int>>& gates) {
    for (const auto& gate : gates) {
        bfs(matrix, gate.first, gate.second);
    }
}