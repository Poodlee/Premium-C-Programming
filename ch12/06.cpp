#include <iostream>
#include <fstream>
using namespace std; 
// ����� �������
// ����� src�� dest ����. ��������� ������ �ľ� ������ �ľ��� tellg()

int main() {
	ifstream fsrc("c:\\windows\\system.ini", ios::in | ios::binary);
	ofstream fdest("c:\\Temp//system.txt", ios::out | ios::binary);

	if (!fsrc || !fdest) {
		cout << "���� ���� ����!!" << endl;
		return 0;
	}
	cout << "���� ����..." << endl;
	// ������ ũ�� ���ϱ�
	fsrc.seekg(0, ios::end); // ���� �� ������ �̵�
	int fsrcSize = fsrc.tellg(); // ���� pointer ��ġ -> ���� ����Ʈ ũ��
	int ten_percent = fsrcSize / 10; // 10%��ŭ �����ϸ鼭 �о� ���̱�

	char* buf = new char[ten_percent];
	// ó������ �о�� �Ǵϱ� ����ġ
	fsrc.seekg(0, ios::beg);
	
	for (int i = 0; i < 10; i++) {	// i<10 -> 100%
		fsrc.read(buf, ten_percent); // buf�� ten_percent��ŭ�� �� �б�
		int readCount = fsrc.gcount(); // ��� �� ����Ʈ ����?
		fdest.write(buf, readCount); // buf�� �ִ� ����Ʈ��ŭ ����
		cout << "." << readCount << "B " << (i + 1) * 10 << "%" << endl;
	}
	cout << fsrcSize << "B ���� �Ϸ�" << endl;

	fsrc.close();
	fdest.close();
	delete[]buf;

}

