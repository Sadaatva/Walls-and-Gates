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

   This function takes the labyrinth matrix as input and constructs an adjacency matrix representing connections between cells. It iterates through each cell in the labyrinth, skipping walls, and updates the adjacency matrix based on neighboring cells.

### 2. `output` (in `output.cpp`)

   The `output` function writes a given matrix to an output file. It iterates through each row of the matrix, then through each value in the row, writing them to the output file separated by spaces. It moves to the next line after writing each row.

### 3. `findDistances` (in `findDistances.cpp`)

   `findDistances` takes the labyrinth matrix and a vector of gate coordinates as input. It calls the `bfs` function for each gate, which performs breadth-first search to find distances from the gate to all reachable cells. The distances are updated in the original matrix.

### 4. `findGates` (in `findGates.cpp`)

   This function identifies the coordinates of gates in the labyrinth. It iterates through each cell in the matrix, and if the cell contains a gate (value 0), it adds the coordinates to a vector of pairs.

### 5. `bfs` (in `bfs.cpp`)

   The `bfs` function performs breadth-first search (BFS) starting from a given point in the labyrinth. It updates the distances from the starting point to all reachable cells. It uses a queue to traverse neighboring cells and a 2D boolean vector to track visited cells during BFS.

### 6. `input` (in `main.cpp`)

   The `input` function reads a matrix from a given file. It opens the file, reads each line, and parses the values into a 2D vector. The resulting matrix is then returned.

### 7. `main` (in `main.cpp`)

   The `main` function serves as the entry point for the program. It reads the labyrinth matrix from "input.txt," finds gates and distances using the provided functions, outputs the result to "output.txt," and runs unit tests using Google Test.

## How to Use

1. Compile the code with your preferred C++ compiler.
2. Ensure you have a file named "input.txt" containing the labyrinth matrix.
3. Run the compiled executable.
4. View the result in the "output.txt" file.

## Unit Tests

The project includes unit tests using Google Test framework. These tests cover different scenarios, such as an empty labyrinth, a labyrinth with gates nearby, and various other cases.

To run the tests, compile the code with the test cases using a testing framework like Google Test.

```bash
./your_executable_name
