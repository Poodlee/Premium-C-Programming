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
		cout << "���� ���� ���� !!" << endl;
		return 0;
	}
	// vector�� �־ �����ϱ�
	string line;
	while (getline(fin, line))
		v.push_back(line);
	fin.close();

	// -----------------data setting complete-------
	cout << "--------------------------------" << endl;
	cout << "���ݺ��� ��� ������ �����մϴ�." << endl;
	cout << "--------------------------------" << endl;
	
	
	while (true) { // ��ü ���� �帧
		bool correct = false;
		int random = rand() % 25143;
		int length = v[random].size();
		string answer = v[random];

		// ������
		int block1, block2;				//�� ó���� random���� �ϴٰ� �Ӹ� ���ļ� rand�� ����
		block1 = rand() % answer.length();
		while (true) {				// if ������ ��� ���� �ɾ��µ� �׳� Ʋ�������� while ������ random���� Ȯ��.
			block2 = rand() % answer.length();
			if (block1 != block2)
				break;
		}
		string temp = answer;
		temp[block1] = '-';		temp[block2] = '-';

		char answer_try,decide;
		// �ϳ��� �ܾ ���� ����
		for (int i = 0; i < 5; i++) {	// �� ���Ӱ� while�ؼ� 5�� �ϸ� break ���� Ƚ���� ������ �Ÿ� for���� �ξ� ����.
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
			cout << "5�� ���� �Ͽ����ϴ�. " << endl;
			cout << answer << endl;
		}
		cout << "Next(y/n)?";
		cin >> decide;
		if (decide == 'n')
			return 0;
	}
}