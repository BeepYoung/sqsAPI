#ifndef DEVICE_H
#define DEVICE_H

#include "Request.h"

class Device {
public:
	virtual void process(Request) = 0;
};

#endif