#include "GettingManager.h"

//GettingManager::GettingManager(DeviceContainer& devices, Buffer buffer, int sourceCount) {
//	this->currSourcePriority = findCurrSourcePriority(devices);
//	this->currDeviceNum = firstAvailableDeviceNum(devices);
//	this->sourceCount = sourceCount;
//}

void GettingManager::getRequest(DeviceContainer& devices, Buffer& buffer, int sourceNum) {

	currSourcePriority = findCurrSourcePriority(devices);
	currDeviceNum = firstAvailableDeviceNum(devices);
	//проверка на синхронизацию времени
	if (devices.at(currDeviceNum).getVacationTime() < buffer.getBufferPtr()->getGenerationTime()) {
		
		for (int i = 0; i < devices.size(); i++) {
			if (isPriorityInBuffer(buffer, currSourcePriority)) {
				devices.at(currDeviceNum).process(buffer.getElementWithPrior(currSourcePriority));
		//		std::cout <<"currsource prior  "<< currSourcePriority << "\n";
				return;
			}
			currSourcePriority = findCurrSourcePriority(devices, currSourcePriority);
		}

		currSourcePriority = buffer.getHighestPriority();
	//	std::cout << "currsource prior  " << currSourcePriority << "\n";
		devices.at(currDeviceNum).process(buffer.getElementWithPrior(currSourcePriority));
	}
	else {
		return;
	}

	

	
}




int GettingManager::firstAvailableDeviceNum(DeviceContainer devices) {
	DeviceContainer::iterator wanted = devices.begin();
	for (DeviceContainer::iterator it = devices.begin(); it != devices.end(); it++) {
		if (it->getVacationTime() < wanted->getVacationTime()) {
			wanted = it;
		}
		std::cout << "firstAvailableDeviceNum :" << wanted->getDeviceNumber() << "\n";
	}
	
	return wanted->getDeviceNumber();
}

int GettingManager::findCurrSourcePriority(DeviceContainer devices, int currPrior) {
	DeviceContainer::iterator wanted = devices.begin();
	for (DeviceContainer::iterator it = devices.begin(); it != devices.end(); it++) {
		if ((it->getCurrentSourceNum() < wanted->getCurrentSourceNum())&&!(it->isFree())) {
			if (currPrior == -1) {
				wanted = it;
			}
			else {
				if (it->getCurrentSourceNum() > currPrior) {
					wanted = it;
				}
			}
		}
	}
	return (wanted->getCurrentSourceNum() != -1) ? wanted->getCurrentSourceNum() : 1;
}

bool GettingManager::isPriorityInBuffer(Buffer& buffer, int priority) {
	return buffer.isReqPriorThere(priority);
}

