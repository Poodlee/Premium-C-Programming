#include <iostream>
#include <string>
using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; }
	void print() { cout << text << endl; }

};
Buffer& append(Buffer& buf, string text) {  // 새로운 함수 지정.
	buf.add(text);
	return buf;
}

int main() {
	Buffer buf( "Hello" );
	Buffer& temp = append(buf, "Guys");
	temp.print();
	buf.print();
}