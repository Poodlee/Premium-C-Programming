#include <iostream>
using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) {
		size = n; p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	for (int i = 0; i < size; i++) {
		cin >> p[i];
	}
}

void Sample::write() {
	for (int i = 0; i < size; i++) {
		std::cout << p[i] << ' ';
	}
	std::cout << endl;
}

int Sample::big() {
	int big = p[0];
	for (int i = 1; i < size; i++) {
		if (big < p[i])
			big = p[i];
	}
	return big;
}

Sample::~Sample() {
	delete[] p;
}

int main(void) {
	Sample s(10);
	s.read();
	s.write();
	std::cout << "가장 큰 수는 " << s.big() << endl;

	int* p = new int [] {1, 2, 3, 4 };
	std::cout << *(p+2);
}