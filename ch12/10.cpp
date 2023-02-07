#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// �񱳴� ���� ���� ũ�� �� ũ�� ������ ���� ��.
bool FileCompare(const char* file1, const char* file2) {
	ifstream fin_first(file1, ios::in | ios::binary);
	ifstream fin_second(file2, ios::in | ios::binary);
	if (!fin_first || !fin_second) {
		cout << "���� ���� ����!!" << endl;
	}
	// file size
	fin_first.seekg(0, ios::end);	int file1_Size = fin_first.tellg();
	fin_second.seekg(0, ios::end);	int file2_Size = fin_second.tellg();
	if (file1_Size != file2_Size) {
		cout << "������ ��ü�� �ٸ��ϴ�." << endl;
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
	cout << "c:\\temp�� �ִ� ������ ���ϰڽ��ϴ�. (���� ����)" << endl;
	if (FileCompare("c:\\temp\\pixel1.jpg", "c:\\temp\\pixel1_2.jpg"))
		cout << "�� ������ �����ϴ�. " << endl;
	else
		cout << "�� ������ ���� �ʽ��ϴ�." << endl;

	cout << "c:\\temp�� �ִ� ������ ���ϰڽ��ϴ�. (�ٸ� ����)" << endl;
	if (FileCompare("c:\\temp\\pixel1.jpg", "c:\\temp\\pixel2.jpg"))
		cout << "�� ������ �����ϴ�. " << endl;
	else
		cout << "�� ������ ���� �ʽ��ϴ�." << endl;
}