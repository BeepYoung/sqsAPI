#include "Request.h"

Request::Request() {
	generationTime = -1;
	number.first = -1;
	number.second = -1;
}

Request::Request(float genTime, std::pair<int, int> number) {
	this->generationTime = genTime;
	this->number = number;
}

Request Request::getRequest() {
	return *this;
}

Request::Request(Request& req) {
	generationTime = req.getGenerationTime();
	number = req.getNumber();
}

float Request::getGenerationTime() {
	return generationTime;
}

std::pair<SourceNum, RequestNum> Request::getNumber() {
	return number;
}

