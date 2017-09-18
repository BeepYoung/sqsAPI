#ifndef BUFFER_H
#define BUFFER_H

#include <vector>;
#include <memory>

#include "Request.h"

class Buffer {
public:
	Buffer() = delete;

	virtual Request getElement() = 0;
	virtual bool putElement(Request request) = 0;

	virtual bool isEmpty() final;
	virtual bool isFull() final;
	

private:
	std::vector<Request> claster;
	int size;
};

#endif // BUFFER_H
