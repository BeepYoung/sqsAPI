#ifndef BUFFER_H
#define BUFFER_H

#include <vector>;//Нужно выбрать удобный контейнер + реализовать буфер
#include <list>
#include <memory>

#include "Request.h"

class Buffer {
public:
	Buffer() = delete;
	Buffer(int size);

	Request getElement();
	bool putElement(Request request);

	bool isEmpty();
	bool isFull();
	

private:
	std::list<Request> claster;
	int size;
	int bufferPtr;
};

#endif // BUFFER_H
