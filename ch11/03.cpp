#include <iostream>
using namespace std;

int main() {
	int ch;
	while ((ch = cin.get()) != EOF) {
		cout.put(ch);
		if (ch == '\n')
			cin.ignore(100, ';');
	}
	cout << endl;
}