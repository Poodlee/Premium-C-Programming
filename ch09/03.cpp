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

class ForLoopAdder : public LoopAdder {
	string names;
public:
	ForLoopAdder(string name) : LoopAdder(name) {
		this->names = name;
	}
	int calculate() {
		int x, y, tmp;
		int sum = 0;
		x = getX(); y = getY();
		if (x > y) {
			tmp = x;
			x = y;
			y = tmp;
		}
		for (int i = x; i <= y; i++) {
			sum += i;
		}
		return sum;
	}
};

int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}