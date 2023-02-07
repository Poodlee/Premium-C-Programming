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

	// �ϴ� ũ�Ⱑ �̻��̿��� �ϰ� ���ۺκ� üũ.
	void search(string word) {
		int length = word.length();
		for (int i = 0; i < v.size(); i++) {
			if (length <= v[i].size()) {
				int count_word = 0;
				for (int j = 0; j < length; j++) {
					if (word[j] == v[i][j])
						count_word++;
				}
				if (count_word == length)
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
