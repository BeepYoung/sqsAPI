#ifndef DEVICE_H
#define DEVICE_H

#include "Request.h"

class Device {
public:
	virtual float process(Request);
private:
	float vacationTime;
};

#endif

//(random/rand_max)*(b-a)+a