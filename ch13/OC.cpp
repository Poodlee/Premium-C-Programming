#include <iostream>
#include <string>
#include <cctype>	// isdigit
using namespace std;

class HardwareException {
	string step;
	string msg;
public:
	HardwareException(string step = " ", string msg = " ") {
		this->step = step; this->msg = msg;
	}
	string getStep() { return step; }
	string getMsg() { return msg; }
	void setMsg(string msg) { this->msg = msg; }
	void print() {
		cout << step << " 스텝, " << msg << endl;
	}
};

class CPU {
	string instruction;
	int op1, op2;
	string op1_s, op2_s;
	string cmd;
	void fetch() throw(HardwareException); // 명령어를 키보드로부터 읽어 온다.
	void decode() throw(HardwareException); // 명령어 코드가 무엇인지 판별
	void execute() throw(HardwareException); // 명령어 코드에 따라 명령 실행
public:
	CPU() { ; }
	bool isInt(string x) {
		bool result = true;
		for (int i = 0; i < x.size(); i++) {
			if (isdigit(x[i]) == false) result = false;
		}

		return result;
	}
	void run() {	// fetch() decode() execute()를 순차적으로 호출
		while (1) {
			try {
				fetch();
				decode();
				execute();
			}
			catch (HardwareException e) {
				e.print();
			}
		}
	}
};

void CPU::fetch() {  // 입력 받기
	instruction = ""; // 미리 선언 해두기
	getline(cin, instruction);
	this->instruction = instruction;
	if (instruction == "")
		throw HardwareException("fecth", "명령 라인 없음");
}
void CPU::decode() { // 오류 있나 확인하기
	int voidNum = 0;
	for (int i = 0; i < instruction.size(); i++)
		if (instruction[i] == ' ') voidNum += 1;
	
	if (voidNum != 2) {
		throw HardwareException("decode", "피연산자 예외");
	}
	// string 쪼개기
	int voidIndex1 = instruction.find(' ');
	int voidIndex2 = instruction.find(' ', voidIndex1 + 1);

	cmd = instruction.substr(0, voidIndex1);
	string op1_s = instruction.substr(voidIndex1 + 1, voidIndex2 - voidIndex1 - 1);
	string op2_s = instruction.substr(voidIndex2 + 1);
	this->cmd = cmd; this->op1_s = op1_s; this->op2_s = op2_s;

	if (cmd == "ADD" || cmd == "SUB" || cmd == "MUL" || cmd == "DIV") {}
	else {
		throw HardwareException("decode", "invalid 명령어 예외");
	}
	if (cmd == "DIV" && op2_s == "0")
		throw HardwareException("decdoe", "0으로 나누는 예외");

	if (isInt(op1_s) == false || isInt(op2_s) == false)   // 무조건 문자인 지 확인할 때는 문자로 바꿔서 생각해야 한다. 
		throw HardwareException("decode", "피연산자 타입 예외");	// 위에서 op1_s를 op1으로 바꿔서 op1을 집어 넣으면 문자 'a'가 들어오면 abort() 에러 발생.
}
void CPU::execute() { // 결과 만들고 출력하기
	this->op1 = stoi(this->op1_s); this->op2 = stoi(this->op2_s);
	if (cmd == "ADD") {
		cout << "              " << "ADD " << op1 << " " << op2 << ":    " << op1 + op2 << endl;
	}
	else if (cmd == "SUB") {
		cout << "              " << "SUB " << op1 << " " << op2 << ":    " << op1 - op2 << endl;
	}
	else if (cmd == "MUL") {
		cout << "              " << "MUL " << op1 << " " << op2 << ":    " << op1 * op2 << endl;
	}
	else if (cmd == "DIV") {
		cout << "              " << "DIV " << op1 << " " << op2 << ":    " << op1 / op2 << endl;
	}
}

int main() {
	CPU DJ_CPU;
	DJ_CPU.run();
}