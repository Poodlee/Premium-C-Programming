#include <iostream>
using namespace std;

template <typename T>
void reverseArray(T* arr, int size) {
	T tmp;
	for (int i = 0; i < size / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
	}
}

int main() {

	int x[] = { 1,10,100,5,4 };
	for (int i = 0; i < 5; i++)
		cout << x[i] << ' ';
	cout << endl;
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++)
		cout << x[i] << ' ';

	return 0;
}