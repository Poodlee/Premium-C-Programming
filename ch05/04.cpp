#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b) { return true; }
	else if (a > b) { big = a; return false; }
	else { big = b; return false; }
}


int main() {
	int a, b, big;
	int c;
	cout << "비교할 두 수를 작성해주세요." << endl;
	cin >> a >> b;
	c = bigger(a, b, big);
	if (bigger(a, b, big)) { cout << "a와 b는 같다. 따라서 큰 값은 a=b= " << a << endl; }
	else { cout << "a와 b는 다르고 더 큰 값은 다음과 같다. " << big << endl; }
}