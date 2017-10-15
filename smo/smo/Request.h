#ifndef REQUEST_H
#define REQUEST_H

#define SOURCE_NUM first
#define REQUEST_NUM second

#include <utility>
#include <iostream>

typedef int SourceNum;
typedef int RequestNum;

class Request {
public:
//	Request() = delete;
	Request(); //fake request
	Request(float genTime,std::pair<int,int> number);
	Request(Request& req);
	Request getRequest();
	float getGenerationTime();
	std::pair<SourceNum, RequestNum> getNumber();
	int getSourceNum();
	int getRequestNum();
	void setFake();
	bool isFake();
private:
	float generationTime;
	std::pair<SourceNum, RequestNum> number;
};

#endif // !REQUEST_H
