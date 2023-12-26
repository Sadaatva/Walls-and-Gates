#include <iostream>
#include <vector>
#include <queue>


void bfs(std::vector<std::vector<int>>& matrix, int startRow, int startCol) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(startRow, startCol));
    visited[startRow][startCol] = true;

    int distance = 0;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            matrix[row][col] = std::min(matrix[row][col], distance);

            // Проверяем соседей
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

        ++distance;
    }
}