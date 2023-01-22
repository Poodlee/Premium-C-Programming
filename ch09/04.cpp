#include <iostream>
using namespace std;

class LoopAdder { // 추상 클래스
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0; // 순수 가상 함수. 루프를 돌며 합을 구하는 함수
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << "입니다." << endl;
}
void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

class WhileLoopAdder : public LoopAdder {
	string names;
public:
	WhileLoopAdder(string name="") : LoopAdder(name) {
		this->names = name;
	}
	int calculate() {
		int sum = 0;
		int x = getX();
		while (x <= getY()) {
			sum += x;
			x++;
		}
		return sum;
	}
};

class DoWhileLoopAdder : public LoopAdder {
	string names;
public:
	DoWhileLoopAdder(string name="") : LoopAdder(name) {
		this->names = name;
	}
	int calculate() {
		int sum = 0;
		int x = getX();
		do {
			sum += x;
			x++;
		} while (x <= getY());
		return sum;
	}
};

int main() {
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do While Loop");

	whileLoop.run();
	doWhileLoop.run();
}