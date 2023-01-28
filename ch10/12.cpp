#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;
class Word
{
private:
	string english;
	string korean;
public:
	Word() { english = korean = ""; }
	Word(string eng, string kor) { english = eng, korean = kor; }
	string getEn() { return english; }
	string getKo() { return korean; }
};
class Game
{
private:
	vector<Word> v;
	void insert()
	{
		cout << "���� �ܾ exit�� �Է��ϸ� �Է� ��" << endl;
		while (1)
		{
			string eng, kor;
			cout << "���� >>";
			cin >> eng;
			if (eng == "exit")
				break;
			cout << "�ѱ� >>";
			cin >> kor;
			v.push_back(Word(eng, kor));
		}
	}
	void quiz()
	{
		cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1-4 �� �ٸ� �Է½� ����." << endl;
		int n1; string answer;
		string bogi[4]; for (int i = 0; i < 4; i++) bogi[i] = "";
		int number[4]; for (int i = 0; i < 4; i++) number[i] = 0;
		int i;
		bool exit = true;
		while (1)
		{
			n1 = rand() % v.size();
			bogi[0] = v.at(n1).getKo();
			answer = bogi[0];
			cout << v.at(n1).getEn() << "?" << endl;

			while (exit) {				// �ߺ����� �ʴ� ���� �����
				for (i = 1; i < 4; i++) {
					n1 = rand() % v.size();
					bogi[i] = v.at(n1).getKo();
				}
				if (bogi[0] != bogi[1] && bogi[0] != bogi[2] && bogi[0] != bogi[3] &&
					bogi[1] != bogi[2] && bogi[1] != bogi[3] && bogi[2] != bogi[3])
					exit = false;
			}
			exit = true;

			number[0] = rand() % 4;
			while (exit) {					//���� ���� ����
				for (i = 1; i < 4; i++) {
					number[i] = rand() % 4;
				}
				if (number[0] != number[1] && number[0] != number[2] && number[0] != number[3] &&
					number[1] != number[2] && number[1] != number[3] && number[2] != number[3])
					exit = false;
			}
			exit = true;
			int result;

			for (i = 1; i < 5; i++)
				cout << "(" << i << ") " << bogi[number[i - 1]] << " ";
			cout << ":>";
			cin >> result;

			if (result != 1 && result != 2 && result != 3 && result != 4)	//���� �߿� ���� 1, 2, 3, 4 �̿��� ������ Ȯ���ؾ���
				break;
			else if (result == -1)  break;
			else if (answer == bogi[number[result - 1]])
				cout << "Excellent !!" << endl;
			else if (result == 1 || result == 2 || result == 3 || result == 4)
				cout << "No. !!" << endl;
		}
	}
public:
	Game()
	{
		srand((unsigned)time(NULL));
		v.push_back(Word("baby", "�Ʊ�"));
		v.push_back(Word("human", "�ΰ�"));
		v.push_back(Word("society", "��ȸ"));
		v.push_back(Word("photo", "����"));
		v.push_back(Word("painting", "�׸�"));
		v.push_back(Word("Love", "���"));
		v.push_back(Word("dall", "����"));
		v.push_back(Word("emotion", "����"));
		v.push_back(Word("trade", "�ŷ�"));
		v.push_back(Word("animal", "����"));
		v.push_back(Word("bear", "��"));
	}
	void run()
	{
		cout << "****** ���� ���� �׽�Ʈ�� �����մϴ�. ******\n";
		int opt;
		while (1)
		{
			cout << "���� ����: 1, ���� �׽�Ʈ: 2, ���α׷� ����:�׿� Ű >> ";
			cin >> opt;
			if (opt == 1)
				insert();
			else if (opt == 2)
				quiz();
			else
				break;
		}
	}
};
int main(void)
{
	Game g;
	g.run();
}