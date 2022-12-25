//VendingMachine.h

#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H 2

#define PEPSI_STOCK 10
#define SPRITE_STOCK 10

class VendingMachine {
private:
	int balance=0, pepsi = PEPSI_STOCK, sprite = SPRITE_STOCK;
public:
	void inputMoney(int money);
	void remainMoney();
	void buyPepsi(int cnt);
	void buySprite(int cnt);
	void returnBalance();
	void checkproduct();
	bool kill();
};

#endif

