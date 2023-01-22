#include <iostream>
#include <string>
using namespace std;

// 비행기 예약 프로그램
// 항공사 이름: 한성항공, 8개의 좌석.3대의 비행기. 서울 부산 간 운항
// 각 비행기 하루에 한 번만 운행. 시간 07시,12시,17시.
// 다음의 기능: 예약, 취소, 예약 보기
// 예약: 비행 시간, 사용자 이름, 좌석 번호 입력 받아 예약
// 취소: 비행 시간, 사용자 이름, 좌석 번호 입력받고 예약 취소 
// 예약은 배열에 넣으면 된다. 취소는 삭제해야 하는데 흠.. 316p 6번 참고하면 될 듯하다. 동적 생성후 제거
// 아니면 그냥 다시 add로 배열의 성분에 집어 넣기? 
// 예약도 가능 시간 알려주고 선택하기.

// 항공사 총 3대의 비행기 운행
// 각 비행기는 별도의 seat와 timetable중 한 자리 선정
// 각 비행기에는 예약, 예약 취소, 예약확인이 들어가야 한다. 
class airline {
	string airline_name;
public:
	airline() {;}
	airline(string name) {
		this->airline_name = name;
	}
};
//예약할 때 비행기 선택하면 남은 시간과 남은 자리 리스트 출력.
class airplane : public airline {
public:
	int seat[8];			// 자리에 누가 들어갔으면 0. 공석이면 1.
	string name[8];			// 예약자 이름 확인용
	airplane() { 
		for (int i = 0; i < 8; i++) { seat[i] = 1; name[i] = "0"; }
	}
	void checkVacancy();
	bool checkVacancy2();
	void reserve(int time,string names, int seatNumber);
	void check_reserve(int time,string names, int seatNumber);
	void cancel_reserve(int time,string names, int seatNumber);
};

void airplane::checkVacancy() {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		if (seat[i] == 1) cnt++;
		}
	cout << "현재 해당 시간 비행기에 남은 좌석은 " << cnt << "개로  ";
		for (int i = 0; i < 8; i++) { 
			if (seat[i] == 1) cout << i+1 << ' ';
		}
		cout << "이 남아 있습니다." << endl;
	if (cnt == 0) {
		cout << "해당 시간 비행기에 남은 좌석은 없습니다.";
	}
}

bool airplane::checkVacancy2() {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int i = 0; i < 8; i++) {
			if (seat[i] == 1) cnt++;
		}
		}
	if (cnt == 0) { return false; }
	else return true;
}


void airplane::reserve(int time,string names, int seatNumber) {
	if (seat[seatNumber-1] == 0 || name[seatNumber-1] != "0") {
		cout << "해당 좌석은 이미 다른 사람이 예약중에 있습니다." << endl;
	}
	else { seat[seatNumber-1] = 0; name[seatNumber-1] = "names";
		cout << names << "님 " << time << "시에 출발하는 비행기의 " << seatNumber << "번 좌석에 예약 완료 됐습니다." << endl;
	}
}

void airplane::check_reserve(int time,string names, int seatNumber) {
	cout << endl << "-------------------------조회 중입니다.-----------------" << endl << endl;
	if (seat[seatNumber-1] == 0 && name[seatNumber-1] == "names") {
		cout << names << "님은 현재 " << time << "시에 출발하는 비행기의 " << seatNumber << "번 좌석에 예약이 되어 있습니다." << endl;
	}
	else {
		cout << "해당 내용을 만족하는 예약 기록은 없습니다." << endl;
	}
}

void airplane::cancel_reserve(int time,string names, int seatNumber) {
	if (seat[seatNumber-1] == 0 && name[seatNumber-1] == "names") {
		cout << names << "님의 현재 " << time << "시에 출발하는 비행기의 " << seatNumber << "번 좌석에 대해 예약을 취소하시겠습니까?(y/n)";
		char yes_no;
		cin >> yes_no;
		if (yes_no == 'n') return;
		else {
			seat[seatNumber-1] = 1; name[seatNumber-1] = '0';
			cout << names << "님의 예약 취소를 완료했습니다." << endl;
		}
	}
	else {
		cout << "해당 내용을 만족하는 예약 기록은 없습니다." << endl;
	}
}

void response(airplane& air1, airplane& air2, airplane& air3) {
	cout << endl << "안녕하십니까 고객님 한성항공입니다." << endl;
	cout << "고객님 저희는 07시, 12시, 17시 항공편이 존재합니다. 몇 시 비행기와 관련된 업무를 희망하실까요?";
	int times,seatNumber;
	int function;
	string name;
	cin >> times;
	cout << endl;
	if (times == 7) {
		cout << "고객님은 현재 07시 비행기1과 관련되서 어떠한 업무가 필요하신가요?" << endl;
		cout << "1. 예약, 2.예약 취소, 3.예약 확인"; 
		cin >> function;
		switch (function) {
			case 1: {
				air1.checkVacancy();
				if (air1.checkVacancy2() == 1) {
					cout << "예약을 진행하기 위해서 예약을 희망하시면 이름, 좌석번호 순서대로 입력해주세요.";
					cin >> name >> seatNumber;
					air1.reserve(7,name, seatNumber); break;
				}
				else break;
			}
			case 2: {
				cout << "예약 취소를 진행하기 위해서 이름, 좌석번호 순서대로 입력해주세요.";
				cin >> name >> seatNumber;
				air1.cancel_reserve(7,name, seatNumber); break;
			}
			case 3: {
				cout << "예약 확인을 진행하기 위해서 이름, 좌석번호 순서대로 입력해주세요.";
				cin >> name >> seatNumber;
				air1.check_reserve(7,name, seatNumber); break;
			}
		}
	}
	if (times == 12) {
		cout << "고객님은 현재 12시 비행기1과 관련되서 어떠한 업무가 필요하신가요?" << endl;
		cout << "1. 예약, 2.예약 취소, 3.예약 확인";
		cin >> function;
		switch (function) {
		case 1: {
			air2.checkVacancy();
			if (air2.checkVacancy2() == 1) {
				cout << "예약을 진행하기 위해서 예약을 희망하시면 이름, 좌석번호 순서대로 입력해주세요.";
				cin >> name >> seatNumber;
				air2.reserve(12, name, seatNumber); break;
			}
			else break;
		}
		case 2: {
			cout << "예약 취소를 진행하기 위해서 이름, 좌석번호 순서대로 입력해주세요.";
			cin >> name >> seatNumber;
			air2.cancel_reserve(12, name, seatNumber); break;
		}
		case 3: {
			cout << "예약 확인을 진행하기 위해서 이름, 좌석번호 순서대로 입력해주세요.";
			cin >> name >> seatNumber;
			air2.check_reserve(12, name, seatNumber); break;
		}
		}
	}
	if (times == 17) {
		cout << "고객님은 현재 17시 비행기1과 관련되서 어떠한 업무가 필요하신가요?" << endl;
		cout << "1. 예약, 2.예약 취소, 3.예약 확인";
		cin >> function;
		switch (function) {
		case 1: {
			air3.checkVacancy();
			if (air3.checkVacancy2() == 1) {
				cout << "예약을 진행하기 위해서 예약을 희망하시면 이름, 좌석번호 순서대로 입력해주세요.";
				cin >> name >> seatNumber;
				air3.reserve(17, name, seatNumber); break;
			}
			else break;
		}
		case 2: {
			cout << "예약 취소를 진행하기 위해서 이름, 좌석번호 순서대로 입력해주세요.";
			cin >> name >> seatNumber;
			air3.cancel_reserve(17, name, seatNumber); break;
		}
		case 3: {
			cout << "예약 확인을 진행하기 위해서 이름, 좌석번호 순서대로 입력해주세요.";
			cin >> name >> seatNumber;
			air3.check_reserve(17, name, seatNumber); break;
		}
		}
	}
}

int main() {
	airline airline_Hansung("한성항공");
	airplane airplane1, airplane2, airplane3;
	while (true) {
		response(airplane1, airplane2, airplane3);
	}
}