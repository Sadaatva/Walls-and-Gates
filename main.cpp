#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <gtest/gtest.h>

#include "input.cpp"
#include "output.cpp"
#include "findDistances.cpp"
#include "findGates.cpp"
#include "buildAdjacencyMatrix.cpp"

// Tests for buildAdjacencyMatrix
TEST(EmptyinputTest, Empty) {
    // Test case with an empty input matrix
    std::vector<std::vector<int>> input = { {} };
    ASSERT_EQ(0, buildAdjacencyMatrix(input).size());
}

TEST(OneEmptyCageTest, OneEmptyCage) {
    // Test case with one empty cage
    std::vector<std::vector<int>> input = {
        {2147483647},
    };

    std::vector<std::vector<int>> out = {
        {0},
    };

    ASSERT_EQ(out, buildAdjacencyMatrix(input));
}

TEST(TwoEmptyCagesNearTest, TwoEmptyCagesNear) {
    // Test case with two empty cages that are near each other
    std::vector<std::vector<int>> input = {
        {2147483647, 2147483647},
    };

    std::vector<std::vector<int>> near = {
        {0, 1},
        {1, 0}
    };

    ASSERT_EQ(near, buildAdjacencyMatrix(input));
}

TEST(TwoEmptyCagesNotNearTest, TwoEmptyCagesNotNear) {
    // Test case with two empty cages that are not near each other
    std::vector<std::vector<int>> input = {
        {2147483647, -1},
        {-1, 2147483647}
    };

     std::vector<std::vector<int>> notNear = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    ASSERT_EQ(notNear, buildAdjacencyMatrix(input));
}

TEST(SampleTest, Sample) {
    // Sample test case
    std::vector<std::vector<int>> input = {
        {2147483647, -1, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, -1},
        {0, -1, 2147483647, 2147483647}
    };

    std::vector<std::vector<int>> out = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    };

    ASSERT_EQ(out, buildAdjacencyMatrix(input));
}
// Tests for buildAdjacencyMatrix

// Tests for final output 
TEST(WallsAndGatesTest, ExampleTest) {
    // Example test for the final output
    std::vector<std::vector<int>> input = {
        {2147483647, -1, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, -1},
        {0, -1, 2147483647, 2147483647}
    };
    
    std::vector<std::vector<int>> output = {
        {3, -1, 0, 1},
        {2, 2, 1, -1},
        {1, -1, 2, -1},
        {0, -1, 3, 4}
    };

    std::vector<std::pair<int, int>> gates = findGates(input); // Coordinates of gates
    findDistances(input, gates);

    ASSERT_EQ(output, input);
} 

TEST(WallsAndGatesTest, ExampleTest2){
    // Another example test for the final output
    std::vector<std::vector<int>> input = {
        {-1}
    };

    std::vector<std::vector<int>> output = {
        {-1}
    };
    
    std::vector<std::pair<int, int>> gates = findGates(input); // Coordinates of gates
    findDistances(input, gates);

    ASSERT_EQ(output, input);
}

TEST(WallsAndGatesTest, NoGateTest) {
    // Test case with no gates
    std::vector<std::vector<int>> input = {
        {-1, -1, 0},
        {-1, 0, -1},
        {-1, -1, -1}
    };

    std::vector<std::vector<int>> output = {
        {-1, -1, 0},
        {-1, 0, -1},
        {-1, -1, -1}
    };

    std::vector<std::pair<int, int>> gates = findGates(input); // Coordinates of gates
    findDistances(input, gates);

    ASSERT_EQ(output, input);
}

TEST(WallsAndGatesTest, NoWallsTest) {
    // Test case with no walls
    std::vector<std::vector<int>> input = {
        {0, 2147483647, 0, 2147483647},
        {2147483647, 0, 2147483647, 0},
        {0, 0, 0, 0},
        {2147483647, 0, 2147483647, 0}
    };

    std::vector<std::vector<int>> output = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 0, 1, 0}
    };

    std::vector<std::pair<int, int>> gates = findGates(input); // Coordinates of gates
    findDistances(input, gates);

    ASSERT_EQ(output, input);
}

TEST(WallsAndGatesTest, GatesNearby) {
    // Test case with gates nearby
    std::vector<std::vector<int>> input = {
        {2147483647, 2147483647, 2147483647, 2147483647},
        {2147483647, 0, 0, 2147483647},
        {2147483647, 0, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, 2147483647}
    };

    std::vector<std::vector<int>> output = {
        {2, 1, 1, 2},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {2, 1, 1, 2}
    };

    std::vector<std::pair<int, int>> gates = findGates(input); // Coordinates of gates
    findDistances(input, gates);

    ASSERT_EQ(output, input);
}
// Tests for final output 

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    std::vector<std::vector<int>> labyrinth = input("input.txt");

    std::vector<std::pair<int, int>> gates = findGates(labyrinth); // Coordinates of gates
    findDistances(labyrinth, gates);

    std::ofstream OutputFile("output.txt");

    output(labyrinth, OutputFile);

    return RUN_ALL_TESTS();
}
