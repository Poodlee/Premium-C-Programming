// VendingMachine_main.cpp

#include <iostream>
#include "VendingMachine.h"

int main() {
	VendingMachine DongJunMachine;

	while (true) {	//무한 루프
		int selection, insertCoin, product, end;
		std::cout << "무엇을 도와드릴까요? " << std::endl;
		std::cout << "1. 돈 넣기 " << "2. 상품 선택 " << "3. 잔돈 받기" << " 4. 잔액 확인" << std::endl;
		std::cin >> selection;
		switch (selection) {
			case 1: std::cout << "얼마를 입금하시겠습니까? " << std::endl;
					std::cin >> insertCoin;
					DongJunMachine.inputMoney(insertCoin); break;
			case 2:
					std::cout << "어떤 상품을 선택 하시겠습니까?? 0. 제고 확인 1. 펩시(1000원) 2. 스프라이트(1000원)" << std::endl;
					std::cin >> product;
					switch (product) {
					case 0: DongJunMachine.checkproduct(); break;
					case 1: std::cout << "개수를 선택해주세요.\n" << std::endl;
							int num_pepsi;
							std::cin >> num_pepsi;
							DongJunMachine.buyPepsi(num_pepsi); break;
					case 2: std::cout << "개수를 선택해주세요.\n" << std::endl;
							int num_sprite;
							std::cin >> num_sprite;
							DongJunMachine.buySprite(num_sprite); break;
					} break;
			case 3: DongJunMachine.returnBalance(); break;
			case 4: DongJunMachine.remainMoney(); break;
			}
		end = DongJunMachine.kill();
		if (end == 0) break;
		std::cout << "\n\n" << std::endl;
	}
};