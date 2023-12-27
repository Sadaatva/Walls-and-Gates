#include <vector>

// GATE = 0;

/*
 * @brief Find the coordinates of gates in the matrix.
 *
 * @param matrix The input matrix representing the labyrinth.
 * @return A vector of pairs representing the coordinates of gates in the labyrinth.
 */
std::vector<std::pair<int, int>> findGates(const std::vector<std::vector<int>>& matrix) {
    // Create a vector to store the coordinates of gates
    std::vector<std::pair<int, int>> gates;

    // Iterate through each cell in the matrix
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            // Check if the current cell contains a gate
            if (matrix[i][j] == GATE) {
                // Add the coordinates of the gate to the vector
                gates.push_back(std::make_pair(i, j));
            }
        }
    }

    // Return the vector containing the coordinates of gates
    return gates;
}
