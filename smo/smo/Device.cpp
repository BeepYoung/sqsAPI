#include "Device.h"

//(random/rand_max)*(b-a)+a


Device::Device(int a, int b, int deviceNumber) {
	this->a = a;
	this->b = b;
	this->deviceNumber = deviceNumber;
	vacationTime = 0;
	currentRequest = Request();
	std::cout << "a " << a << "\tb " << b << "\n";
}

void Device::process(Request req) {
	this->currentRequest = req;
	float randInt = (float)(rand() % 99 + 1.0) / (float)100.0;
	vacationTime += float(randInt*(float(b-a))+ float(a));
	std::cout << "devNum: " <<deviceNumber << "\t" <<"srcNum:"<<currentRequest.getSourceNum()<<"\tvac time   "<< vacationTime << "\n";
}

float Device::getVacationTime() {
	return vacationTime;
}

int Device::getDeviceNumber() {
	return deviceNumber;
}

int Device::getCurrentSourceNum() {
	return currentRequest.getSourceNum();
}

bool Device::isFree() {
	return currentRequest.isFake();
}