#ifndef SETTING_MANAGER_H
#define SETTING_MANAGER_H

#include <iostream>

#include "Request.h"
#include "Buffer.h"

class SettingManager {
public:
	void sendRequest(Buffer& buffer);
	void putElement(Iterator it);
};

#endif

//������ ������ � �����
// ����� ������ ������������ ����������
//��� ����������� ���������
//���� �� ����� isFull()
//���� ���� �� ������ �� ���������
//���� ��� �� ������ ������ � �������� �����