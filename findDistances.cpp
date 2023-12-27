#include <vector>
#include "bfs.cpp"

// @brief Find distances from gates to all reachable cells using BFS.
// @param matrix The input matrix representing the labyrinth.
// @param gates A vector of pairs representing the coordinates of gates in the labyrinth.
 
void findDistances(std::vector<std::vector<int>>& matrix, const std::vector<std::pair<int, int>>& gates) {
    // Iterate through each gate in the vector
    for (const auto& gate : gates) {
        // Call BFS to find distances from the current gate to all reachable cells
        bfs(matrix, gate.first, gate.second);
    }
}
