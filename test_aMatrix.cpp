#include <iostream>
#include <gtest/gtest.h>
#include <vector>

TEST(FirstTest, Empty) {
	std::vector<std::vector<int>> labyrinth
    ASSERT_EQ(0, buildAdjacencyMatrix(labyrinth));
}

TEST(SecondTest, oneEmptyCage) {
	std::vector<std::vector<int>> labyrinth = {
        {2147483647},
    };

    std::vector<std::vector<int>> out = {
        {0},
    };

    ASSERT_EQ(out, buildAdjacencyMatrix(labyrinth));
}

TEST(ThirdTest, twoEmptyCage) {
	std::vector<std::vector<int>> labyrinth = {
        {2147483647, 2147483647},
    };

    std::vector<std::vector<int>> Near = { //When cages is near
        {0, 1},
        {1, 0}
    };
    std::vector<std::vector<int>> notNear = { //When cages is not near
        {0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
    };

    ASSERT_EQ(Near, buildAdjacencyMatrix(labyrinth)); //When cages is near
    ASSERT_EQ(notNear, buildAdjacencyMatrix(labyrinth)); //When cages is near
}

TEST(FourthTest, sample) {
	std::vector<std::vector<int>> labyrinth = {
		{2147483647, -1 ,0, 2147483647},
		{2147483647,2147483647,2147483647,-1},
		{2147483647,-1,2147483647,-1},
		{0,-1,2147483647,2147483647}
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