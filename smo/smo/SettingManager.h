#ifndef SETTING_MANAGER_H
#define SETTING_MANAGER_H

#include <iostream>

#include "Request.h"

class SettingManager {
public:
	virtual void sendRequest() = 0; //includes decline
	virtual void doSomething(int x) = 0;
};

#endif