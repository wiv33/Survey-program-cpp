#ifndef SELECTION_H
#pragma once
#define SELECTION_H
#include <iostream>
#include "IDisplay.h"

using namespace std;
/*
	설문지 질문에 해당하는 선택항목의 클래스
*/
class Selection: public IDisplay
{
public:
	//생성자에서 parameter로 선택항목 title을 받는다.
	// Selection 객체는 setter를 생성하지 않고 생성자를 활용해보기 위해 생성자 오버로딩을 하였습니다.
	Selection(const string title) {
		title_ = title;
	};
	//기본 생성자
	Selection() {};
	//기본 소멸자
	~Selection() {};

	string getTitle() const { //설정된 title을 반환
		return title_;
	}
	void setSelectNum(int num) { // 선택항목이 투표될 때 사용할 함수
		this->selectNum = num;
	}
	int getSelectNum() const {  // 선택항목의 현재 값 반환
		return this->selectNum;
	}
	void setSecret(bool secret) { // 투표할 때마다 증가 값이 확인되도록 비밀 여부를 설정.
									// 이 부분은 설계상 오류로 생각하고 있습니다.
									// 설문 행위에 포함된 내용으로 Survey 객체에서 활용 했어야 할 기능입니다.
		this->secret = secret;
	}
	bool getSecret() { // 현재 설정된 비밀 투표 여부의 상태를 반환.
		return this->secret;
	}
	virtual void print() { // IDisplay의 가상 함수 구현
		cout << "선택항목 제목은 [" + title_ + "] 입니다.";
		if (!this->secret) { // secret이 false라면, 현재 select 된 Number를 추가로 출력합니다.
			cout << "[" << selectNum << "]";
		}
		cout << endl;
	}
private:
	string title_; // 선택항목의 title
	int selectNum = 0; // 선택항목의 선택된 수
	bool secret = true; // 현재 설문의 선택항목이 비밀로 진행되는지 여부 체크 값.
};
#endif // !SELECTION_H

