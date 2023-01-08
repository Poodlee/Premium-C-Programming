#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	//s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
	static int* concat(int s1[], int s2[], int size);

	//s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����
	//�����ϴ� �迭�� ũ��� retSize�� ����. retSize�� 0�� ��� NULL ����
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* sumArray = new int[size];
	for (int i = 0; i < size/2; i++) {
		sumArray[i] = s1[i];
		sumArray[i + size/2] = s2[i];
	}
	return sumArray;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int* tmp = new int[size];
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) { s1[i] = NULL; break; }
			if (j == size - 1) tmp[cnt++] = s1[i]; // �׳� ��ü������ i ���󰡴ϱ� ������� �Ѵ�. �׷��� ���ο� ���� �߰�
		}
	}
	if (cnt == 0) return NULL;
	retSize = cnt;
	int* ret = new int[retSize];
	
	// ������ ����� �� �� �־���... �׷��� ��� �߸��� ����.
	for (int i = 0; i < retSize; i++) {
		ret[i] = tmp[i];
	}

	std::cout << "\n �߰� �׽�Ʈ �Դϴ�.\n";
	for (int i = 0; i < size; i++) std::cout << s1[i] << ' ';
	std::cout << endl;
	for (int i = 0; i < retSize; i++) std::cout << tmp[i] << ' ';
	std::cout << endl << endl;

	return ret;
}

int main() {
	int x[5], y[5], retSize = 0, size;

	std::cout << "������ 5 �� �Է��϶�. �迭 x�� �����Ѵ�>>";
	cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
	std::cout << "������ 5 �� �Է��϶�. �迭 y�� �����Ѵ�>>";
	cin >> y[0] >> y[1] >> y[2] >> y[3] >> y[4];
	std::cout << "��ģ ���� �迭�� ����Ѵ�." << endl;

	size = 10; // x�� y ���� ��
	int* temp = ArrayUtility2::concat(x, y, size);
	for (int i = 0; i < size; i++) std::cout << temp[i] << ' ';
	std::cout << endl;

	size = 5; // x������ ����
	int* temp2 = ArrayUtility2::remove(x, y, size, retSize); // ���� ������ �����ؼ� �̷��� �����ص� ���
	std::cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << retSize << endl;
	for (int i = 0; i < retSize; i++) std::cout << temp2[i] << ' ';
	std::cout << endl;
}