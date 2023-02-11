#include <iostream>
#include <fstream>
using namespace std;

void getFileSize_Andprint(const char* file) { 
	try {
		ifstream fin(file);
		if (file == "NULL") throw - 1;
		if (!fin) throw - 2;
		fin.seekg(0, ios::end);
		int length = fin.tellg();
		cout << "파일 크기 = " << length << endl;
	}
	catch(int i){
		if (i == -1)
			cout << "예외 발생 : 파일명이 NULL 입니다." << endl;
		else if (i == -2)
			cout << "예외 발생 : 파일 불러 오기 실패 !!" << endl;
	}
}

int main() {
	getFileSize_Andprint("c:\\windows\\system.ini");
	getFileSize_Andprint("NULL");
}