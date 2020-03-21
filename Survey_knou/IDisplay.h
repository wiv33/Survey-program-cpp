#pragma once
//��ü�� ������ ����
#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <string>
using namespace std; 

/*
	Question, Selection�� ��� ����� ������ �ִ�.
*/
class IDisplay {
public:
	/*
		�⺻ �����ڿ� �Ҹ���.
		interface�� �ǹ̷� ����ü�� ����� �´�.
	*/
	IDisplay() {}
	~IDisplay(){}

	// �⺻ ��� �Լ� // ���� Ŭ�������� ���� �������̵��� �Ѵ�.
	virtual void print() { cout << "Hello World" << endl; };
};

#endif // !DISPLAY_H

