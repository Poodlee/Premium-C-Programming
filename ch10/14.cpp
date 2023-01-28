#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	map<string, string> manager;
	string name, password;
	int choice;

	cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****" << endl;
	while (1) {
		cout << "삽입:1, 검사:2, 종료:3 >>";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "이름과 암호>> ";
			cin >> name >> password;
			manager[name] = password; //등록
			break;
		}
		case 2: {
			cout << "이름>> ";
			cin >> name;
			while (1) {
				if (manager.find(name) == manager.end()) cout << "찾을 수 없습니다." << endl;
				else {
					cout << "암호? ";
					cin >> password;
					if (password == manager[name]) { cout << "통과!!" << endl; break; }
					else { cout << "실패~~" << endl; }
				}
			}
			break;
		}
		case 3: {
			cout << "프로그램을 종료합니다..." << endl;
			return 0;
		}
		}
	}
}