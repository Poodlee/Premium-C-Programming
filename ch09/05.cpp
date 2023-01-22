#include <iostream>

using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0; // operation 개별적으로 사용
};
class ANDGate : public AbstractGate {
private:
	bool result;
public:
	ANDGate() { ; }
	bool operation() {
		if (x == 1 && y == 1) {
			result = true;
		}
		else result = false;
		return result;
	}
};
class ORGate : public AbstractGate {
private:
	bool result;
public:
	ORGate() { ; }
	bool operation() {
		if (x == 0 && y == 0) {
			result = false;
		}
		else result = true;
		return result;
	}
};
class XORGate : public AbstractGate {
private:
	bool result;
public:
	XORGate() { ; }
	bool operation() {
		if ((x == 1 && y == 1) || (x==0 && y==0)) {
			result = false;
		}
		else result = true;
		return result;
	}
};

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;

	return 0;
}