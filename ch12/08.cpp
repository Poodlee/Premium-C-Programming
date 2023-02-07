#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main() {
    ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
    if (!fin) {
        cout << "c:\\windows\\system.ini ���� ����" << endl;
    }
    cout << "c:\\windows\\system.ini ���" << endl << endl;
    while (true) {
        int cnt = 0, j = 0, c=0;    // 16����Ʈ �а� tap�ϱ� ���� cnt, �д� ���� �ľ��� ���ڸ� ��Ÿ���� ���� j, ���ڿ� �޾Ƴ� c
        char ch[16] = { 0 };    // �� ���ο� 8���� 16���� ���� -> 16����Ʈ -> char�� 1����Ʈ�ν� 16���� �о�ڴ�. 
        for (int i = 0; i < 16; i++) {  // �� ���ξ� �аڴ�.
            c = fin.get();
            if (fin.tellg() == EOF)
                break;
            ch[i] = c;
            j++;
        }
        for (int i = 0; i < j; i++) {
            cout << hex << setw(2) << setfill('0') << (int)ch[i] << " ";    // 16���� ǥ��
            cnt++; 
            if (cnt % 8 == 0) // 16����Ʈ ������ tap
                cout << "  ";
        }
        if (j < 16) { // �� ����
            for (int i = 0; i < 16 - j; i++)
                cout << "   ";
            cout << "  ";
        }
        cnt = 0;
        for (int i = 0; i < j; i++) {
            if (isprint((int)ch[i])) {      // ���ڷ� ��Ÿ�� �� �ִ� ��
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
