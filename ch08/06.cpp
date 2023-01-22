#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity; // �迭�� ũ��
	int* mem; // ���� �迭�� ����� ���� �޸��� ������
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	virtual ~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};
class MyStack : public BaseArray {
	int start, end;
public:
	MyStack(int capacity = 0) : BaseArray(capacity) { start = 0; end = 0; }
	void push(int n) { put(end, n); end++; }
	int capacity() { return getCapacity(); }
	int length() { return end - start; }
	int pop() { return get(--end); }
	
};

int main() {
	MyStack mStack(100);
	int n;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); //���ÿ� ����
	}
	cout << "������ �뷮:" << mStack.capacity() << ", ������ ũ��:" << mStack.length() << endl;
	cout << "������ ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; //���ÿ��� �����Ͽ� ���
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}

