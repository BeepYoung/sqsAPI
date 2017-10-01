#include "Buffer.h"

Buffer::Buffer(int size) {
	this->size = size;
	bufferPtr = 0;
}

bool Buffer::isEmpty() {
	return (claster.begin() == claster.end()) ? true : false;
}

bool Buffer::isFull() {
	return (claster.size() == size) ? true : false;
}

