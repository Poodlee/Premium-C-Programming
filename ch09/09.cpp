#include <iostream>
#include <string>
using namespace std;

class printer {
	string model, manufacture;
	int printedCount, availableCount;
public:
	printer(string model, string manufacture, int availableCount) {
		this->model = model; this->manufacture = manufacture; this->availableCount = availableCount;
	}
	void print(int pages) { this->availableCount -= pages; }
	string getModel() { return model; }
	string getManufacture() { return manufacture; }
	int getAvailableCount() { return availableCount; }
};

class Inkjet_printer : public printer {
	int availableInk;
public:
	Inkjet_printer(string model, string manufacture, int printedCount, int availableInk) : printer(model, manufacture, printedCount)
	{
		this->availableInk = availableInk;
	}
	void printInkJet(int pages) {
		this->availableInk -= pages;
		print(pages);
	}
	void show() {
		cout << "잉크젯 : " << getModel() << " ," << getManufacture() << " ,남은 종이 "
			<< getAvailableCount() << "장 ,남은 잉크 " << availableInk << endl;
	}
	int getInk() { return availableInk; }
};

class Laser_printer : public printer {
	int availableToner;
public:
	Laser_printer(string model, string manufacture, int printedCount, int availableToner) : printer(model, manufacture, printedCount)
	{
		this->availableToner = availableToner;
	}
	void printLaser(int pages) {
		this->availableToner -= pages;
		print(pages);
	}
	void show() {
		cout << "레이저 : " << getModel() << " ," << getManufacture() << " ,남은 종이 "
			<< getAvailableCount() << "장 ,남은 토너 " << availableToner << endl;
	}
	int getToner() { return availableToner; }
};

int main() { //입력은 받지 않는다. 그저 설정되었다.
	Inkjet_printer *inkprinter = new Inkjet_printer("Officejet V40", "HP", 5, 10);
	Laser_printer *laserprinter = new Laser_printer("SCX - 6x45", "삼성전자", 3, 20);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	inkprinter->show();
	laserprinter->show();

	int printer, paper;
	char yes_no;
	while (true) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		std::cin >> printer >> paper;
		switch (printer) {
		case 1: {
			if (inkprinter->getAvailableCount() < paper || inkprinter->getInk() < paper) {
				cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
				inkprinter->show();
				laserprinter->show(); break;
			}
			else {
				cout << "프린터하였습니다." << endl;
				inkprinter->printInkJet(paper);
				inkprinter->show();
				laserprinter->show(); break;
			}
		}
		case 2: {
			if (laserprinter->getAvailableCount() < paper || laserprinter->getToner() < paper) {
				cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
				inkprinter->show();
				laserprinter->show(); break;
			}
			else {
				cout <<"프린터하였습니다."<<endl;
				laserprinter->printLaser(paper);
				inkprinter->show();
				laserprinter->show(); break;
			}
		}
		}
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		std::cin >> yes_no;
		if (yes_no == 'n') break;
		else continue;
	}
}