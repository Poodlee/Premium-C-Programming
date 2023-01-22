#include <iostream>
using namespace std;

class LoopAdder { // �߻� Ŭ����
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0; // ���� ���� �Լ�. ������ ���� ���� ���ϴ� �Լ�
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "���� " << y << "������ �� = " << sum << "�Դϴ�." << endl;
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