#include "Buffer.h"

bool Buffer::isEmpty() {
	return (claster.begin() == claster.end()) ? true : false;
}

bool Buffer::isFull() {
	return (claster.size() == size) ? true : false;
}