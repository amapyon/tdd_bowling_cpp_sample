#include <gtest/gtest.h>
#include "Game.h"

TEST(GameTest, testScoreAllGutter) {
	int rolls[] = {0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,0};
	ASSERT_EQ(0, Game::score(rolls));
}

TEST(GameTest, testScore) {
	int rolls[] = {5,4, 0,0, 10,0, 9,1, 6,3, 7,0, 6,2, 10,0, 10,0, 1,9,5};
	ASSERT_EQ(125, Game::score(rolls));
}
