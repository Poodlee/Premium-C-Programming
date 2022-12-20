#include <iostream>
#include <random>
using namespace std;

class Random {
public:
	int next();
	int nextInRange(int min, int max);
};

int Random::next() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 32237);
	return dis(gen);
}
int Random::nextInRange(int min, int max) {
	// ���� ���� rand�� �������� min�� max ���̷� ������ ����� ����ϴ�.
	// ��ġ Min-Max Data Wrangling ó�� -> ������ + �ּڰ�
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}

int main() {
	Random r;
	cout << "--0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "--2���� " << "4 �����Ƿ��� ���� 10�� -- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}