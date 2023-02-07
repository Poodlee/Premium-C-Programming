#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

// 단어 찾기 기능 (유무 + 유-> 한 글자 다른 것 찾기)
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

	// 비교할 때 가장 먼저 크기 -> 그 다음 성분 (단어 정렬해서 비교하면 되지 않나?)
	void search(string word) {
		int length = word.length();
		for (int i = 0; i < v.size(); i++) {
			if (length == v[i].size()) {
				int count_word = 0;
				/*
				string temp_word = word;	// 정렬 시 원래 문자열 변화때문
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
			cout << "파일 열기 실패!! " << endl;
		}
		string line;
		while (getline(fin, line))
			v.push_back(line);
		cout << "... words.txt 파일 로딩 완료" << endl;
	}
	~SearchWords() { fin.close(); }
	void run() {
		cout << "검색을 시작합니다. 단어를 입력해 주세요." << endl;
		while (1) {
			cout << "단어>> ";
			string word;
			getline(cin, word);
			if (word == "exit")
				return;
			if (!exist(word))
				cout << word << "단어 없음." << endl;
			search(word);
		}
	}
};

int main() {

	SearchWords s;
	s.run();
}
