#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) { this->size = size; scores = new int[size]; }
	Dept(const Dept& dept); //복사 생성자
	~Dept() { delete[]scores; }
	int getSize() { return size; }
	void read(); // size만큼 키보드에서 정수를 읽어 scores 배열에 저장
	bool isOver60(int index); // index 학생의 성적이 60보다 크면 true 리턴
};
Dept::Dept(const Dept& dept) {
	this->size = dept.size;
	this->scores = new int[dept.size];
	for (int i = 0; i < dept.size; i++) {
		this->scores[i] = dept.scores[i];
	}
}
void Dept::read() {
	cout << "10개 점수 입력>>";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}
bool Dept::isOver60(int index) {
	if (scores[index] >= 60) return true;
	else return false;
}
int countPass(Dept dept) { // dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명" << endl;
}

//12-2 복사 생성자가 어느 부분에서 호출되는 가? countPass가 실행되는 구간에서 복사가 일어난다. 
//12-2 복사 생성자가 없으면 왜 실행 오류? count Pass가 종료되면서 소멸자 이미 실행된다.
