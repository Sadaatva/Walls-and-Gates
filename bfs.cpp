#include <iostream>
#include <vector>
#include <queue>

// Constants representing different types of cells
const int WALL = -1;
const int GATE = 0;
const int EMPTY = 2147483647;

/**
 * @brief Perform breadth-first search (BFS) to find distances from a starting point to all reachable cells.
 *
 * @param matrix The input matrix representing the labyrinth.
 * @param startRow The starting row for BFS.
 * @param startCol The starting column for BFS.
 */
void bfs(std::vector<std::vector<int>>& matrix, int startRow, int startCol) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Create a 2D boolean vector to track visited cells during BFS
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    // Create a queue for BFS and enqueue the starting point
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(startRow, startCol));
    visited[startRow][startCol] = true;

    int distance = 0;  // Initialize distance

    // Perform BFS
    while (!q.empty()) {
        int levelSize = q.size();

        // Process all nodes at the current level of BFS
        for (int i = 0; i < levelSize; ++i) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Update the distance in the matrix
            matrix[row][col] = std::min(matrix[row][col], distance);

            // Check neighboring cells and enqueue unvisited neighbors
            if (row - 1 >= 0 && !visited[row - 1][col] && matrix[row - 1][col] != WALL) {
                q.push(std::make_pair(row - 1, col));
                visited[row - 1][col] = true;
            }
            if (row + 1 < rows && !visited[row + 1][col] && matrix[row + 1][col] != WALL) {
                q.push(std::make_pair(row + 1, col));
                visited[row + 1][col] = true;
            }
            if (col - 1 >= 0 && !visited[row][col - 1] && matrix[row][col - 1] != WALL) {
                q.push(std::make_pair(row, col - 1));
                visited[row][col - 1] = true;
            }
            if (col + 1 < cols && !visited[row][col + 1] && matrix[row][col + 1] != WALL) {
                q.push(std::make_pair(row, col + 1));
                visited[row][col + 1] = true;
            }
        }

        // Move to the next level in BFS
        ++distance;
    }
}
