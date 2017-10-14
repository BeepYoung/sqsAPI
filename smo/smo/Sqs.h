#ifndef SQS_H
#define SQS_H

#include <vector>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <cmath>

#include "Source.h"
#include "Buffer.h"
#include "Device.h"
#include "SettingManager.h"

class Sqs {
public:
	Sqs() = delete;
	Sqs(int sourceCounter, int bufferSize, int deviceCounter, int requestCount);
	void work();


private:
	Buffer buffer;
	std::vector<Source> sources;
	std::vector<Device> devices;
	int requestCount;
	int sourceCounter;
	int bufferSize; 
	int deviceCounter;

	int earliestSourceNumber(std::vector<Source> sources);
};

#endif

//����� ���������� ������ � �������
//����� ��������� - ����� ���������
//��� �� ����� ���������� � ������ ���� �����
//����� ���������� ������ � ������
//	���� ����� �����, �� �����
//��������� ��������� ������ - ����� ���. ����
//	���� ������� �� ������, �� ����� ��������� 
//������ ������� - ����� ��������� ������

//������ COUNTER ������ ��������������� ����� �����������