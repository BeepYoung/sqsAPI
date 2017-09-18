#ifndef GETTING_MANAGER_H
#define GETTING_MANAGER_H

#include "Buffer.h"

class GettingManagerP {
public:
	virtual void chooseDevice() = 0;
	virtual void chooseRequest(Buffer& buffer) = 0;

};

#endif