#include "Buffer.h"

Buffer::Buffer(int size) {
	this->size = size;
	claster.resize(size);
	this->bufferPtr = claster.begin();
}

bool Buffer::isEmpty() {
	return (claster.begin() == claster.end()) ? true : false;
}

bool Buffer::isFull() {
	//можно придумать что-то
	// с итератором
	return (claster.size() == size) ? true : false;
}


Request Buffer::getElement() {
	return Request(1, std::pair<int, int>(1, 1));
}
