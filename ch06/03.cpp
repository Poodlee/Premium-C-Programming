#include <iostream>
using namespace std;

/* 3-(1)
int big(int a, int b) {
	int big = 0;
	if (a > b) big = a;
	else big = b;
	if (big > 100) { big = 100; }
	return big;
}
int big(int a, int b, int limit) {
	int big = 0;
	if (a > b) big = a;
	else big = b;
	if (big > limit) { big = limit; }
	return big;
}
*/
int big(int a, int b, int limit = 100) {
	int big = 0;
	if (a > b) big = a;
	else big = b;
	if (big > limit) { big = limit; }
	return big;
}
int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
 }