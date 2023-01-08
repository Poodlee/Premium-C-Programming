#include <iostream>
#include <string>
using namespace std;
#define MAX_LINE 1000

class Board {
private:
    static int index; // �� ��° �ٷ� �Ѿ�� �� ǥ��
    static string story[MAX_LINE]; //�Խñ� ��ü �� ���� ����
public:
    static void start();
    static void add(string line);
    static void print();
};
int Board::index = 0; // ���� ������ index ����
string Board::story[MAX_LINE] = { " " };
void Board::start() {
    for (int i = 0; i < 13; i++) {
        cout << '*';
    }
    cout << " �Խ����Դϴ�. ";
    for (int i = 0; i < 13; i++) {
        cout << '*';
    }
}

void Board::add(string line) {
    if (index >= MAX_LINE) cout << "�ִ� �� �ۼ� ������ �ʰ��߽��ϴ�. " << endl;
    else {
        story[index] = line;
        index++;
    }
}

void Board::print() {
    start();
    cout << endl;
    for (int i = 0; i < index; i++) {
        cout << i << ": " << story[i] << endl;
    }
    cout << endl;
}

int main()
{
    Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
    Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
    Board::print();
    Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
    Board::print();
}
