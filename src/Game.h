#ifndef GAME_H_
#define GAME_H_

#include "Frame.h"
#include "TenthFrame.h"

class Game {
public:
	Game() {};
	virtual ~Game() {};

	static int score(int rolls[]) {
		TenthFrame frame10{rolls[18], rolls[19], rolls[20]};
		Frame frame9{rolls[16], rolls[17]}; frame9.setNextFrame(&frame10);
		Frame frame8{rolls[14], rolls[15]}; frame8.setNextFrame(&frame9);
		Frame frame7{rolls[12], rolls[13]}; frame7.setNextFrame(&frame8);
		Frame frame6{rolls[10], rolls[11]}; frame6.setNextFrame(&frame7);
		Frame frame5{rolls[8], rolls[9]}; frame5.setNextFrame(&frame6);
		Frame frame4{rolls[6], rolls[7]}; frame4.setNextFrame(&frame5);
		Frame frame3{rolls[4], rolls[5]}; frame3.setNextFrame(&frame4);
		Frame frame2{rolls[2], rolls[3]}; frame2.setNextFrame(&frame3);
		Frame frame1{rolls[0], rolls[1]}; frame1.setNextFrame(&frame2);

		return frame1.score()
				+ frame2.score()
				+ frame3.score()
				+ frame4.score()
				+ frame5.score()
				+ frame6.score()
				+ frame7.score()
				+ frame8.score()
				+ frame9.score()
				+ frame10.score();
	}
};

#endif /* GAME_H_ */
