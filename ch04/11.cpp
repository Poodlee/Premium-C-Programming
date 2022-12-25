#include <iostream>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; }
	void consume(int n) { size -= n; }
	int getSize() { return size; }
};

class coffeeVendingMachine {
	Container tong[3];	//tong[0] : 커피, tong[1] : 물, tong[2]: 설탕통
	void fill() {
		for (int i = 0; i < 3; i++) {
			tong[i].fill();
	} 
		cout << " 커피 " << tong[0].getSize() << " 물 " << tong[1].getSize() << " 설탕 " << tong[2].getSize() << endl;
	}
	void selectEspresso() {
		if (tong[0].getSize() >= 1 && tong[1].getSize() >= 1) {
			tong[0].consume(1);
			tong[1].consume(1);
			cout << "에스프레소 드세요\n";
		}
		else	cout << "원료가 부족합니다.\n";
	}
	void selectAmericano() {
		if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2) {
			tong[0].consume(1);
			tong[1].consume(2);
			cout << "아메리카노 드세요\n";
		}
		else	cout << "원료가 부족합니다.\n";
	}
	void selectSugarCoffee() {
		if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2 && tong[2].getSize() >= 1) {
			tong[0].consume(1);
			tong[1].consume(2);
			tong[2].consume(1);
			cout << "설탕커피 드세요\n";
		}
		else	cout << "원료가 부족합니다.\n";
	}
	void show() {
		cout << " 커피 " << tong[0].getSize() << " 물 " << tong[1].getSize() << " 설탕 " << tong[2].getSize() << endl;
	}
public:
	void run();
};

void coffeeVendingMachine::run() {
	
	cout << "*****  커피자판기를 작동합니다.  *****" << endl;
	while (true) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기) >> ";
		int select;
		cin >> select;
		switch (select) {
		case 1:  selectEspresso(); break;
		case 2: selectAmericano(); break;
		case 3: selectSugarCoffee(); break;
		case 4: show(); break;
		case 5: fill(); break;
		}
	}
}

int main() {
	coffeeVendingMachine DongJunMachine;
	DongJunMachine.run();

	return 0;
}