#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size = 0) { this->size = size; scores = new int[size]; }
	Dept(const Dept& dept); //���� ������
	~Dept() { delete[]scores; }
	int getSize() { return size; }
	void read(); // size��ŭ Ű���忡�� ������ �о� scores �迭�� ����
	bool isOver60(int index); // index �л��� ������ 60���� ũ�� true ����
};
Dept::Dept(const Dept& dept) {
	this->size = dept.size;
	this->scores = new int[dept.size];
	for (int i = 0; i < dept.size; i++) {
		this->scores[i] = dept.scores[i];
	}
}
void Dept::read() {
	cout << "10�� ���� �Է�>>";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}
bool Dept::isOver60(int index) {
	if (scores[index] >= 60) return true;
	else return false;
}
int countPass(Dept dept) { // dept �а��� 60�� �̻����� ����ϴ� �л��� �� ����
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10), test();
	com.read();
	test = com;
	int n = countPass(com);
	cout << "60�� �̻��� " << n << "��" << endl;
}

//12-2 ���� �����ڰ� ��� �κп��� ȣ��Ǵ� ��? countPass�� ����Ǵ� �������� ���簡 �Ͼ��. 
//12-2 ���� �����ڰ� ������ �� ���� ����? count Pass�� ����Ǹ鼭 �Ҹ��� �̹� ����ȴ�.