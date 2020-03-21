#ifndef SURVEY_H
#define SURVEY_H
#include "Selection.h" // Survey에서 사용할 Selection 객체 include
#include "Question.h" // Survey에서 사용할 Question 객체 include
class Survey
{
public:
	//기본 생성자
	Survey() {};
	//기본 소멸자
	~Survey() {
		//사용한 객체의 참조주소 해제는 소멸자에서 수행
		delete selections;
		delete &question;
	};

	void setQuestion(Question q) { // Question을 설정
		this->question = q;
	}
	void setSelections(Selection* s) { // Selection*를 설정
		this->selections = s;
	}
	Question getQuestion() { // 설정된 Question을 반환
		return this->question;
	}
	Selection* getSelections() { //설정된 Selection*를 반환
		return this->selections;
	}

	void setTotalCount(int totalCount) { // 총 투표 수 설정
		this->totalCount = totalCount;
	}
	int getTotalCount() { // 총 투표 수 반환
		return this->totalCount;
	}
/*	
	// secret 처리는 Survey에서 조절해야 했습니다.
	// 설계 오류입니다.
	void setSecret(bool secret) {
		this->secret = secret;
	}
	bool getSecret() {
		return this->secret;
	}
*/
private:
	//캡슐화
	Question question; //Question 선언
	Selection* selections; // Selection* 선언
	int totalCount = 0; //총 투표 수 체크 값
	//bool secret = false;
};
#endif // !SURVEY_H

#pragma once
