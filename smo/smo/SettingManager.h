#ifndef SETTING_MANAGER_H
#define SETTING_MANAGER_H

#include <iostream>

#include "Request.h"
#include "Buffer.h"

class SettingManager {
public:
	void putElement(Buffer& buffer, Request req);
};

#endif

//������ ������ � �����
// ����� ������ ������������ ����������
//��� ����������� ���������
//���� �� ����� isFull()
//���� ���� �� ������ �� ���������
//���� ��� �� ������ ������ � �������� �����

