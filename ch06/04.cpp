#include <iostream>
using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n, int val);
	~MyVector() { delete[]mem; }
	void show() {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += mem[i];
		}
		cout << "모든 mem의 합은 " << sum << "입니다." << endl;
	}
};
MyVector::MyVector(int n=100, int val=0) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++) mem[i] = val;
}

int main() {
	MyVector AQW;
	MyVector AWW(50,2);
	AQW.show();
	AWW.show();
}