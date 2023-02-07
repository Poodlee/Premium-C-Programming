#include <iostream>
#include <fstream>
using namespace std; 
// 복사와 진행사항
// 복사는 src와 dest 설정. 진행사항은 사이즈 파악 사이즈 파악은 tellg()

int main() {
	ifstream fsrc("c:\\windows\\system.ini", ios::in | ios::binary);
	ofstream fdest("c:\\Temp//system.txt", ios::out | ios::binary);

	if (!fsrc || !fdest) {
		cout << "파일 열기 실패!!" << endl;
		return 0;
	}
	cout << "복사 시작..." << endl;
	// 파일의 크기 구하기
	fsrc.seekg(0, ios::end); // 파일 맨 끝으로 이동
	int fsrcSize = fsrc.tellg(); // 현재 pointer 위치 -> 파일 바이트 크기
	int ten_percent = fsrcSize / 10; // 10%만큼 증가하면서 읽어 들이기

	char* buf = new char[ten_percent];
	// 처음부터 읽어야 되니까 원위치
	fsrc.seekg(0, ios::beg);
	
	for (int i = 0; i < 10; i++) {	// i<10 -> 100%
		fsrc.read(buf, ten_percent); // buf에 ten_percent만큼의 값 읽기
		int readCount = fsrc.gcount(); // 방금 몇 바이트 읽음?
		fdest.write(buf, readCount); // buf에 있는 바이트만큼 쓰기
		cout << "." << readCount << "B " << (i + 1) * 10 << "%" << endl;
	}
	cout << fsrcSize << "B 복사 완료" << endl;

	fsrc.close();
	fdest.close();
	delete[]buf;

}

