#include <iostream>
using namespace std;

class MyIntStack { //Stack Ŭ����
	int p[10];  // �ִ� 10���� ���� ����
	int tos;  // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack() { tos = -1; }
	bool push(int n); //���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
	bool pop(int& n); // ���Ͽ� n�� ����, ������ ��� ������ false, �ƴϸ� true ����

};
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

class ArrayUtility2 {
public:
	//s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
	static int* concat(int s1[], int s2[], int size);

	//s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����
	//�����ϴ� �迭�� ũ��� retSize�� ����. retSize�� 0�� ��� NULL ����
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* sumArray = new int[size * 2];
	for (int i = 0; i < size; i++) {
		sumArray[i] = s1[i];
	}
	for (int i = 0; i < size; i++) {
		sumArray[i + size] = s2[i];
	}
	return sumArray;
}
int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) s1[i] = NULL;
		}
	}
	for (int i = 0; i < size; i++) {
		if (s1[i] != NULL) retSize++;
	}
	if (retSize == 0) return NULL;
	int* p = new int[retSize];
	// ���� �������� ���� �κ� ã�� + �迭���� ���� �߰� �ȵǴϱ�
	// stack �̿��ؼ� push�ϰ� �ش� ���� �� ���Ӱ� p�� �Ҵ� ���ָ� �ǰ���?
	MyIntStack stack;
	int *p_inverse = new int[retSize];
	for (int i = 0; i < size; i++) {
		if (s1[i] != NULL) stack.push(s1[i]);
	}
	for (int i = 0; i < retSize; i++) {
		stack.pop(p_inverse[i]);
	}
	for (int i = 0; i < retSize; i++) {
		p[i] = p_inverse[retSize - i];
	}
	return p;
}

int main() {
	int x[5], y[5], retSize = 0, size;

	cout << "������ 5 �� �Է��϶�. �迭 x�� �����Ѵ�>>";
	cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
	cout << "������ 5 �� �Է��϶�. �迭 y�� �����Ѵ�>>";
	cin >> y[0] >> y[1] >> y[2] >> y[3] >> y[4];
	cout << "��ģ ���� �迭�� ����Ѵ�." << endl;

	size = 10; // x�� y ���� ��
	int* temp = ArrayUtility2::concat(x, y, size);
	for (int i = 0; i < size; i++) cout << temp[i] << ' ';
	cout << endl;
	
	size = 5; // x������ ����
	int* temp2 = ArrayUtility2::remove(x, y, size, retSize); // ���� ������ �����ؼ� �̷��� �����ص� ���
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << retSize << endl;
	for (int i = 0; i < retSize; i++) cout << temp[i] << ' ';
	cout << endl;
}