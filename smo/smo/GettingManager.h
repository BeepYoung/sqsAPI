#ifndef GETTING_MANAGER_H
#define GETTING_MANAGER_H

#include "Buffer.h"
#include "Request.h"

class GettingManagerP {
public:
	virtual Request getRequest(Buffer& buffer) = 0;

};

#endif