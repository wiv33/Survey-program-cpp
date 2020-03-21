// Survey_knou.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include <string>
#include "Question.h"
#include "Selection.h"
#include "Survey.h"

using namespace std;
int getNumber(string outString, int capacity); //함수 원형 선언

/*
MAIN 시작
*/
int main()
{
	IDisplay display; // interface로 활용할 display 선언
	std::string title, inputString; //title 변수 선언, 사용자 입력 문자열 선언
	int selectNum = 0; // 

	cout << "설문 작성을 시작합니다." << endl;

	/* 질문 등록 시작 */
	cout << "질문을 등록하세요." << endl;
	std::getline(std::cin, title);

	Question *que = new Question(title);

	while (selectNum != 0) {
		cout << "항목의 숫자를 입력해주세요." << endl;
		selectNum = getNumber("[1]. 등록된 질문 확인\t[2]. 질문 재등록\t[0]. 다음 단계", 2);
		cout << selectNum << "을 입력하셨습니다." << endl;
		switch (selectNum) {
		case 1:
			//질문 출력
			que->print();
			//TODO
			break;
		case 2:
			// Question의 title을 다시 등록.
			std::cin.ignore();
			cout << "질문을 등록하세요." << endl;
			std::getline(std::cin, title);
			que->setTitle(title);
			break;
		case 0:
			cout << "0번 다음 단계로 넘어갑니다.\n" << endl;
			break;
		default:
			break;
		}
	}
	/* 질문 등록 끝 */

	/* 선택항목 등록 시작 */
	// 질문의 최대 등록 개수는 256개, 요구사항 변경 시 늘릴 수 있다.
	
	int paramNum = getNumber("선택항목의 개수를 입력하세요.", 256);
	if (paramNum <= 0) {
		cout << "선택항목의 개수는 최소 1개입니다.\n" << "선택 항목은 1개로 설정됩니다." << endl;
		paramNum = 1;
	}
	
	


	cout << "선택항목의 수는 [" << paramNum << "] 입니다." << endl;

	std::cin.ignore();

	string *str = new string[paramNum];
	Selection *selections = new Selection[paramNum];

	// cout << paramNum << endl;
	for (int i = 0; i < paramNum; i++) {
		string temp;
		cout << (i + 1) << ". 선택항목의 제목을 입력하세요. ";
		std::getline(std::cin, temp);
		selections[i] = Selection(temp);
		//s[i].print();
	}

	do {
		cout << "항목의 숫자를 입력해주세요." << endl;
		selectNum = getNumber("[1]. 선택항목 출력\t[2]. 선택항목 다시 등록 \t[0] 다음 단계", 2);
		int checkNum = 0;
		string temp;

		switch (selectNum) {
		case 1:
			// 선택항목 출력
			for (int i = 0; i < paramNum; i++) {
				cout << (i + 1) << ". ";
				selections[i].print();
			}
			break;
		case 2:
			// 다시 등록할 선택 항목의 번호를 입력 받아서 해당 번호 Selection title을 변경한다.
			// while 내에서 1번과 do while 문으로 나갈 수 있도록 로직 구현 
			checkNum = getNumber("다시 등록할 선택항목의 번호를 입력하세요.", paramNum);
			cout << checkNum << ". 선택항목의 제목을 입력하세요. ";
			std::cin.ignore(); //사용자의 입력 값 무시, 간헐적으로 cin 값이 제대로 동작하지 않음.
			std::getline(std::cin, temp); // 한 줄을 입력받아 temp에 저장
			selections[checkNum - 1] = Selection(temp); // 해당 selection을 찾아 새로운 Selection 객체를 생성하여 대입. 
			selections[checkNum - 1].print();
			break;
		default:
			break;
		}

	} while (selectNum != 0);
	/* 선택항목 등록 끝 */

	cout << "\n" << endl;
	// Question과 Selections를 취합하여 Survey를 완성한다.
	Survey *survey = new Survey(); // 객체 생성
	
	survey->setQuestion(*que); // Question 객체 주입
	survey->setSelections(selections); // Selection 객체의 배열 주입

	Selection *selArr = survey->getSelections(); // 설문 객체에 주입된 Selections 배열을 꺼내온다.

	cout << "===============================================" << endl;
	cout << "========= 설문 작성이 완료되었습니다. =========" << endl;
	cout << "===============================================\n" << endl;

	cout << "**********************************************" << endl;
	cout << "*****         설문을 시작합니다.         *****" << endl; 
	cout << "**********************************************\n" << endl;

	selectNum = getNumber("#투표 방식을 선택하세요.\n# [1]. 비밀투표\t[2]. 공개투표", 3);
	bool secret = selectNum == 1 ? 1 : 0; // 1번일 경우 비밀투표이고 0, 2번을 입력 시 공개투표 처리

	do {
		cout << "" << endl;
		cout << "투표 방식은 [" << (secret ? "비밀" : "공개") << "투표] 입니다." << endl;
		survey->getQuestion().print(); // 설문 객체에 등록된 Question의 출력을 호출
		for (int i = 0; i < paramNum; i++) { // 총 선택항목의 수 만큼 반복
			Selection *s = &selArr[i];
			cout << (i + 1) << ". ";
			s->setSecret(secret); // 각 선택항목의 공개 / 비밀 여부를 주입 // 설계의 오류. -> 이 구간은 Survey 객체에서 관리되었어야 했다.
			s->print(); // 선택항목의 내용 출력
		}
		cout << "" << endl;
		selectNum = getNumber("# 투표할 항목의 번호를 입력해주세요. (종료는 0번)", paramNum);

		int finalChk = 0; // 마지막 사용자 선택의 구분을 위한 Check 값

		if (selectNum == 0) { //입력 값이 0이면 종료 선택지로 이동
			//종료 중에서 사용자 선택
			do {
				finalChk = getNumber("# [1]. 설문 결과 확인\t[2]. 설문 초기화\t[3] 이전 단계\t[0]. 설문 종료", 3);
				string *str = new string[paramNum];
				switch (finalChk) {
				case 1:
					// 질문과 선택항목을 출력한다.
					cout << "==========================================================" << endl;
					survey->getQuestion().print();
					for (int i = 0; i < paramNum; i++) {
						Selection *s = &selArr[i];
						cout << (i + 1) << ". ";
						s->setSecret(true); // 설문 결과 확인에선 공개처리
						s->print();
					}
					
					cout << "\n총 투표 수 [ " << survey->getTotalCount() << " ]" << endl;
					// 현재까지 투표를 출력한다. 투표는 #으로 표시, 
					for (int i = 0; i < paramNum; i++) {
						Selection *s = &selArr[i];
						// output 함수의 사용을 최소화하기 위해 append() 함수를 사용.
						for (int j = 0; j < s->getSelectNum() - 1; j++) {
							str[i].append("#");
						}
						// 총 개수와 #을 출력
						cout << "[" << (i + 1) << "]번 투표 수 [ " << str[i].length() << " ] ->" << str[i] << endl;
					}
					cout << "==========================================================" << endl;
					break;
				case 2:
					//  선택항목의 selectNum을 모두 초기화한다.
					for (int i = 0; i < paramNum; i++) {
						Selection *s = &selArr[i];
						s->setSelectNum(0);
					}
					survey->setTotalCount(0); // 총 투표 수 초기화
					cout << "# 선택 값이 모두 초기화되었습니다." << endl;
					break;
				case 3: 
					// 이전 단계로의 이동이기 때문에 최종에서는 벗어나고 투표를 진행할 수 있다.
					finalChk = 0;
					selectNum = -1;
					break;
				default:
					// 설문 종료로 모든 값을 종료 처리중인 0으로 치환 후 종료를 알린다.
					finalChk = 0;
					selectNum = 0;
					cout << "**********************************************" << endl;
					cout << "***** 설문이 종료되었습니다. 감사합니다. *****" << endl;
					cout << "**********************************************" << endl;
				}

			} while (finalChk != 0);
		}
		// 입력 값이 0이 아닐 경우 투표
		else {
			/*
				1. 총 투표 수 체크를 한다.
				2. 선택항목 배열 중 입력 값을 받아 해당 index를 기준으로 선택항목을 호출하여,
				3. 현재 값에서 + 1 한 값을 적용한다.
			*/
			survey->setTotalCount(survey->getTotalCount() + 1);
			Selection *s = &selArr[selectNum - 1];
			s->setSelectNum(s->getSelectNum() + 1);
		}

	} while (selectNum != 0);

	return 0;
}

// 숫자를 입력받는 공통 함수
// recursive
/*
	@param string outString
	@description: 숫자를 받을 때 사용할 문자열

	@param int capacity
	@description: 입력받을 숫자의 최대 값

	@return int num
*/
int getNumber(string outString, int capacity) {
	
	int num;
	cout << outString << ": ";
	cin >> num;

	// 잘못된 입력을 받았을 경우
	/*
		1. string
		2. 허용치를 벗어난 int 값, 
			ex) 기대치 3, 입력 값 4
			ex) 기대치 2, 입력 값 -1
	*/
	if (cin.fail() || capacity < num) { //입력 값이 오류이거나 최대 개수보다 많은 수를 입력했을 경우
		if (capacity < num) { //입력 범위가 초과했을 경우 추가 설명을 출력
			cout << "입력 범위를 초과하였습니다. 입력 범위는 [" << capacity << "] 입니다." << endl;
		}
		cout << "숫자를 입력해주세요." << endl; // 사용자의 재입력 유도
		cin.clear(); // 오류스트림을 초기화
		cin.ignore(256, '\n'); // 입력버퍼를 비움
		return getNumber(outString, capacity); // 함수를 재호출한다
	}

	return num;
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
