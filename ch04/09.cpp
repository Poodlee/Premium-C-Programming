#include <iostream>
#include <string>
using namespace std;

class person {
	string name;
	string tel;
public:
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel) { this->name = name, this->tel = tel; }
};

int main() {
	
	person Personal[3];
	string name, tel;

	cout << "이름과 전화 번호를 입력해 주세요." << endl;
	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i << " >> ";
		cin >> name >> tel;
		Personal[i].set(name, tel);
	}
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) {
		cout << Personal[i].getName() << ' ';
	}
	cout << endl;

	cout << "전화번호 검색합니다. 이름을 입력하세요 >> ";
	cin >> name;

	int index = -1;
	for (int i = 0; i < 3; i++) {
		if (Personal[i].getName() == name) {
			index = i;
			break;
		}
	}

	if (index == -1) { cout << "존재하지 않는 이름입니다." << endl; }
	else { cout << "전화번호는" << Personal[index].getTel() << endl; }

}

