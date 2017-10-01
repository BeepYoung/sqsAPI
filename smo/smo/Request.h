#ifndef REQUEST_H
#define REQUEST_H

#include <utility>
#include <iostream>

typedef int SourceNum;
typedef int RequestNum;

class Request {
public:
	Request() = delete;
	Request(float genTime,std::pair<int,int> number);
	Request(Request& req);
	Request getRequest();
	float getGenerationTime();
	std::pair<SourceNum, RequestNum> getNumber();
private:
	float generationTime;
	std::pair<SourceNum, RequestNum> number;
};

#endif // !REQUEST_H
