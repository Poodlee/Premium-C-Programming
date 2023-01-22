#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0; //스택에 n을 푸시한다. 스택이 full이면 flase 리턴
	virtual bool pop(int& n) = 0; //스택에서 팝한 정수를 n에 저장하고
								  //스택이 empty면 false 리턴

	virtual int size() = 0; // 순수 가상함수, 현재 스택에 저장된 정수의 개수 리턴

};
class IntStack : public AbstractStack {
	int stack[6] = { 0,0,0,0,0,0 };
	int top = -1;
public:
	bool push(int n) {
		if (size() + 1 >= 6) {
			cout << "Stack이 꽉 찼습니다." << endl;
			return false;
		}
		else {
			stack[++top] = n;
			return true;
		}
	}
	bool pop(int& n) {
		if (size() < 0) {
			cout << "Stack이 텅텅 비었습니다." << endl;
			return false;
		}
		else {
			n = stack[top--];
			return true;
		}		
	}
	int size() { return (top + 1); }
	void show() {
		cout << " | | ";
		for (int i = 0; i <= top; i++)
			cout << stack[i] << ' ';
		cout << " | | " << endl;
	}
};

int main() {
	IntStack intStack;

	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);
	intStack.push(6);

	intStack.show();

	int n;
	intStack.pop(n);
	cout << n << " is popped" << endl;
	intStack.show();

	return 0;
}