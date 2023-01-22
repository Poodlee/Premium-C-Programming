#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class GameObject { // �߻� Ŭ����
protected:
	int distance; // �� �� �̵��Ÿ�
	int x, y; // ���� ��ġ
public:
	GameObject(int startX, int startY, int distance) {  // �ʱ� ��ġ�� �̵��Ÿ� ����
		x = startX; y = startY; this->distance = distance;

	}
	virtual ~GameObject() {}; // ���� �Ҹ���
	virtual void move() = 0; // �̵��� �� ���ο� ��ġ�� x, y ����
	virtual char getShape() = 0; // ��ü�� ����� ��Ÿ���� ���� ���� 
				//	(Human : 'H', Monster: 'M', Food: '@')
	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject* p) { // �� ��ü�� ��ü p�� �浹������ true ����
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else return false;
	}
	void check() {
		if (19 < x)
			x = 19;
		if (0 > x)
			x = 0;
		if (9 < y)
			y = 9;
		if (0 > y)
			y = 0;
	}

};
// Ű�� �Էµ� ������ Human, Monster, Food ��ü�� move()������� ȣ��.
class Human : public GameObject {
public:
	Human(int startX, int startY, int distance) : GameObject(startX,startY,distance){}
	void move() {
		char moving;
		cin >> moving;
		switch (moving) {
		case 'a': {
			y -= distance;
			check();
			break;
		}
		case 's': {
			x += distance;
			check();
			break;
		}
		case 'd': {
			x -= distance;
			check();
			break;
		}
		case 'f': {
			y += distance;
			check();
			break;
		}
		}
	}
	char getShape() { return 'H'; }
};
class Monster : public GameObject {
public:
	Monster(int startX, int startY, int distance) : GameObject(startX,startY,distance) {}
	void move() {
		srand((unsigned int)time(NULL));
		int random = rand() % 4;
		switch (random) {
		case 0: {
			x -= distance;
			check();
			break;
		}
		case 1: {
			y -= distance;
			check();
			break;
		}
		case 2: {
			y += distance;
			check();
			break;
		}
		case 3: {
			x += distance;
			check();
			break;
		}
		}
	}
	char getShape() { return 'M'; }
};
class Food : public GameObject {
public:
	int cnt = 0;
	Food(int startX, int startY, int distance) : GameObject(startX, startY, distance) {}
	void move() {
		srand((unsigned int)time(NULL));
		int random = rand() % 4;
		if (cnt < 2) {
			switch (random) {
			case 0: {
				x -= distance;
				cnt++;
				check();
				break;
			}
			case 1: {
				y -= distance;
				cnt++;
				check();
				break;
			}
			case 2: {
				y += distance;
				cnt++;
				check();
				break;
			}
			case 3: {
				x += distance;
				cnt++;
				check();
				break;
			}
			}
		}
		else {
			cnt++;
			if (cnt == 5) cnt = 0;
		}
	}
	char getShape() { return '@'; }
};

class Game {
	char field[10][20];
public:
	Game() { reset(); }
	void reset() {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 20; j++)
				field[i][j] = '-';
	}
	void show() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				cout << field[i][j];
			}
			cout << endl;
		}
	}
	void set(Human& h, Monster& m, Food& f) {
		reset();
		field[h.getX()][h.getY()] = h.getShape();
		field[m.getX()][m.getY()] = m.getShape();
		field[f.getX()][f.getY()] = f.getShape();
	}
};
int main() {
	Human h(0, 9, 1);
	Monster m(5, 5, 2);
	Food f(4, 5, 1);

	Game game;
	game.set(h,m,f);
	cout << "** Human�� Food �Ա� ������ �����մϴ�. **" << endl;
	while (true) {
		game.show();
		cout << "����(a), �Ʒ�(s), ��(d), ������(f) >> ";
		h.move();
		m.move();
		f.move();
		game.set(h, m, f);
		if (h.collide(&f)) {
			game.show();
			cout << "Human is Winner!!" << endl;
			break;
		}
		else if (m.collide(&f) || m.collide(&h)) {
			game.show();
			cout << "Game over" << endl;
			break;
		}
	}
}