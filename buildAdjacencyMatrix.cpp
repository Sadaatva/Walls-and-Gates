#include <iostream>
#include <vector>




std::vector<std::vector<int>> buildAdjacencyMatrix(const std::vector<std::vector<int>>& labyrinth) {
    int rows = labyrinth.size();
    int cols = labyrinth[0].size();
    int numVertices = rows * cols;

    std::vector<std::vector<int>> adjacencyMatrix(numVertices, std::vector<int>(numVertices, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (labyrinth[i][j] == WALL) {
                continue; // Skip walls
            }

            // Check neighboring cells
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

    return adjacencyMatrix;
}