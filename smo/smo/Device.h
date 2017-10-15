#ifndef DEVICE_H
#define DEVICE_H

#include <cstdlib>
#include <cmath>

#include "Request.h"

class Device {
public:
	Device(int a, int b,int deviceNumber);
	void process(Request);
	float getVacationTime();
	int getDeviceNumber();
	int getCurrentSourceNum();
	bool isFree();
private:
	float vacationTime;
	int a, b;
	int deviceNumber;
	Request currentRequest;
};

#endif

//(random/rand_max)*(b-a)+a