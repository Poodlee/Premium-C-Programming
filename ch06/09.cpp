#include <iostream>
#include <string>
using namespace std;
#define MAX_LINE 1000

class Board {
private:
    static int index; // 몇 번째 줄로 넘어가는 지 표시
    static string story[MAX_LINE]; //게시글 전체 글 개수 제한
public:
    static void start();
    static void add(string line);
    static void print();
};
int Board::index = 0; // 전역 변수로 index 설정
string Board::story[MAX_LINE] = { " " };
void Board::start() {
    for (int i = 0; i < 13; i++) {
        cout << '*';
    }
    cout << " 게시판입니다. ";
    for (int i = 0; i < 13; i++) {
        cout << '*';
    }
}

void Board::add(string line) {
    if (index >= MAX_LINE) cout << "최대 글 작성 개수를 초과했습니다. " << endl;
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
    Board::add("중간고사는 감독 없는 자율 시험입니다.");
    Board::add("코딩 라운지 많이 이용해 주세요.");
    Board::print();
    Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
    Board::print();
}
