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




//Tests for buildAdjacencyMatrix
TEST(EmptyinputTest, Empty) {
    std::vector<std::vector<int>> input = { {} };
    ASSERT_EQ(0, buildAdjacencyMatrix(input).size());
}

TEST(OneEmptyCageTest, OneEmptyCage) {
    std::vector<std::vector<int>> input = {
        {2147483647},
    };

    std::vector<std::vector<int>> out = {
        {0},
    };

    ASSERT_EQ(out, buildAdjacencyMatrix(input));
}

TEST(TwoEmptyCagesNearTest, TwoEmptyCagesNear) {
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
//Tests for buildAdjacencyMatrix


//Tests for final output 
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

    std::vector<std::pair<int, int>> gates = findGates(input); // Координаты ворот
    findDistances(input, gates);

    ASSERT_EQ(output, input);
} 

TEST(WallsAndGatesTest, ExampleTest2){
    std::vector<std::vector<int>> input = {
        {-1}
    };

    std::vector<std::vector<int>> output = {
        {-1}
    };
    
    std::vector<std::pair<int, int>> gates = findGates(input); // Координаты ворот
    findDistances(input, gates);

    ASSERT_EQ(output, input);
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

    std::vector<std::pair<int, int>> gates = findGates(input); // Координаты ворот
    findDistances(input, gates);

    ASSERT_EQ(output, input);
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

    std::vector<std::pair<int, int>> gates = findGates(input); // Координаты ворот
    findDistances(input, gates);

    ASSERT_EQ(output, input);
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

    std::vector<std::pair<int, int>> gates = findGates(input); // Координаты ворот
    findDistances(input, gates);

    ASSERT_EQ(output, input);
}
//Tests for final output 


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    std::vector<std::vector<int>> labyrinth = input("input.txt");

    std::vector<std::pair<int, int>> gates = findGates(labyrinth); // Координаты ворот
    findDistances(labyrinth, gates);

    std::ofstream OutputFile("output.txt");


    output(labyrinth, OutputFile);

    return RUN_ALL_TESTS();
}
