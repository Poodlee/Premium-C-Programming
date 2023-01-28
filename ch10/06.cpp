#include <iostream>
using namespace std;

template <typename T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	int size = sizeSrc + sizeMinus;
	int cnt = 0;
	T* tmp = new T[size];
	for (int i = 0; i < sizeSrc; i++) {
		for (int j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) { src[i] = NULL; break; }
			if (j == sizeMinus - 1) { tmp[cnt++] = src[i]; }
		}
	}
	retSize = cnt;
	int* ret = new int[retSize];
	for (int i = 0; i < retSize; i++) { ret[i] = tmp[i]; }
	return ret;
}

int main() {
	int arr1[] = { 1,2,3,4,5,6 };
	int arr2[] = { 3,6,1 };
	int size = 0;
	int* ptr;
	ptr = remove(arr1, 6, arr2, 3, size);
	for (int i = 0; i < size; i++)
		cout << ptr[i] << ' ';
}