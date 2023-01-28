#include <iostream>
using namespace std;

template <typename T>
T* concat(T arr[], int sizea, T arr2[], int sizeb) {
	int size = sizea + sizeb;
	T* c = new T(size);
	for (int i = 0; i < sizea; i++) c[i] = arr[i];
	for (int i = sizea; i < size; i++) c[i] = arr2[i-sizea];

	return c;
}

int main() {
	int x[] = { 1,3,5,6,7 };
	int y[] = { 2,4,5,5,6,9 };

	int* p = concat(x, 5, y, 6);
	for (int i = 0; i < 11; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
}