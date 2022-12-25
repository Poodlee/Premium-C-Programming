#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int main() {
	Color screenColor(255, 0, 0);	// 빨간색의 screenColor 객체 생성
	Color* p;			// Color 타입의 포인터 변수 p 선언
	p = &screenColor;	//(1) p가 screenColor 주소 갖도록(배열이 아니다.)
	p->show();			//(2) p가 가리키는 클래스 멤버 함수 실행
	Color colors[3];	//(3) 배열 선언
	p = colors;			//(4) 이번에는 배열이므로 이름만 적어도 주소값 

	p->setColor(255, 0, 0);		//(5) 배열에 1 2 더하면 다음 주소값
	(p + 1)->setColor(0, 255, 0);
	(p + 2)->setColor(0, 0, 255);

	for (int i = 0; i < 3; i++)			//(6) 각 클래스의 멤버 함수 이용
		(p + i)->show();
}