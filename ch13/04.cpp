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
		cout << "���� ũ�� = " << length << endl;
	}
	catch(int i){
		if (i == -1)
			cout << "���� �߻� : ���ϸ��� NULL �Դϴ�." << endl;
		else if (i == -2)
			cout << "���� �߻� : ���� �ҷ� ���� ���� !!" << endl;
	}
}

int main() {
	getFileSize_Andprint("c:\\windows\\system.ini");
	getFileSize_Andprint("NULL");
}