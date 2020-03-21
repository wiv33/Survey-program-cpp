#ifndef SELECTION_H
#pragma once
#define SELECTION_H
#include <iostream>
#include "IDisplay.h"

using namespace std;
/*
	������ ������ �ش��ϴ� �����׸��� Ŭ����
*/
class Selection: public IDisplay
{
public:
	//�����ڿ��� parameter�� �����׸� title�� �޴´�.
	// Selection ��ü�� setter�� �������� �ʰ� �����ڸ� Ȱ���غ��� ���� ������ �����ε��� �Ͽ����ϴ�.
	Selection(const string title) {
		title_ = title;
	};
	//�⺻ ������
	Selection() {};
	//�⺻ �Ҹ���
	~Selection() {};

	string getTitle() const { //������ title�� ��ȯ
		return title_;
	}
	void setSelectNum(int num) { // �����׸��� ��ǥ�� �� ����� �Լ�
		this->selectNum = num;
	}
	int getSelectNum() const {  // �����׸��� ���� �� ��ȯ
		return this->selectNum;
	}
	void setSecret(bool secret) { // ��ǥ�� ������ ���� ���� Ȯ�εǵ��� ��� ���θ� ����.
									// �� �κ��� ����� ������ �����ϰ� �ֽ��ϴ�.
									// ���� ������ ���Ե� �������� Survey ��ü���� Ȱ�� �߾�� �� ����Դϴ�.
		this->secret = secret;
	}
	bool getSecret() { // ���� ������ ��� ��ǥ ������ ���¸� ��ȯ.
		return this->secret;
	}
	virtual void print() { // IDisplay�� ���� �Լ� ����
		cout << "�����׸� ������ [" + title_ + "] �Դϴ�.";
		if (!this->secret) { // secret�� false���, ���� select �� Number�� �߰��� ����մϴ�.
			cout << "[" << selectNum << "]";
		}
		cout << endl;
	}
private:
	string title_; // �����׸��� title
	int selectNum = 0; // �����׸��� ���õ� ��
	bool secret = true; // ���� ������ �����׸��� ��з� ����Ǵ��� ���� üũ ��.
};
#endif // !SELECTION_H

