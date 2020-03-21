#ifndef SURVEY_H
#define SURVEY_H
#include "Selection.h" // Survey���� ����� Selection ��ü include
#include "Question.h" // Survey���� ����� Question ��ü include
class Survey
{
public:
	//�⺻ ������
	Survey() {};
	//�⺻ �Ҹ���
	~Survey() {
		//����� ��ü�� �����ּ� ������ �Ҹ��ڿ��� ����
		delete selections;
		delete &question;
	};

	void setQuestion(Question q) { // Question�� ����
		this->question = q;
	}
	void setSelections(Selection* s) { // Selection*�� ����
		this->selections = s;
	}
	Question getQuestion() { // ������ Question�� ��ȯ
		return this->question;
	}
	Selection* getSelections() { //������ Selection*�� ��ȯ
		return this->selections;
	}

	void setTotalCount(int totalCount) { // �� ��ǥ �� ����
		this->totalCount = totalCount;
	}
	int getTotalCount() { // �� ��ǥ �� ��ȯ
		return this->totalCount;
	}
/*	
	// secret ó���� Survey���� �����ؾ� �߽��ϴ�.
	// ���� �����Դϴ�.
	void setSecret(bool secret) {
		this->secret = secret;
	}
	bool getSecret() {
		return this->secret;
	}
*/
private:
	//ĸ��ȭ
	Question question; //Question ����
	Selection* selections; // Selection* ����
	int totalCount = 0; //�� ��ǥ �� üũ ��
	//bool secret = false;
};
#endif // !SURVEY_H

#pragma once
