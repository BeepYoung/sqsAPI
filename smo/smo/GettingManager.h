#ifndef GETTING_MANAGER_H
#define GETTING_MANAGER_H

#include<iostream>
#include<memory>
#include<vector>

#include "Buffer.h"
#include "Request.h"
#include "Device.h"
//����� �������� ���� ��������

typedef std::vector<Device> DeviceContainer;

class GettingManager {
public:
	//GettingManager(DeviceContainer& devices, Buffer buffer,int sourceCount);
	void getRequest(DeviceContainer& devices,Buffer& buffer, int sourceNum);
private:
	int firstAvailableDeviceNum(DeviceContainer devices);
//	int findCurrSourcePriority(DeviceContainer devices,int currPrior = -1);
//	bool isPriorityInBuffer(Buffer& buffer, int priority);
	int currDeviceNum;
//	int currSourcePriority;
	int sourceCount;
};

#endif

//������ �������� ������ �� ������� 
//������� �� ������
//������ � ����� ������ ����������� 
//����������� ����������

//������:
//����� ��������� ���������
//������:
//����� ��������� ���������

//������� ��������� ��������� �� ������ ������
//��������� ���� � � ������ ������ �� �������
//���������. ��� �� ��� ��� ���� �� �������
//������ ������.
//
//� ������ ����������� ����� ������ � �������:
//������� ���� �� ��������� ������:
//���� ���� , �� �� ���������� ��������� ������������� ������
//�������� ������ � ������
//���� ������ � ����� ����������� ������ ���, �� ����� ��������� �� ���������� � ������
//
//p.s. ������ ���������� �� ���������� ������ 
//�������
