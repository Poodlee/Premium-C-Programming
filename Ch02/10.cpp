#include <iostream>
#include <string>
using namespace std;

int main() {

	string munja;

	cout << "문자열 입력 >>\n";
	getline(cin, munja);

	for (int i = 0; i <= munja.length()-1; i++) {
		for (int j = 0; j <= i; j++) {
			cout << munja[j];
		}
		cout << endl;
	}
}