#include <iostream>
using namespace std;

int main() {
	char ch;
	int cnt = 0;

	while (1) {
		cin.get(ch);
		if (cin.eof() || ch == '\n') break;
		if (ch == ' ') cnt++;
	}
	cout << "������ ������ " << cnt << endl;
}