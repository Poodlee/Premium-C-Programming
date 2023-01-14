#include <iostream>
#include <string>
using namespace std;

class Color {
	int red;
	int green;
	int blue;
public:
	Color() { red = 0; green = 0; blue = 0; }
	Color(int r, int g, int b) {
		this->red = r; this->green = g; this->blue = b;
	}
	void show() {
		cout << red << ' ' << green << ' ' << blue << endl;
	}
	//5-1
	/*
	Color operator +(Color c) {
		Color tmp;
		tmp.red = this->red + c.red;
		tmp.green = this->green + c.green;
		tmp.blue = this->blue + c.blue;
		return tmp;
	}
	bool operator ==(Color c) {
		if (this->red == c.red && this->green == c.green && this->blue == c.blue) return true;
		else return false;
	}
	*/
	friend Color operator +(Color c1, Color c2);
	friend bool operator == (Color c1, Color c2);
};
// 5-2
Color operator+(Color c1, Color c2) {
	Color tmp;
	tmp.red = c1.red + c2.red;
	tmp.green = c1.green + c2.green;
	tmp.blue = c1.blue + c2.blue;
	return tmp;
}
bool operator == (Color c1, Color c2) {
	if (c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue) return true;
	else return false;
}

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show(); // 색 값 출력

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}