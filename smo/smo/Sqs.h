#ifndef SQS_H
#define SQS_H

#include <vector>
#include <iostream>
#include <memory>

#include "Source.h"
#include "Buffer.h"
#include "Device.h"

class Sqs {
public:
	Sqs() = delete;

private:
	std::shared_ptr<Buffer> buffer;
	std::vector<Source> sources;
	std::vector<Device> devices;
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
