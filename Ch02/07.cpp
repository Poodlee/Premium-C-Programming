#include <iostream>
#include <string>
using namespace std;

int main() {

	string a;

	while (true) {
		cout << "�����ϰ� ������ yes�� �Է��Ͻÿ�.>>";
		getline(cin, a);

		if (a == "yes") {
			cout << "�����ϴ�." << endl;
			break;
		}
	}
}