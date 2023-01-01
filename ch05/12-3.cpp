//12-3 ���� ������ ���� ��, ����. -> ���� ���̸� ��... ��¥ ���簡 �ƴ϶� ���� üũ�ϴ� �Ŷ�.

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
	void read(); // size��ŭ Ű���忡�� ������ �о� scores �迭�� ����
	bool isOver60(int index); // index �л��� ������ 60���� ũ�� true ����
};
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
int countPass(Dept &dept) { // dept �а��� 60�� �̻����� ����ϴ� �л��� �� ����
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
	cout << "60�� �̻��� " << n << "��" << endl;
}