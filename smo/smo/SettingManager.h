#ifndef SETTING_MANAGER_H
#define SETTING_MANAGER_H

#include <iostream>

#include "Request.h"
#include "Buffer.h"

class SettingManager {
public:
	virtual void sendRequest(Buffer& buffer) = 0;
};

#endif