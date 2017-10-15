#include "Buffer.h"

Buffer::Buffer(int size)
{
	this->size = size;
	this->bufferPtr = claster.begin();
	for (int i = 0; i < size; i++) {
		claster.push_back(Request());
	}
	bufferPtr = claster.begin();
}

bool Buffer::isEmpty()
{
	return (claster.begin() == claster.end()) ? true : false;
}

bool Buffer::isFull() 
{
	//можно придумать что-то
	// с итератором
	return (claster.size() == size) ? true : false;
}


Request Buffer::getElement() 
{
	return Request(1, std::pair<int, int>(1, 1));
}

void Buffer::printBuffer()
{
	for (Iterator it = claster.begin(); it != claster.end(); it++) {
		std::cout << it->getNumber().first << "\t" << it->getNumber().second << "\t" << it->getGenerationTime() << "\n";
	}
	std::cout << claster.size();
	std::cout << "\n";
}

Iterator& Buffer::operator++() {
	Iterator next = bufferPtr;
	next++;
	if (next == claster.end()) {
		bufferPtr = claster.begin();
		return bufferPtr;
	}
	else {
		return bufferPtr++;
	}
}

Iterator Buffer::operator++(int)
{
	Iterator next = bufferPtr;
	next++;
	if (next == claster.end()) {
		bufferPtr = claster.begin();
		return bufferPtr;
	}
	else {
		return bufferPtr++;
	}
}

