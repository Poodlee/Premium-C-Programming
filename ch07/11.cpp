#include <iostream>
#include <string>

using namespace std;

class Stack {
	int s[100];
	int top;
public:
	Stack() { top = -1; }
	bool operator !() {
		if (top == -1) return true;
		else return false;
	}
	Stack& operator<<(int x) { //지속적인 연산을 위해 Stack& 참조 형식으로 리턴한다.
		s[++top] = x;
		return *this;
	}
	Stack& operator>>(int& x) { //지속적인 연산을 위해 Stack& 참조 형식으로 리턴한다.
		x = s[top--];
		return *this;
	}
};

int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}