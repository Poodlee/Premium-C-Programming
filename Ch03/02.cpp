// main 

#include <iostream>
#include <string>
using namespace std;


class Date {
public:
	Date(int a, int b,int c);
	Date(string Data);
	void show();
	int year; int month; int day;
	int getYear(); int getMonth(); int getDay();
};

Date::Date(int a, int b, int c) {
	year = a;
	month = b;
	day = c;
}

// stoi �� ���ڳ� ���� �ܿ� ������ �����.
// find �� �ε����� Ȯ���ϴ� ��ɾ��̴�.
Date::Date(string Data) {
	int index;

	year = stoi(Data);
	index = Data.find('/');
	month = stoi(Data.substr(index + 1)); // ������ �� �����.
	index = Data.find('/', index + 1);
	day = stoi(Data.substr(index + 1));
}
void Date::show() {
	cout << year << "��" << month << "��" << day << "��" << endl;
}
int Date::getYear() { return year; }
int Date::getMonth() { return month; }
int Date::getDay() { return day; }


int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;

};