#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	char* title; //제목 문자열
	int price; //가격
public:
	Book(const char* title, int price);
	Book(const Book& book); // 깊은 복사 생성자
	~Book() { delete[]title; }
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};
Book::Book(const char* title, int price) {
	int len = strlen(title);
	this->title = new char[len + 1];
	this->price = price;
	strcpy(this->title, title);
}
void Book::set(const char* title, int price) {
	
	strcpy(this->title, title);
	this->price = price;
}
Book::Book(const Book& book) {
	this->price = book.price;
	int len = strlen(book.title);
	this->title = new char[len + 1];
	strcpy(this->title, book.title);
	cout << "복사 생성자 실행." << endl;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();

	return 0;
}