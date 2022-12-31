/* ���
�Ʒ��� ���� �ؽ�Ʈ�� �Է��ϼ���. �� ��ȣ�� �ٲߴϴ�.
lets meet 4 pm 2014.
.-.. . - ...   -- . . -   ....-   .--. --    ..--- ----- .---- ....- .-.-.-

�� ��ȣ�� �ٽ� ���� �ؽ�Ʈ�� �ٲߴϴ�.
lets meet 4 pm 2014.
*/

#include <iostream>
#include <string>
using namespace std;

class Morse {
    string alphabet[26]; // ���ĺ��� �� ��ȣ ����
    string digit[10]; // ������ �� ��ȣ ����
    string slash, question, comma, period, plus, equal; // Ư�� ������ �� ��ȣ ����
public:
    Morse(); // alphabet[], digit[] �迭 �� Ư�� ������ �� ��ȣ �ʱ�ȭ
    void text2Mores(string text, string& morse); // ���� �ؽ�Ʈ�� �� ��ȣ�� ��ȯ
    bool mores2text(string morse, string& text); // �� ��ȣ�� ���� �ؽ�Ʈ�� ��ȯ
};
Morse::Morse() {
    alphabet[0] = ".-"; alphabet[1] = "-..."; alphabet[2] = "-.-."; alphabet[3] = "-..";
    alphabet[4] = "."; alphabet[5] = "..-."; alphabet[6] = "--."; alphabet[7] = "....";
    alphabet[8] = ".."; alphabet[9] = ".---"; alphabet[10] = "-.-"; alphabet[11] = ".-..";
    alphabet[12] = "--"; alphabet[13] = "-."; alphabet[14] = "---"; alphabet[15] = ".--.";
    alphabet[16] = "--.-"; alphabet[17] = ".-."; alphabet[18] = "..."; alphabet[19] = "-";
    alphabet[20] = "..-"; alphabet[21] = "...-"; alphabet[22] = ".--"; alphabet[23] = "-..-";
    alphabet[24] = "-.--"; alphabet[25] = "--.."; digit[0] = "-----"; digit[1] = ".----";
    digit[2] = "..---"; digit[3] = "...--"; digit[4] = "....-"; digit[5] = ".....";
    digit[6] = "-...."; digit[7] = "--..."; digit[8] = "---.."; digit[9] = "----.";
    slash = "-..-."; question = "..--.."; comma = "--..--"; period = ".-.-.-";
    plus = ".-.-"; equal = "-...-";
}
void Morse::text2Mores(string text, string& morse) {
    for (int i = 0; i < text.size(); ++i) {
        char c = text.at(i);
        if (c >= 65 && c <= 90) c = tolower(c);     //  ASCII Code to lower
        if (c >= 97 && c <= 122) {
            morse = morse + alphabet[c - 97] + " ";     // �� ĭ �ٿ�� �ش� alphabet�� �´� morse ��ȣ�� ����
            // ó���� morse[i] = alphabet[c-97] + " " ; �� �ߴٰ� text�� ��ġ�� morse�� ��ġ�� �������� �ʴ´ٴ� ���� ����.
        }
        else if (c >= 48 && c <= 57) {
            morse = morse + digit[c - 48] + " ";
        }
        else {
            switch (c)
            {
            case '/':morse = morse + slash + " "; break;
            case '?':morse = morse + question + " "; break;
            case ',':morse = morse + comma + " "; break;
            case '.':morse = morse + period + " "; break;
            case '+':morse = morse + plus + " "; break;
            case '=':morse = morse + equal + " "; break;
            case ' ':morse += "   "; break;  // 3ĭ �ٿ��
            }
        }
    }
}

bool Morse::mores2text(string morse, string& text) { // �پ�� ���� �� ����(ó������ mos ������) ���� �տ� ���� �� ��ȣ�� ���� alphabet �迭 ���� �Ͱ� ���� �� ��. 
                                                      // �̶� �� bool�� ����������? ������ text�� ���ؼ� ������ true Ʋ���� false�� -> ���ο� string ������ ��. -> test_text
    string alpha[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o",
        "p","q","r","s","t","u", "v","w","x","y","z" };
    string di[10] = { "0","1","2","3","4","5","6","7","8","9" };
    string test_text = "";
    for (int i = 0; i < morse.size();) {
        int index = morse.find(" ", i); // 194p
        if (index == -1) break; // �� ã���� �� !
        bool confirm = false;   // ���Դ� �� Ȯ�ο�.
        string str = morse.substr(i, index - i);    // �� ���� �ϳ� ����
        for (int j = 0; j < 26; j++) { //alphabet  ��
            if (str == alphabet[j]) {
                test_text.append(alpha[j]);
                confirm = true;
                break;
            }
        }
        if (confirm == false) {
            for (int j = 0; j < 9; j++) {  // ���� ��
                if (str == digit[j]) {
                    test_text.append(di[j]);
                    confirm = true;
                    break;
                }
            }
        }
        if (confirm == false) {
            if (str == slash) test_text.append("/");
            else if (str == question) test_text.append("?");
            else if (str == comma) test_text.append(",");
            else if (str == period) test_text.append(".");
            else if (str == plus) test_text.append("+");
            else if (str == equal) test_text.append("=");
        }
        if (morse[index] == ' ' && morse[index + 1] == ' ' && morse[index + 2] == ' ') {
            test_text.append(" ");
            index += 2;
        }
        i = index + 1;
    }
    if (test_text == text) return true;
    else return false;
}

int main() {
    string text, morse; // text �� morse�� �����Ƽ� ǥ��
    Morse m;    // ��ü ȣ��
    cout << "�Ʒ��� ���� �ؽ�Ʈ�� �Է��ϼ���. �� ��ȣ�� �ٲߴϴ�." << endl;
    getline(cin, text, '\n');
    m.text2Mores(text, morse); // morse�� ���� ������ �޾� morse�� ��ȭ��Ų��. 
    cout << morse << endl << endl;
    cout << "�� ��ȣ�� �ٽ� ���� �ؽ�Ʈ�� �ٲߴϴ�." << endl;
    if (m.mores2text(morse, text)) // text�� ���� ������ �޾� text�� ��ȭ��Ų��.
        cout << text << endl;
    else
        cout << "�� ��ȣ->�ؽ�Ʈ ��ȯ ����" << endl;
}