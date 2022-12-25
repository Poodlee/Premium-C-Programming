//VendingMachine.cpp

#include <iostream>
#include "VendingMachine.h"

void VendingMachine::inputMoney(int money) {
	balance += money;
	std::cout << money << "원이 입금되어 현재 잔액은 " << balance << " 입니다. \n";

}
void VendingMachine::remainMoney() {
	std::cout << "잔액은 " << balance << "입니다. \n";
}
void VendingMachine::buyPepsi(int cnt) { 
	if (balance >= 1000 * cnt) {
		if (pepsi == 0)
			std::cout << "띠링 !! 품절입니다. \n";
		else if (pepsi > 0 && pepsi < cnt)
			std::cout << "구매하려는 개수보다 재고의 개수가 더 적습니다. \n" << std::endl;
		else
			balance -= 1000*cnt;
			pepsi -= cnt;
			std::cout << "코카콜라 " << cnt << "개 맛있게 드세요!\n";
	}
	else { std::cout << "띠링!잔액 부족입니다! \n"; }
}
void VendingMachine::buySprite(int cnt) {
	if (balance >= 1000 * cnt) {
		if (sprite == 0) {
			std::cout << "띠링 !! 품절입니다. \n";
		}
		else if (sprite > 0 && sprite < cnt) {
			std::cout << "구매하려는 개수보다 재고의 개수가 더 적습니다. \n" << std::endl;
		}
		else {
			balance -= 1000 * cnt;
			sprite -= cnt;
			std::cout << "사이다 " << cnt << "개 맛있게 드세요!\n";
		}
	}
	else { std::cout << "띠링! 잔액 부족입니다! \n"; }
}
void VendingMachine::returnBalance() {
	if (balance > 0) {
		std::cout << balance << "원 잔액으로 남아 돌려 드립니다.\n 안녕히 가세요!!\n";
		balance = 0;
	}
	else {
		std::cout << "남은 잔액이 없네요 ㅠㅠ";

	}
}
void VendingMachine::checkproduct() {
	std::cout << "현재 남아 있는 펩시는 " << pepsi << "개 이고 남아 있는 스프라이트는 " << sprite << "개 입니다." << std::endl;
}
bool VendingMachine::kill() {
	if (pepsi == 0 && sprite == 0) {
		int select;
		std::cout << "자판기의 모든 제품이 품절 됐습니다.\n 재입고 하시겠습니까?? 재입고:1 종료:2\n";
		std::cin >> select;
		switch (select) {
		case 1: {std::cout << "재고를 입고했습니다. 다시 펩시와 사이다 재고는 10개 입니다.\n";
			pepsi = 10; sprite = 10; return 1; }
		case 2: std::cout << "장비를 정지합니다."; return 0;
		}
	}
	else {
		return 1;
	}
}