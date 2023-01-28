#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T biggest(T arr[], int size) {
	T big = arr[0];
	for (int i = 1; i < size; i++) {
		if (big < arr[i]) big = arr[i];
	}
	return big;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	cout << biggest(x, 5) << endl;
	double y[] = { 1.1, 5.1, 10.5, 50.7, 4.0 };
	cout << biggest(y, 5) << endl;
	string z[] = { "hello","world","zoo" };
	cout << biggest(z, 3) << endl;
}