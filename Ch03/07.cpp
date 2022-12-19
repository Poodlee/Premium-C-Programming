#include <iostream>
#include <cstdlib>	// rand()
#include <ctime>	//srand()
using namespace std;

class Random {
public:
	int next();
	int nextInRange(int min, int max);
	int select;
};

int Random::next() {
	if (select == 0) {
		srand((unsigned)time(NULL)); // -> ��� ���� ��?
		int n;
		do {
			n = rand();
		} while (n % 2 == 1);
		return n;
	}
	else if (select == 1) {
		srand((unsigned)time(NULL)); // -> ��� ���� ��?
		int n;
		do {
			n = rand();
		} while (n % 2 == 0);
		return n;
	}
	else { cout << "�߸��� �Ϸ��Դϴ�." << endl; }

}
int Random::nextInRange(int min, int max) {
	if (select == 0) {
		srand((unsigned)time(0));
		int n;
		do {
			n = rand();
		} while (n % 2 == 1);
		n = n % (max - min + 1) + min;
		return n;
	}
	else if (select == 1) {
		srand((unsigned)time(0));
		int n;
		do {
			n = rand();
		} while (n % 2 == 0);
		n = n % (max - min + 1) + min;
		return n;
	}
	else { cout << "�߸��� �Ϸ��Դϴ�." << endl; }
	
}

int main() {
	Random r;
	cout << "Ȧ���� 1 ¦���� 0���� �Է����ּ���.";
	int select;
	cin >> select;
	r.select = select;

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