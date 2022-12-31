#include <iostream>
#include <string>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value);
	Accumulator& add(int n);
	int get();
};
Accumulator::Accumulator(int value) {
	this->value = value;
}
int Accumulator::get() {
	return value;
}

Accumulator& Accumulator::add(int n) {  // ���ο� �Լ� Ÿ�� ����.
	value += n;
	return *this;
}

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get();
}