#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	vector<string> v;
	ifstream fin("c:\\Temp\\words.txt", ios::in);
	if (!fin) {
		cout << "파일 열기 오류 !!" << endl;
		return 0;
	}
	// vector에 넣어서 관리하기
	string line;
	while (getline(fin, line))
		v.push_back(line);
	fin.close();

	// -----------------data setting complete-------
	cout << "--------------------------------" << endl;
	cout << "지금부터 행맨 게임을 시작합니다." << endl;
	cout << "--------------------------------" << endl;
	
	
	while (true) { // 전체 게임 흐름
		bool correct = false;
		int random = rand() % 25143;
		int length = v[random].size();
		string answer = v[random];

		// 가림막
		int block1, block2;				//젤 처음에 random으로 하다가 머리 아파서 rand로 변경
		block1 = rand() % answer.length();
		while (true) {				// if 문으로 계속 조건 걸었는데 그냥 틀릴때까지 while 돌리면 random성도 확보.
			block2 = rand() % answer.length();
			if (block1 != block2)
				break;
		}
		string temp = answer;
		temp[block1] = '-';		temp[block2] = '-';

		char answer_try,decide;
		// 하나의 단어에 대한 게임
		for (int i = 0; i < 5; i++) {	// 또 새롭게 while해서 5번 하면 break 보다 횟수가 정해진 거면 for문이 훨씬 편함.
			cout << temp << endl;
			cin >> answer_try;
			
			if (answer_try == answer[block1]) temp[block1] = answer[block1];
			else if (answer_try == answer[block2])	temp[block2] = answer[block2];
			if (temp == answer) {
				cout << answer << endl;
				correct = true;
				break;
			}
		}
		if (!correct) {
			cout << "5번 실패 하였습니다. " << endl;
			cout << answer << endl;
		}
		cout << "Next(y/n)?";
		cin >> decide;
		if (decide == 'n')
			return 0;
	}
}