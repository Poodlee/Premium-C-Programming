#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// 비교는 가장 먼저 크기 비교 크기 같으면 성분 비교.
bool FileCompare(const char* file1, const char* file2) {
	ifstream fin_first(file1, ios::in | ios::binary);
	ifstream fin_second(file2, ios::in | ios::binary);
	if (!fin_first || !fin_second) {
		cout << "파일 열기 실패!!" << endl;
	}
	// file size
	fin_first.seekg(0, ios::end);	int file1_Size = fin_first.tellg();
	fin_second.seekg(0, ios::end);	int file2_Size = fin_second.tellg();
	if (file1_Size != file2_Size) {
		cout << "사이즈 자체가 다릅니다." << endl;
		return false;
	}

	// component (per line)
	vector<string> v1, v2;
	string line1, line2;
	while (getline(fin_first, line1))
		v1.push_back(line1);
	while (getline(fin_second, line2))
		v2.push_back(line2);
	if (v1 == v2)	return true;
	else return false;

}


int main() {
	cout << "c:\\temp에 있는 사진을 비교하겠습니다. (같은 사진)" << endl;
	if (FileCompare("c:\\temp\\pixel1.jpg", "c:\\temp\\pixel1_2.jpg"))
		cout << "두 파일은 같습니다. " << endl;
	else
		cout << "두 파일은 같지 않습니다." << endl;

	cout << "c:\\temp에 있는 사진을 비교하겠습니다. (다른 사진)" << endl;
	if (FileCompare("c:\\temp\\pixel1.jpg", "c:\\temp\\pixel2.jpg"))
		cout << "두 파일은 같습니다. " << endl;
	else
		cout << "두 파일은 같지 않습니다." << endl;
}