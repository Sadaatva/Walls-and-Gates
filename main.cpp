#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <gtest/gtest.h>
#include "input.cpp"
#include "output.cpp"
#include "findDistances.cpp"

// Tests for input
TEST(MatrixOperationsTest, EmptyInputFile) {
    std::ofstream emptyOutputFile("empty_input.txt");
    emptyOutputFile.close();

    std::ifstream emptyInputFile("empty_input.txt");

    std::vector<std::vector<int>> matrix;
    inputMatrix(matrix, emptyInputFile);

    emptyInputFile.close();
    ASSERT_TRUE(matrix.empty());
    std::remove("empty_input.txt");
}
// Tests for input


//Tests for buildAdjacencyMatrix
TEST(EmptyLabyrinthTest, Empty) {
    std::vector<std::vector<int>> labyrinth = { {} };
    ASSERT_EQ(0, buildAdjacencyMatrix(labyrinth).size());
}

TEST(OneEmptyCageTest, OneEmptyCage) {
    std::vector<std::vector<int>> labyrinth = {
        {2147483647},
    };

    std::vector<std::vector<int>> out = {
        {0},
    };

    ASSERT_EQ(out, buildAdjacencyMatrix(labyrinth));
}

TEST(TwoEmptyCagesNearTest, TwoEmptyCagesNear) {
    std::vector<std::vector<int>> labyrinth = {
        {2147483647, 2147483647},
    };

    std::vector<std::vector<int>> near = {
        {0, 1},
        {1, 0}
    };

    ASSERT_EQ(near, buildAdjacencyMatrix(labyrinth));
}

TEST(TwoEmptyCagesNotNearTest, TwoEmptyCagesNotNear) {
    std::vector<std::vector<int>> labyrinth = {
        {2147483647, -1},
        {-1, 2147483647}
    };

     std::vector<std::vector<int>> notNear = {
        {0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
    };
    ASSERT_EQ(notNear, buildAdjacencyMatrix(labyrinth));
}

TEST(SampleTest, Sample) {
    std::vector<std::vector<int>> labyrinth = {
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

    ASSERT_EQ(out, buildAdjacencyMatrix(labyrinth));
}
//Tests for buildAdjacencyMatrix


//Tests for findDistances
TEST(WallsAndGatesTest, ExampleTest) {
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

    std::vector<std::pair<int, int>> gates; 
    ASSERT_EQ(output, findDistances(input, gates));
} 

TEST(WallsAndGatesTest, ExampleTest2){
    std::vector<std::vector<int>> input = {
        {-1}
    };

    std::vector<std::vector<int>> output = {
        {-1}
    };
    
    std::vector<std::pair<int, int>> gates; 
    ASSERT_EQ(output, findDistances(input, gates));
}

TEST(WallsAndGatesTest, NoGateTest) {
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

    std::vector<std::pair<int, int>> gates; 
    ASSERT_EQ(output, findDistances(input, gates));
}

TEST(WallsAndGatesTest, NoWallsTest) {
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

    std::vector<std::pair<int, int>> gates; 
    ASSERT_EQ(output, findDistances(input, gates));
}

TEST(WallsAndGatesTest, GatesNearby) {
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

    std::vector<std::pair<int, int>> gates; 
    ASSERT_EQ(output, findDistances(input, gates));
}
//Tests for findDistances


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
