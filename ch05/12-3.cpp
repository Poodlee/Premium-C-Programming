//12-3 복사 생성자 제거 후, 수정. -> 참조 붙이면 끝... 진짜 복사가 아니라 값만 체크하는 거라서.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) { this->size = size; scores = new int[size]; }
	~Dept() { delete[]scores; }
	int getSize() { return size; }
	void read(); // size만큼 키보드에서 정수를 읽어 scores 배열에 저장
	bool isOver60(int index); // index 학생의 성적이 60보다 크면 true 리턴
};
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
int countPass(Dept &dept) { // dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
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
