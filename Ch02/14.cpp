#include <iostream>
#include <cstring>

using namespace std;

int main() {

	string menu;
	int total_income =0, number = 0;

	cout << "에스프레소 2000원,  아메리카노 2300원,  카푸치노 2500원입니다.\n";

	while (true) {
		if (total_income <= 20000) {
			cout << "주문 >>";
			cin >> menu >> number;
			if (menu == "에스프레소") {
				cout << number * 2000 << "원입니다. 맛있게 드세요.\n";
				total_income += number * 2000;
			}
			if (menu == "아메리카노") {
				cout << number * 2300 << "원입니다. 맛있게 드세요. \n";
				total_income += number * 2300;
			}
			if (menu == "카푸치노") {
				cout << number * 2500 << "원입니다. 맛있게 드세요. \n";
				total_income += number * 2500;
			}
		}
		else {
			cout << "오늘 " << total_income << "원을 판매하여 카페를 닫습니다.  내일 봐요~~~";
			break;
		}
	}

}
