#ifndef CIRCLE_BUFF_H
#define CIRCLE_BUFF_H

#include "Buffer.h"
#include "Request.h"

class CircleBuffer :public Buffer {
public:

	Request getElement();
	bool putElement(Request request);

};

#endif