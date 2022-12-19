#include <iostream>
#include <cstdlib>	// rand()
#include <ctime>	//srand()
using namespace std;

class EvenRandom {
public:
	int next();
	int nextInRange(int min, int max);
};

int EvenRandom::next() {
	srand((unsigned)time(NULL)); // -> 출력 동일 왜?
	int n;
	do {
		n = rand();
	} while (n % 2 == 1);
	return n;

}
int EvenRandom::nextInRange(int min, int max) {
	
	srand((unsigned)time(0));
	int n;
	do {
		n = rand();
	} while (n % 2 == 1);
	n = n % (max - min + 1) + min;
	return n;
}

int main() {
	EvenRandom r;
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "--2에서 " << "4 까지의랜덤 정수 10개 -- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}