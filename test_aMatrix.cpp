#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "buildAdjacencyMatrix.cpp"

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

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
