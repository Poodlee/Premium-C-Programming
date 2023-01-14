#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = " ", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	
	/* 2-1
	bool operator ==(int price) {
		if (this->price == price) return true;
		else return false;
	}
	bool operator ==(string title) {
		if (this->title.compare(title) == 0) return true;
		else return false;
	}
	bool operator ==(Book& book) {
		if (this->title.compare(book.title) == 0
			&& this->price == book.price
			&& this->pages == book.pages) return true;
		else return false;
	}
	*/
	friend bool operator == (Book a, int price);
	friend bool operator == (Book a, string title);
	friend bool operator == (Book a, Book b);
};
// 2-2
bool operator == (Book a, int price) {
	if (a.price == price) return true;
	else return false;
}
bool operator == (Book a, string title) {
	if (a.title.compare(title) == 0) return true;
	return false;
}
bool operator == (Book a, Book b) {
	if (a.title.compare(b.title) == 0
		&& a.price == b.price
		&& a.pages == b.pages) return true;
	else return false;
}

int main() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) { cout << " 정가 30000원" << endl; }
	if (a == "명품 C++") { cout << "명품 C++ 입니다." << endl; }
	if (a == b) { cout << "두 책은 같은 책입니다." << endl; }
}