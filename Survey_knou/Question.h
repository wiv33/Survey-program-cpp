#pragma once
#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
#include <string>
#include "IDisplay.h"
using namespace std;

/*
	�������� ���� Ŭ����
*/
class Question :public IDisplay{

public:
	Question() {} // �⺻ ������
	~Question() { //�⺻ �Ҹ���
		//cout << "Question �Ҹ���" << endl;
	};

	Question(const string n) { // �����ε� ������
		//cout << "Question ������" << endl;
		title = n;
	};

	const string getTitle() const { // Question�� title�� ��ȯ
		return title;
	}

	void setTitle(string title) { // Question�� title�� ����
		this->title = title;
	}

	virtual void print() { // IDisplay�� ���� �޼��� ����
		cout << "������ [" << title << "]�Դϴ�." << endl;
	}

private:
	string title; //������  title
};

#endif // !QUESTION_H