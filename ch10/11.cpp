#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;

class Book {
	int year;
	string bookName, author;
public:
	Book(int year, string bookName, string author) {
		this->year = year; this->bookName = bookName; this->author = author;
	}
	int getYear() { return year; }
	string getBookName() { return bookName; }
	string getAuthor() { return author; }
};

class Bookstore {
	vector<Book> v;
	void stock() {
		int year;
		string bookName, author;
		cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
		while (1) {
			cout << "년도>>";
			cin >> year;
			if (year == -1) {
				cout << "총 입고된 책은 " << v.size() << "권입니다." << endl;
				break;
			}
			cin.ignore();
			cout << "책이름>>";
			getline(cin,bookName);
			cout << "저자>>";
			getline(cin, author);
			v.push_back(Book(year, bookName, author));
		}
	}
	void search() {
		string author_search;
		int year_search,choice;
		while (1) {
			cout << "검색하고자 하는 옵션을 선택해주세요. " << endl;
			cout << "1. 저자 이름, 2.년도 3. 끝내기";
			cin >> choice;
			cin.ignore();
			switch (choice) {
			case 1: {
				cout << "검색하고자 하는 저자의 이름을 입력하세요>>";
				getline(cin, author_search);
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i].getAuthor() == author_search) {
						cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getAuthor() << endl;
					}
				}
				break;
			}
			case 2: {
				cout << "검색하고자 하는 년도를 입력하세요>>";
				cin >> year_search;
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i].getYear() == year_search) {
						cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getAuthor() << endl;
					}
				}
				break;
			}
			case 3: {return; }
			}
		}
	}
public:
	void enter() {
		stock();
		search();
	}
};

int main() {
	Bookstore DJbookstore;
	DJbookstore.enter();
}