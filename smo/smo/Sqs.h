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