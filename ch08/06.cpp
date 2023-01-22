#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity; // 배열의 크기
	int* mem; // 정수 배열을 만들기 위한 메모리의 포인터
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
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); //스택에 삽입
	}
	cout << "스택의 용량:" << mStack.capacity() << ", 스택의 크기:" << mStack.length() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; //스택에서 제거하여 출력
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}

