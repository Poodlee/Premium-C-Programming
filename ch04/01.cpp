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
	Color screenColor(255, 0, 0);	// �������� screenColor ��ü ����
	Color* p;			// Color Ÿ���� ������ ���� p ����
	p = &screenColor;	//(1) p�� screenColor �ּ� ������(�迭�� �ƴϴ�.)
	p->show();			//(2) p�� ����Ű�� Ŭ���� ��� �Լ� ����
	Color colors[3];	//(3) �迭 ����
	p = colors;			//(4) �̹����� �迭�̹Ƿ� �̸��� ��� �ּҰ� 

	p->setColor(255, 0, 0);		//(5) �迭�� 1 2 ���ϸ� ���� �ּҰ�
	(p + 1)->setColor(0, 255, 0);
	(p + 2)->setColor(0, 0, 255);

	for (int i = 0; i < 3; i++)			//(6) �� Ŭ������ ��� �Լ� �̿�
		(p + i)->show();
}