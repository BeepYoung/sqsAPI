#include "GettingManager.h"

//GettingManager::GettingManager(DeviceContainer& devices, Buffer buffer, int sourceCount) {
//	this->currSourcePriority = findCurrSourcePriority(devices);
//	this->currDeviceNum = firstAvailableDeviceNum(devices);
//	this->sourceCount = sourceCount;
//}

void GettingManager::getRequest(DeviceContainer& devices, Buffer& buffer, int sourceNum) {

	currDeviceNum = firstAvailableDeviceNum(devices);
	//std::cout << "vac time dev  " << devices.at(currDeviceNum).getVacationTime() << "\tgenTime  " << buffer.getBufferPtr()->getGenerationTime() << "\n";
	//buffer.printBuffer();

		devices.at(currDeviceNum).process(buffer.getElement());
	
}




int GettingManager::firstAvailableDeviceNum(DeviceContainer devices) {
	DeviceContainer::iterator wanted = devices.begin();
	for (DeviceContainer::iterator it = devices.begin(); it != devices.end(); it++) {
		if (it->getVacationTime() < wanted->getVacationTime()) {
			wanted = it;
		}
//		std::cout << "firstAvailableDeviceNum :" << wanted->getDeviceNumber() << "\n";
	}
	
	return wanted->getDeviceNumber();
}

//int GettingManager::findCurrSourcePriority(DeviceContainer devices, int currPrior) {
//	DeviceContainer::iterator wanted = devices.begin();
//	for (DeviceContainer::iterator it = devices.begin(); it != devices.end(); it++) {
//		if ((it->getCurrentSourceNum() < wanted->getCurrentSourceNum())&&!(it->isFree())) {
//			if (currPrior == -1) {
//				wanted = it;
//			}
//			else {
//				if (it->getCurrentSourceNum() > currPrior) {
//					wanted = it;
//				}
//			}
//		}
//	}
//	return (wanted->getCurrentSourceNum() != -1) ? wanted->getCurrentSourceNum() : 1;
//}

//bool GettingManager::isPriorityInBuffer(Buffer& buffer, int priority) {
//	return buffer.isReqPriorThere(priority);
//}


