// main 

#include <iostream>
using namespace std;

// ��� ������ �ʱ�ȭ �ϼ���. -> ������ ������ ���ڿ� �����ϰ� ���� X

class Tower {
private:
	int height;
public:
	Tower();
	Tower(int height);
	int getHeight();
};

Tower::Tower() : Tower(1) {}
Tower::Tower(int a) {
	height = a;
}
int Tower::getHeight() { return height; }

int main() {
	Tower myTower; // 1meter
	Tower seoulTower(100); // 100meter
	cout << "���̴�" << myTower.getHeight() << "����" << endl;
	cout << "���̴�" << seoulTower.getHeight() << "����" << endl;

};