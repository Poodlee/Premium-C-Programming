#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main() {
    ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
    if (!fin) {
        cout << "c:\\windows\\system.ini 열기 오류" << endl;
    }
    cout << "c:\\windows\\system.ini 출력" << endl << endl;
    while (true) {
        int cnt = 0, j = 0, c=0;    // 16바이트 읽고 tap하기 위해 cnt, 읽는 개수 파악해 빈자리 나타내기 위한 j, 문자열 받아낼 c
        char ch[16] = { 0 };    // 한 라인에 8개의 16진수 존재 -> 16바이트 -> char는 1바이트로써 16개를 읽어내겠다. 
        for (int i = 0; i < 16; i++) {  // 한 라인씩 읽겠다.
            c = fin.get();
            if (fin.tellg() == EOF)
                break;
            ch[i] = c;
            j++;
        }
        for (int i = 0; i < j; i++) {
            cout << hex << setw(2) << setfill('0') << (int)ch[i] << " ";    // 16진수 표현
            cnt++; 
            if (cnt % 8 == 0) // 16바이트 읽으면 tap
                cout << "  ";
        }
        if (j < 16) { // 끝 라인
            for (int i = 0; i < 16 - j; i++)
                cout << "   ";
            cout << "  ";
        }
        cnt = 0;
        for (int i = 0; i < j; i++) {
            if (isprint((int)ch[i])) {      // 문자로 나타낼 수 있는 지
                cout << setw(2) << setfill(' ') << ch[i];
                cnt++;
            }
            else {
                cout << ".";
                cnt++;
            }
            if (cnt % 8 == 0)
                cout << "  ";
        }

        if (fin.tellg() == EOF)
            break;
        cout << endl;

    }
    cout << endl;

}
