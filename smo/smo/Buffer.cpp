#include "Buffer.h"

Buffer::Buffer(int size, int sourceNum)
{
	this->size = size;
	this->currPackPriority = 1;
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

bool Buffer::isReqPriorThere(int sourceNum) {
	Iterator it = bufferPtr;
	for (int i = 0; i < size; i++) {
		if (it->getSourceNum() == sourceNum) {
			return true;
		}
		incrementBufPtr(it);
	}
	return false;
}

bool Buffer::isPackFinished() {
	return packIndexes.size() == 0;
}

Request Buffer::getElementWithPrior(int sourceNum)
{
	for (int i = 0; i < size; i++) {
		if (bufferPtr->getSourceNum() == sourceNum) {
			Request wantedReq = bufferPtr->getRequest();
			bufferPtr->setFake();
			incrementBufPtr(bufferPtr);
			return wantedReq;
		}
		incrementBufPtr(bufferPtr);
	}
//	printBuffer();
}

void Buffer::printBuffer()
{
	for (Iterator it = claster.begin(); it != claster.end(); it++) {
		std::cout << it->getNumber().first << "\t" << it->getNumber().second << "\t" << it->getGenerationTime() << "\n";
	}
//	std::cout << claster.size();
	std::cout << "\n";
}

void Buffer::generatePack() {
	currPackPriority = getHighestPriority();
	for (Iterator it = claster.begin(); it != claster.end(); it++) {
		if (it->getSourceNum() == currPackPriority) {
			packIndexes.push_back(it);
		}
	}
}

Iterator Buffer::getBufferPtr() {
	return bufferPtr;
}

void Buffer::incrementBufPtr(Iterator& bufferPtr)
{
	Iterator next = bufferPtr;
	next++;
	if (next == claster.end()){
		bufferPtr = claster.begin();
	}
	else {
		bufferPtr++;
	}
}

void Buffer::setElement(Request req) {
	std::cout << "Request seted: srcNum  " << req.getSourceNum() << "\t reqNum" << req.getRequestNum() << "\t genTime " << req.getGenerationTime() << "\n";
	for (int i = 0; i < size; i++) {
		if (bufferPtr->isFake()) {
			*bufferPtr = req;
			incrementBufPtr(bufferPtr);
			return;
		}
		incrementBufPtr(bufferPtr);
	}
	std::cout << "KICKED: srcNum  " << bufferPtr->getSourceNum() << "\t reqNum" << bufferPtr->getRequestNum() << "\t genTime " << bufferPtr->getGenerationTime() << "\n";
	*bufferPtr = req;
	incrementBufPtr(bufferPtr);
}

int Buffer::getHighestPriority() {
	int x = bufferPtr->getSourceNum();
	for (Iterator it = claster.begin(); it != claster.end(); it++) {
		if (it->getSourceNum() < x) {
			x = it->getSourceNum();
		}
	}
	return x;
}