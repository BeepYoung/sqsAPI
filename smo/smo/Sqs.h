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

//время пребывания заявки в системе
//время обработки - время генерации
//или же время пребывания в буфепе если отказ
//время пребывания заявки в буфере
//	Если будет отказ, то время
//генерации следующей заявки - время ген. этой
//	Если попадет на прибор, то время окончания 
//работы прибора - время генерации заявки

//ВВЕСТИ COUNTER ЗАЯВОК СГЕНЕРИРОВАННЫХ ВСЕМИ ИСТОЧНИКАИИ