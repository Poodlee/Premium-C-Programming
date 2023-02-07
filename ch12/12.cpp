#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

// �ܾ� ã�� ��� (���� + ��-> �� ���� �ٸ� �� ã��)
class SearchWords {
private:
	ifstream fin;
	vector<string> v;
	bool exist(string word) {
		for (int i = 0; i < v.size(); i++) {
			if (word == v[i])
				return true;
		}
		return false;
	}

	// ���� �� ���� ���� ũ�� -> �� ���� ���� (�ܾ� �����ؼ� ���ϸ� ���� �ʳ�?)
	void search(string word) {
		int length = word.length();
		for (int i = 0; i < v.size(); i++) {
			if (length == v[i].size()) {
				int count_word = 0;
				/*
				string temp_word = word;	// ���� �� ���� ���ڿ� ��ȭ����
				string temp_v = v[i];
				sort(temp_word.begin(), temp_word.end());
				sort(temp_v.begin(), temp_v.end());
				*/
				for (int j = 0; j < length; j++) {
					if (word[j] == v[i][j])
						count_word++;
				}
				if (count_word == length - 1)
					cout << v[i] << endl;
			}
		}
	}
public:
	SearchWords() {
		fin.open("c:\\Temp\\words.txt");
		if (!fin) {
			cout << "���� ���� ����!! " << endl;
		}
		string line;
		while (getline(fin, line))
			v.push_back(line);
		cout << "... words.txt ���� �ε� �Ϸ�" << endl;
	}
	~SearchWords() { fin.close(); }
	void run() {
		cout << "�˻��� �����մϴ�. �ܾ �Է��� �ּ���." << endl;
		while (1) {
			cout << "�ܾ�>> ";
			string word;
			getline(cin, word);
			if (word == "exit")
				return;
			if (!exist(word))
				cout << word << "�ܾ� ����." << endl;
			search(word);
		}
	}
};

int main() {

	SearchWords s;
	s.run();
}
