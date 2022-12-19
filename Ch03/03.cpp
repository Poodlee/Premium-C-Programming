// main 

#include <iostream>
#include <string>
using namespace std;


class Account {
public:
	string name;
	int id, balance;
	Account(string name, int id, int balance);
	int withdraw(int money);
	int inquiry();
	void deposit(int money);
	string getOwner();
};

Account::Account(string name, int id, int balance) {
	this -> name = name;
	this -> id = id;
	this -> balance = balance;
}
int Account::withdraw(int money) {
	balance = balance - money;
	return balance;
}
int Account::inquiry() { return balance; }
void Account::deposit(int money) {
	balance = balance + money;
}
string Account::getOwner() { return name; }


int main() {
	Account a("Kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº" << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº" << a.inquiry() << endl;
};