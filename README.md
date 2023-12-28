<p align="center">
  <img src="gate.png" style="width: 150px;" />
</p>

# Labyrinth Distance Calculator

This program calculates the distance from each empty cell in a labyrinth to the nearest gate using breadth-first search (BFS). The labyrinth is represented as a matrix, where each cell can have one of three values:

- **-1**: Wall or obstacle.
- **0**: Gate.
- **2147483647**: Empty location.

## Files

1. **buildAdjacencyMatrix.cpp**
   - Defines a function to build the adjacency matrix for the labyrinth, representing connections between cells.

2. **findDistances.cpp**
   - Implements BFS to find distances from gates to all reachable cells.

3. **findGates.cpp**
   - Identifies the coordinates of gates in the labyrinth.

4. **output.cpp**
   - Outputs the matrix to a file.

5. **bfs.cpp**
   - Contains the BFS function for finding distances.

6. **input.cpp**
   - Reads a matrix from a file.

7. **main.cpp**
   - Entry point for the program. Reads the labyrinth from "input.txt", finds gates and distances, outputs the result to "output.txt," and runs unit tests.

## Function Explanations

### 1. `buildAdjacencyMatrix` (in `buildAdjacencyMatrix.cpp`)

   This function takes the labyrinth matrix as input and constructs an adjacency matrix representing connections between cells. 
   
```cpp
#include <iostream>
#include <vector>
// Get the input labyrinth matrix
std::vector<std::vector<int>> buildAdjacencyMatrix(const std::vector<std::vector<int>>& labyrinth) {  
    // Implementation
    // Returns the adjacency matrix representing connections between cells
}
```
It iterates through each cell in the labyrinth, skipping walls, and updates the adjacency matrix based on neighboring cells.
```cpp

   if (labyrinth[i][j] == WALL) {
         continue;
   }

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
```

### 2. `output` (in `output.cpp`)

   The `output` function writes a given matrix to an output file. It iterates through each row of the matrix, then through each value in the row, writing them to the output file separated by spaces. It moves to the next line after writing each row.
   ```cpp
   void output(const std::vector<std::vector<int>>& matrix, std::ofstream& output) { // Get the input matrix to be 
       // Iterate through each row in the matrix                                        written to the output file
       for (const auto& row : matrix) {
           // Iterate through each value in the row and write it to the output file
           for (int value : row) {
               output << value << " ";
           }
           // Move to the next line after writing a complete row
           output << "\n";
       }
   }
   ```

### 3. `findDistances` (in `findDistances.cpp`)

   `findDistances` takes the labyrinth matrix and a vector of gate coordinates as input. It calls the `bfs` function for each gate, which performs breadth-first search to find distances from the gate to all reachable cells. The distances are updated in the original matrix.
   
   ```cpp
   // Get the input matrix representing the labyrinth
   void findDistances(std::vector<std::vector<int>>& matrix, const std::vector<std::pair<int, int>>& gates) { 
       // Iterate through each gate in the vector
       for (const auto& gate : gates) {
           // Call BFS to find distances from the current gate to all reachable cells
           bfs(matrix, gate.first, gate.second);
       }
   }
   ```

### 4. `findGates` (in `findGates.cpp`)

   This function identifies the coordinates of gates in the labyrinth.
   
   ```cpp
   std::vector<std::pair<int, int>> findGates(const std::vector<std::vector<int>>& matrix) {
       // Create a vector to store the coordinates of gates
       std::vector<std::pair<int, int>> gates;
       // Implementation
       // Return the vector containing the coordinates of gates
   ```
   
   It iterates through each cell in the matrix, and if the cell contains a gate (value 0), it adds the coordinates to a vector of pairs.
   ```cpp
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
   ```

### 5. `bfs` (in `bfs.cpp`)

   The `bfs` function performs breadth-first search (BFS) starting from a given point in the labyrinth. 
   It uses a queue to traverse neighboring cells and a 2D boolean vector to track visited cells during BFS.

   ![bfs](bfs.gif)
   ```cpp
// Get the input matrix representing the labyrinth
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
   // Implementation
```
   
   It updates the distances from the starting point to all reachable cells. 
   
   **`matrix[row][col] = std::min(matrix[row][col], distance);`**

   
  
### 6. `input` (in `main.cpp`)

   The `input` function reads a matrix from a given file. It opens the file, reads each line, and parses the values into a 2D vector. The resulting matrix is then returned.
   ```cpp
std::vector<std::vector<int>> input(const std::string& filename) { // Get the name of the file to read
    // Open the file for reading
    std::ifstream file(filename);
    // Implementation
    // Return a matrix read from the file
```

### 7. `main` (in `main.cpp`)

   The `main` function serves as the entry point for the program. It reads the labyrinth matrix from "input.txt," finds gates and distances using the provided functions, outputs the result to "output.txt," and runs unit tests using Google Test.

## How to Use

1. Clone repository
   ```bash
   git clone https://github.com/Sadaatva/Walls-and-Gates.git:Walls-and-Gates
   ```
2. Build it via Cmake
3. Ensure you have a file named "input.txt" containing the labyrinth matrix.
4. Run the compiled executable.
5. View the result in the "output.txt" file.

## Unit Tests

The project includes unit tests using Google Test framework. These tests cover different scenarios, such as an empty labyrinth, a labyrinth with gates nearby, and various other cases.

To run the tests, compile the code with the test cases using a testing framework like Google Test.

```bash
./project 
```
