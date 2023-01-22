#include <iostream>
#include <string>
using namespace std;

// 정수 배열을 항상 증가 순으로 유지.  (클래스 작성 및 + = 연산자 중복 작성)
class SortedArray {
private:
	int size; //현재 배열의 크기
	int* p; //정수 배열에 대한 포인터
	void sort(); // 정수 배열을 오름차순으로 정렬
public:
	SortedArray(); //p는 NULL로 size는 0으로 초기화
	SortedArray(const SortedArray& sor); //복사 생성자
	SortedArray(int p[], int size); // 생성자. 정수 배열과 크기를 전달 받음
	~SortedArray() { delete[] p;} // 소멸자
	SortedArray operator + (SortedArray& op2); // 현재 배열에 op2 배열 추가
	//SortedArray& operator = (const SortedArray& op2); // 현재 배열에 op2 배열 복사
	void show();
};
void SortedArray::sort() {
	int tmp; //이동 위해서
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size -i-1; j++) {
			if (p[j] > p[j+1]) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}                           
SortedArray::SortedArray() {
	this->size = 0;
	this->p = NULL;
}
SortedArray::SortedArray(const SortedArray& sor) {
	this->size = sor.size;
	this->p = new int[size];
	for (int i = 0; i < sor.size; i++) {
		this->p[i] = sor.p[i];
	}
}
SortedArray::SortedArray(int p[], int size) {
	this->size = size;
	this->p = new int [size];
	for (int i = 0; i < size; i++) {
		this->p[i] = p[i];
	}
	sort();
}
SortedArray SortedArray::operator + (SortedArray& op2) { //더하고 정렬
	SortedArray tmp;
	tmp.size = this->size + op2.size;
	tmp.p = new int[tmp.size];
	int ind = 0;
	for (int i = 0; i < this->size; i++) {
		tmp.p[ind++] = this->p[i];
	}
	for (int i = 0; i < op2.size; i++) {
		tmp.p[ind++] = op2.p[i];
	}
	tmp.sort();
	return tmp;
}
/*
SortedArray& SortedArray::operator = (const SortedArray& op2) { // 대입
	delete[] this->p; //기존의 것 삭제
	this->size = op2.size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) {
		this->p[i] = op2.p[i];
	}
	sort();
	return *this;
}
*/
void SortedArray::show() {
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++)
		cout << p[i] << ' ';
	cout << endl;
}
int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4);

	SortedArray c = a + b;
	// c = a + b; // +, = 작성 필요
	// + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요
	a.show();
	b.show();
	c.show();
	
}