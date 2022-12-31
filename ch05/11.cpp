#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	char* title; //���� ���ڿ�
	int price; //����
public:
	Book(const char* title, int price);
	Book(const Book& book); // ���� ���� ������
	~Book() { delete[]title; }
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "��" << endl; }
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
	cout << "���� ������ ����." << endl;
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp;
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();

	return 0;
}