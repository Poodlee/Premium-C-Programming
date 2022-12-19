// main 

#include <iostream>
using namespace std;

// 멤버 변수를 초기화 하세요. -> 생성자 생성시 인자와 동일하게 설정 X

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
	cout << "높이는" << myTower.getHeight() << "미터" << endl;
	cout << "높이는" << seoulTower.getHeight() << "미터" << endl;

};