#include <iostream>
using namespace std;

int main() {

	int menu=0, number=0;

	cout << "***** 승리장에 오신 것을 환영합니다. *****\n";
	
	while (true) {
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4 >>";
		cin >> menu;
		if (menu >= 1 && menu <= 3) {
			cout << "몇인분?";
			cin >> number;

			switch (menu) {	 // switch문에 break는 필수이다.
			case 1: cout << "짬뽕 " << number << "인분 나왔습니다.\n"; break;
			case 2: cout << "짜장 " << number << "인분 나왔습니다.\n"; break;
			case 3: cout << "군만두 " << number << "인분 나왔습니다.\n"; break;
			}
		}
		else if (menu == 4) {
			cout << "오늘 영업은 끝났습니다.";
			break;
		}
		else cout << "다시 주문하세요!!\n";
	}
	
}