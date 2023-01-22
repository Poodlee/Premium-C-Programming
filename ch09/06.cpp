#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0; //���ÿ� n�� Ǫ���Ѵ�. ������ full�̸� flase ����
	virtual bool pop(int& n) = 0; //���ÿ��� ���� ������ n�� �����ϰ�
								  //������ empty�� false ����

	virtual int size() = 0; // ���� �����Լ�, ���� ���ÿ� ����� ������ ���� ����

};
class IntStack : public AbstractStack {
	int stack[6] = { 0,0,0,0,0,0 };
	int top = -1;
public:
	bool push(int n) {
		if (size() + 1 >= 6) {
			cout << "Stack�� �� á���ϴ�." << endl;
			return false;
		}
		else {
			stack[++top] = n;
			return true;
		}
	}
	bool pop(int& n) {
		if (size() < 0) {
			cout << "Stack�� ���� ������ϴ�." << endl;
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