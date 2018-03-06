#ifndef FRAME_H_
#define FRAME_H_

class Frame {
private:
	int _first;
	int _second;
	Frame* _next;
public:
	Frame(int first, int second):
		_first(first), _second(second){};
	virtual ~Frame(){};

	void setNextFrame(Frame* next) {
		_next = next;
	}

	int score() {
		int bonus{0};
		if (_first == 10) {
			bonus = _next->strikeBonus();
		} else if (_first + _second == 10) {
			bonus = _next->spareBonus();
		}
		return _first + _second + bonus;
	}

	virtual int spareBonus() {
		return _first;
	}

	virtual int strikeBonus() {
		if (_first < 10) {
			return _first + _second;
		}
		return 10 + _next->first();
	}

protected:
	int first() { return _first; }
	int second() { return _second; }

};

#endif /* FRAME_H_ */
