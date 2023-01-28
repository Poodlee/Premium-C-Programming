#include <iostream>
using namespace std;

template <typename T>
bool equalArrays(T n1, T n2, int size) {
	for (int i = 0; i < size; i++)
		if (n1[i] != n2[i]) return false;
	return true;
}

int main() {
	
	int x[] = { 1,10,100,5,4 };
	int y[] = { 1,10,100,5,4 };
	if (equalArrays(x, y, 5))
		cout << "같다";
	else
		cout << "다르다";
	cout << endl;

	double a[] = { 1.5, 5.0, 100, 10.0, 4.3 };
	double b[] = { 1,5, 20, 10, 4 };
	if (equalArrays(a, b, 5))
		cout << "같다";
	else
		cout << "다르다";
	cout << endl;
	return 0;
}