#ifndef TENTHFRAME_H_
#define TENTHFRAME_H_

#include "Frame.h"

class TenthFrame: public Frame {
private:
	int _third;
public:
	TenthFrame(int first, int second, int third):
		Frame(first, second), _third(third){};
	virtual ~TenthFrame() {};

	int score() {
		return first() + second() +_third;
	}

	int spareBonus() {
		return first();
	}

	int strikeBonus() {
		return first() + second();
	}

};

#endif /* TENTHFRAME_H_ */
