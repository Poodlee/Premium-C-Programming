#include <iostream>
#include <string>
using namespace std;

// 조건: int 배열을 동적 할당, 연산자 함수(!,>>,<<,~)
class Statistics {
private:
	int size;
	int* stat;
public:
	Statistics(int size = 0) { this->size = size; this->stat = new int[size]; }
	bool operator !() {
		if (size == 0) return true;
		else return false;
	}
	void operator >> (int& avg) {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += stat[i];
		avg = sum / size;
	}
	void operator ~() {
		for (int i = 0; i < size; i++) {
			cout << stat[i] << ' ';
		}
		cout << endl;
	}
	Statistics& operator <<(int x) {
		size++;
		Statistics tmp(size);
		for (int i = 0; i < size - 1; i++)
			tmp.stat[i] = stat[i];
		tmp.stat[size-1] = x;

		delete[] this->stat;
		this->stat = new int[size];
		for (int i = 0; i < size; i++)
			this->stat[i] = tmp.stat[i];
		return *this;
	}
};

int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;

	int x[5];
	cout << "5개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) cin >> x[i]; //x[i] 정수 입력

	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] 값을 통계 객체에 삽입한다.
	stat << 100 << 200; //100,200을 통계 객체에 삽입한다.
	~stat; //통계 데이터를 모두 출력한다.

	int avg;
	stat >> avg; //통계 객체로부터 평균을 받는다.
	cout << "avg =" << avg << endl;
}