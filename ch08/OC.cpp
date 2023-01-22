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
	//같은 show를 다 가지고 있지만 내부 종류에 따라 달라지므로, 가상 함수 설정.
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
	cout << "--- 상품ID : " << getId() << endl;
	cout << "상품설명 : " << getExp() << endl;
	cout << "생산자 : " << getManu() << endl;
	cout << "가격 : " << getPrice() << endl;
	cout << "ISBN : " << ISBN << endl;
	cout << "책제목 : " << book_title << endl;
	cout << "저자 : " << writer << endl;
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
	cout << "--- 상품ID : " << getId() << endl;
	cout << "상품설명 : " << getExp() << endl;
	cout << "생산자 : " << getManu() << endl;
	cout << "가격 : " << getPrice() << endl;
	cout << "ISBN : " << getISBN() << endl;
	cout << "책제목 : " << getBName() << endl;
	cout << "저자 : " << getWriter() << endl;
	cout << "언어 : " << language << endl;
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
	cout << "--- 상품ID : " << getId() << endl;
	cout << "상품설명 : " << getExp() << endl;
	cout << "생산자 : " << getManu() << endl;
	cout << "가격 : " << getPrice() << endl;
	cout << "앨범제목 : " << album_title << endl;
	cout << "가수 : " << singer << endl;
}

int main() {
	int select,price,ISBN;
	int id = -1;
	string exp, manu, BT, writer, AT, singer, lan;

	Product* p[100]; // 업 캐스팅

	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
	while (true) {
		cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
		cin >> select;
		switch (select) {
		case 1: 
			cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
			cin >> select;
			id++;
			cin.ignore(1,'\n');
			if (id >= 100) break;
			if (select == 1)  // 책 선택
			{
				cout << "상품설명>>"; getline(cin, exp);
				cout << "생산자>>"; getline(cin, manu);
				cout << "가격>>";  cin >> price;
				cin.ignore();
				cout << "책제목>>"; getline(cin, BT);
				cout << "저자>>"; getline(cin, writer);
				cout << "ISBN>>"; cin >> ISBN;
				cin.ignore();
				Book* b = new Book(id, exp, manu, price, BT, writer, ISBN);
				p[id] = b; 
			}
			if (select == 2) //음악 CD
			{
				cout << "상품설명>>"; getline(cin, exp);
				cout << "생산자>>"; getline(cin, manu);
				cout << "가격>>"; cin >> price;
				cin.ignore();
				cout << "앨범제목>>"; getline(cin, AT);
				cout << "가수>>"; getline(cin, singer);
				CompactDisc* cd = new CompactDisc(id, exp, manu, price, AT, singer);
				p[id] = cd;
			}
			if (select == 3) //회화책
			{
				cout << "상품설명>>"; getline(cin, exp);
				cout << "생산자>>"; getline(cin, manu);
				cout << "가격>>"; cin >> price;
				cin.ignore();
				cout << "책제목>>"; getline(cin, BT);
				cout << "저자>>"; getline(cin, writer);
				cout << "언어>>"; getline(cin, lan);
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