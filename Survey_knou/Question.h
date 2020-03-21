#pragma once
#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
#include <string>
#include "IDisplay.h"
using namespace std;

/*
	설문지의 질문 클래스
*/
class Question :public IDisplay{

public:
	Question() {} // 기본 생성자
	~Question() { //기본 소멸자
		//cout << "Question 소멸자" << endl;
	};

	Question(const string n) { // 오버로딩 생성자
		//cout << "Question 생성자" << endl;
		title = n;
	};

	const string getTitle() const { // Question의 title을 반환
		return title;
	}

	void setTitle(string title) { // Question의 title을 적용
		this->title = title;
	}

	virtual void print() { // IDisplay의 가상 메서드 구현
		cout << "질문은 [" << title << "]입니다." << endl;
	}

private:
	string title; //질문의  title
};

#endif // !QUESTION_H