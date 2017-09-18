#ifndef BUFFER_H
#define BUFFER_H

#include <vector>;

#include "HoldStrategy.h"
#include "Request.h"

class Buffer {
public:
	Buffer() = delete;
	Buffer(const HoldStrategy& holdStrategy):
	holdStrategy(holdStrategy){
	}

	virtual void setStrategy(const HoldStrategy holdStrategy) final {
		this->holdStrategy = holdStrategy;
	}
	virtual std::vector<Request>& getClaster() final{
		return claster;
	}

	virtual void putElement(Request& request) = 0;
	virtual Request& digElement() = 0;
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	virtual void processRequest(Request& request) = 0;
	
private:
	std::vector<Request> claster;
	HoldStrategy holdStrategy;
};

#endif // BUFFER_H
