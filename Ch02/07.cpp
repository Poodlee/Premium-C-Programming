#include <iostream>
#include <string>
using namespace std;

int main() {

	string a;

	while (true) {
		cout << "종료하고 싶으면 yes를 입력하시오.>>";
		getline(cin, a);

		if (a == "yes") {
			cout << "같습니다." << endl;
			break;
		}
	}
}