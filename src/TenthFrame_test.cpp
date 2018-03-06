#include <gtest/gtest.h>

#include "TenthFrame.h"

TEST(TenthFrameTest, testScoreGutter) {
	TenthFrame frame{0, 0, 0};
	ASSERT_EQ(0, frame.score());
}

TEST(TenthFrameTest, testScoreTurkey) {
	TenthFrame frame{10, 10, 10};
	ASSERT_EQ(30, frame.score());
}

TEST(TenthFrameTest, testSpareBonus) {
	TenthFrame frame{10, 10, 10};
	ASSERT_EQ(10, frame.spareBonus());
}

TEST(TenthFrameTest, testStrikeBonus) {
	TenthFrame frame{10, 10, 10};
	ASSERT_EQ(20, frame.strikeBonus());
}
