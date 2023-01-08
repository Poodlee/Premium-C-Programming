#include <iostream>
#include <string>
using namespace std;

class MyIntStack { //Stack 클래스
	int* p; // 스택 메모리로 사용할 포인터
	int size;  // 스택의 최대 크기
	int tos;  // 스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() { tos = -1; size = 1; p = new int[size];}
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);
	~MyIntStack() { delete[] p; }
	bool push(int n); //정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 팝하여 n에 저장, 스택이 비어 있으면 false, 아니면 true 리턴

};
MyIntStack::MyIntStack(int size) {
	this->p = new int[size];
	this->size = size;
	this->tos = -1;
}
MyIntStack::MyIntStack(const MyIntStack& s) {
	int len = s.size;
	this->p = new int[len];
	this->size = len;
	this->tos = s.tos;

	for (int i = 0; i <= tos; i++) {
		this->p[i] = s.p[i];
	}
}
bool MyIntStack::push(int n) {
	if (tos >= 9) { return false; }
	p[++tos] = n;
	return true;
}
bool MyIntStack::pop(int& n) {
	if (tos < 0) { return false; }
	n = p[tos--];
	return true;
}


int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //깊은 복사
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}