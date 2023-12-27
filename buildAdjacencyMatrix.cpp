#include <iostream>
#include <vector>

// WALL = -1;

/**
 * @brief Build the adjacency matrix for a labyrinth.
 *
 * @param labyrinth The input labyrinth matrix.
 * @return The adjacency matrix representing connections between cells.
 */
 
std::vector<std::vector<int>> buildAdjacencyMatrix(const std::vector<std::vector<int>>& labyrinth) {
    // Get the number of rows and columns in the labyrinth
    int rows = labyrinth.size();
    int cols = labyrinth[0].size();
    int numVertices = rows * cols;

    // Initialize the adjacency matrix with zeros
    std::vector<std::vector<int>> adjacencyMatrix(numVertices, std::vector<int>(numVertices, 0));

    // Iterate through each cell in the labyrinth
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Skip walls
            if (labyrinth[i][j] == WALL) {
                continue;
            }

            // Check neighboring cells and update the adjacency matrix
            if (i - 1 >= 0 && labyrinth[i - 1][j] != WALL) {
                adjacencyMatrix[i * cols + j][(i - 1) * cols + j] = 1;
            }
            if (i + 1 < rows && labyrinth[i + 1][j] != WALL) {
                adjacencyMatrix[i * cols + j][(i + 1) * cols + j] = 1;
            }
            if (j - 1 >= 0 && labyrinth[i][j - 1] != WALL) {
                adjacencyMatrix[i * cols + j][i * cols + (j - 1)] = 1;
            }
            if (j + 1 < cols && labyrinth[i][j + 1] != WALL) {
                adjacencyMatrix[i * cols + j][i * cols + (j + 1)] = 1;
            }
        }
    }

    // Return the generated adjacency matrix
    return adjacencyMatrix;
}
