#include <gtest/gtest.h>

#include "Frame.h"
#include "TenthFrame.h"

TEST(FrameTest, testScoreGutter) {
	Frame frame{0, 0};
	ASSERT_EQ(0, frame.score());
}

TEST(FrameTest, testScoreNoMark) {
	Frame frame{6, 3};
	ASSERT_EQ(9, frame.score());
}

TEST(FrameTest, testScoreSpareStrike) {
	TenthFrame frame10{10, 0, 0};
	Frame frame9{6, 4};
	frame9.setNextFrame(&frame10);
	ASSERT_EQ(20, frame9.score());
}

TEST(FrameTest, testScoreSpareStrikeStrike) {
	TenthFrame frame10{10, 10, 0};
	Frame frame9{10, 0};
	frame9.setNextFrame(&frame10);
	ASSERT_EQ(30, frame9.score());
}

TEST(FrameTest, testScoreSpareWhen8Frame) {
	Frame frame9{10, 0};
	Frame frame8{9, 1};
	frame8.setNextFrame(&frame9);
	ASSERT_EQ(20, frame8.score());
}

TEST(FrameTest, testScoreStrikeWhen8Frame) {
	Frame frame9{8, 1};
	Frame frame8{10, 0};
	frame8.setNextFrame(&frame9);
	ASSERT_EQ(19, frame8.score());
}

TEST(FrameTest, testScoreTurkeyWhen8Frame) {
	TenthFrame frame10{10, 0, 0};
	Frame frame9{10, 0};
	frame9.setNextFrame(&frame10);
	Frame frame8{10, 0};
	frame8.setNextFrame(&frame9);
	ASSERT_EQ(30, frame8.score());
}
