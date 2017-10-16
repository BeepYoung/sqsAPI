#ifndef GETTING_MANAGER_H
#define GETTING_MANAGER_H

#include<iostream>
#include<memory>
#include<vector>

#include "Buffer.h"
#include "Request.h"
#include "Device.h"
//много девайсов один менеджер

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

//должен выбирать заявку на которую 
//выбрать на прибор
//прибор и буфер должны предосавить 
//необходимый функционал

//прибор:
//какой приоритет источника
//буффер:
//какой приоритет источника

//смотрим приоритет источника на данный момент
//проверяем есть и в буфере заявки от данного
//источника. Так до тех пор пока не выберем
//нужную заявку.
//
//В момент поступления новой заявки в систему:
//смотрим есть ли свободный прибор:
//если есть , то по приоритету последней обслужившейся заявки
//выбираем заявку с буфера
//если заявок с таким приоритетом больше нет, то берем следующую по приоритету с буфера
//
//p.s. девайс выбирается по приоритету номера 
//девайса
