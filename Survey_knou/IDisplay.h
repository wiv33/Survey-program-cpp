#pragma once
//객체가 없으면 선언
#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <string>
using namespace std; 

/*
	Question, Selection은 출력 기능을 가지고 있다.
*/
class IDisplay {
public:
	/*
		기본 생성자와 소멸자.
		interface의 의미로 구현체가 없어야 맞다.
	*/
	IDisplay() {}
	~IDisplay(){}

	// 기본 출력 함수 // 하위 클래스에서 별도 오버라이딩을 한다.
	virtual void print() { cout << "Hello World" << endl; };
};

#endif // !DISPLAY_H

