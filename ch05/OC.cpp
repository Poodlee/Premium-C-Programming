/* 결과
아래에 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다.
lets meet 4 pm 2014.
.-.. . - ...   -- . . -   ....-   .--. --    ..--- ----- .---- ....- .-.-.-

모스 부호를 다시 영문 텍스트로 바꿉니다.
lets meet 4 pm 2014.
*/

#include <iostream>
#include <string>
using namespace std;

class Morse {
    string alphabet[26]; // 알파벳의 모스 부호 저장
    string digit[10]; // 숫자의 모스 부호 저장
    string slash, question, comma, period, plus, equal; // 특수 문자의 모스 부호 저장
public:
    Morse(); // alphabet[], digit[] 배열 및 특수 문자의 모스 부호 초기화
    void text2Mores(string text, string& morse); // 영문 텍스트를 모스 부호로 변환
    bool mores2text(string morse, string& text); // 모스 부호를 영문 텍스트로 변환
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
            morse = morse + alphabet[c - 97] + " ";     // 한 칸 뛰우고 해당 alphabet에 맞는 morse 부호로 변경
            // 처음에 morse[i] = alphabet[c-97] + " " ; 로 했다가 text의 위치와 morse의 위치와 동일하지 않는다는 것을 인지.
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
            case ' ':morse += "   "; break;  // 3칸 뛰우기
            }
        }
    }
}

bool Morse::mores2text(string morse, string& text) { // 뛰어쓰기 나올 때 까지(처음부터 mos 끝까지) 끊고 앞에 나온 모스 부호가 위의 alphabet 배열 내의 것과 같은 지 비교. 
                                                      // 이때 왜 bool로 선언했을까? 기존의 text와 비교해서 맞으면 true 틀리면 false로 -> 새로운 string 만들어야 함. -> test_text
    string alpha[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o",
        "p","q","r","s","t","u", "v","w","x","y","z" };
    string di[10] = { "0","1","2","3","4","5","6","7","8","9" };
    string test_text = "";
    for (int i = 0; i < morse.size();) {
        int index = morse.find(" ", i); // 194p
        if (index == -1) break; // 다 찾으면 끝 !
        bool confirm = false;   // 나왔는 지 확인용.
        string str = morse.substr(i, index - i);    // 모스 문자 하나 추출
        for (int j = 0; j < 26; j++) { //alphabet  비교
            if (str == alphabet[j]) {
                test_text.append(alpha[j]);
                confirm = true;
                break;
            }
        }
        if (confirm == false) {
            for (int j = 0; j < 9; j++) {  // 숫자 비교
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
    string text, morse; // text 와 morse를 번갈아서 표현
    Morse m;    // 객체 호출
    cout << "아래에 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다." << endl;
    getline(cin, text, '\n');
    m.text2Mores(text, morse); // morse를 참조 변수로 받아 morse만 변화시킨다. 
    cout << morse << endl << endl;
    cout << "모스 부호를 다시 영문 텍스트로 바꿉니다." << endl;
    if (m.mores2text(morse, text)) // text를 참조 변수로 받아 text만 변화시킨다.
        cout << text << endl;
    else
        cout << "모스 부호->텍스트 변환 에러" << endl;
}