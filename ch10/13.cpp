#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> manager;
	string name;
	int choice,score;
	
	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다 *****" << endl;
	while (1) {
		cout << "입력:1, 조회:2, 종료:3 >>";
		cin >> choice;
		switch(choice) {
		case 1: {
			cout << "이름과 점수>> ";
			cin >> name >> score;
			manager[name] = score; //등록
			break;
		}
		case 2: {
			cout << "이름>> ";
			cin >> name;
			if (manager.find(name) == manager.end()) cout << "찾을 수 없습니다." << endl;
			else cout << name << "의 점수는 " << manager[name] << endl;
			break;
		}
		case 3: {
			cout << "프로그램을 종료합니다..." << endl;
			return 0;
		}
		}
	}
}