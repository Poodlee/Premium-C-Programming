#include <iostream>
#include <cstdlib>	// rand()
#include <ctime>	//srand()
using namespace std;

class Random {
public:
	int next();
	int nextInRange(int min, int max);
};

int Random::next() {
	srand((unsigned)time(NULL)); // -> ��� ���� ��?
	int n = rand();
	return n;
}
int Random::nextInRange(int min, int max) {
	// ���� ���� rand�� �������� min�� max ���̷� ������ ����� ����ϴ�.
	// ��ġ Min-Max Data Wrangling ó�� -> ������ + �ּڰ�
	srand((unsigned)time(0));
	int n = rand();
	n = n%(max-min+1) + min;
	return n;
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