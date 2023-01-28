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
		cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� �԰� �����մϴ�." << endl;
		while (1) {
			cout << "�⵵>>";
			cin >> year;
			if (year == -1) {
				cout << "�� �԰�� å�� " << v.size() << "���Դϴ�." << endl;
				break;
			}
			cin.ignore();
			cout << "å�̸�>>";
			getline(cin,bookName);
			cout << "����>>";
			getline(cin, author);
			v.push_back(Book(year, bookName, author));
		}
	}
	void search() {
		string author_search;
		int year_search,choice;
		while (1) {
			cout << "�˻��ϰ��� �ϴ� �ɼ��� �������ּ���. " << endl;
			cout << "1. ���� �̸�, 2.�⵵ 3. ������";
			cin >> choice;
			cin.ignore();
			switch (choice) {
			case 1: {
				cout << "�˻��ϰ��� �ϴ� ������ �̸��� �Է��ϼ���>>";
				getline(cin, author_search);
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i].getAuthor() == author_search) {
						cout << v[i].getYear() << "�⵵, " << v[i].getBookName() << ", " << v[i].getAuthor() << endl;
					}
				}
				break;
			}
			case 2: {
				cout << "�˻��ϰ��� �ϴ� �⵵�� �Է��ϼ���>>";
				cin >> year_search;
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i].getYear() == year_search) {
						cout << v[i].getYear() << "�⵵, " << v[i].getBookName() << ", " << v[i].getAuthor() << endl;
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