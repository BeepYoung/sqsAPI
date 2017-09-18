#ifndef DEVICE_H
#define DEVICE_H

#include "Request.h"

class Device {
public:
	virtual float process(Request) = 0;
private:
	
};

#endif