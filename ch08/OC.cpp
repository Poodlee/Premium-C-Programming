#include <iostream>
#include <string>
using namespace std;

class Product {
	int id,price;
	string explained, manufacturer;
public:
	Product() {;}
	Product(int id, string explained, string manufacturer, int price) {
		this->id = id;
		this->explained = explained; 
		this->manufacturer = manufacturer;
		this->price = price;
	}
	int getId() { return id; }
	int getPrice() { return price; }
	string getExp() { return explained; }
	string getManu() { return manufacturer; }
	virtual void show() = 0; 
	//���� show�� �� ������ ������ ���� ������ ���� �޶����Ƿ�, ���� �Լ� ����.
};

class Book : public Product {
	int ISBN;
	string writer, book_title;
public:
	Book(int id,string explained, string manufacturer, int price,
		string book_title, string writer, int ISBN)
		: Product(id,explained, manufacturer, price) {
		this->book_title = book_title;
		this->writer = writer;
		this->ISBN = ISBN;
	}
	int getISBN() { return ISBN; }
	string getWriter() { return writer; }
	string getBName() { return book_title; }
	virtual void show();
};
void Book::show() { 
	cout << "--- ��ǰID : " << getId() << endl;
	cout << "��ǰ���� : " << getExp() << endl;
	cout << "������ : " << getManu() << endl;
	cout << "���� : " << getPrice() << endl;
	cout << "ISBN : " << ISBN << endl;
	cout << "å���� : " << book_title << endl;
	cout << "���� : " << writer << endl;
}

class ConversationBook : public Book {
	string language;
public:
	ConversationBook(int id,string explained, string manufacturer, int price,
		string book_title, string writer, int ISBN, string language)
		: Book(id,explained, manufacturer, price, book_title, writer, ISBN) {
		this->language = language;
	}
	virtual void show();
};
void ConversationBook::show() {
	cout << "--- ��ǰID : " << getId() << endl;
	cout << "��ǰ���� : " << getExp() << endl;
	cout << "������ : " << getManu() << endl;
	cout << "���� : " << getPrice() << endl;
	cout << "ISBN : " << getISBN() << endl;
	cout << "å���� : " << getBName() << endl;
	cout << "���� : " << getWriter() << endl;
	cout << "��� : " << language << endl;
}

class CompactDisc : public Product {
	string album_title, singer;
public:
	CompactDisc(int id,string explained,string manufacturer, int price,
		string album_title, string singer) : Product(id,explained, manufacturer, price) {
		this->album_title = album_title; this->singer = singer;
	}
	virtual void show();
};
void CompactDisc::show() {
	cout << "--- ��ǰID : " << getId() << endl;
	cout << "��ǰ���� : " << getExp() << endl;
	cout << "������ : " << getManu() << endl;
	cout << "���� : " << getPrice() << endl;
	cout << "�ٹ����� : " << album_title << endl;
	cout << "���� : " << singer << endl;
}

int main() {
	int select,price,ISBN;
	int id = -1;
	string exp, manu, BT, writer, AT, singer, lan;

	Product* p[100]; // �� ĳ����

	cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << endl;
	while (true) {
		cout << "��ǰ �߰�(1), ��� ��ǰ ��ȸ(2), ������(3) ? ";
		cin >> select;
		switch (select) {
		case 1: 
			cout << "��ǰ ���� å(1), ����CD(2), ȸȭå(3) ? ";
			cin >> select;
			id++;
			cin.ignore(1,'\n');
			if (id >= 100) break;
			if (select == 1)  // å ����
			{
				cout << "��ǰ����>>"; getline(cin, exp);
				cout << "������>>"; getline(cin, manu);
				cout << "����>>";  cin >> price;
				cin.ignore();
				cout << "å����>>"; getline(cin, BT);
				cout << "����>>"; getline(cin, writer);
				cout << "ISBN>>"; cin >> ISBN;
				cin.ignore();
				Book* b = new Book(id, exp, manu, price, BT, writer, ISBN);
				p[id] = b; 
			}
			if (select == 2) //���� CD
			{
				cout << "��ǰ����>>"; getline(cin, exp);
				cout << "������>>"; getline(cin, manu);
				cout << "����>>"; cin >> price;
				cin.ignore();
				cout << "�ٹ�����>>"; getline(cin, AT);
				cout << "����>>"; getline(cin, singer);
				CompactDisc* cd = new CompactDisc(id, exp, manu, price, AT, singer);
				p[id] = cd;
			}
			if (select == 3) //ȸȭå
			{
				cout << "��ǰ����>>"; getline(cin, exp);
				cout << "������>>"; getline(cin, manu);
				cout << "����>>"; cin >> price;
				cin.ignore();
				cout << "å����>>"; getline(cin, BT);
				cout << "����>>"; getline(cin, writer);
				cout << "���>>"; getline(cin, lan);
				cout << "ISBN>>"; cin>>ISBN;
				cin.ignore();
				ConversationBook* cb = new ConversationBook(id, exp, manu, price, BT, writer, ISBN, lan);
				p[id] = cb;
			}
			cout << endl;
			break;

		case 2: 
			for (int i = 0; i <= id; i++) {
				p[i]->show();
			}
			cout << endl;
			break;

		case 3:
			return 0;
		}


	}
}