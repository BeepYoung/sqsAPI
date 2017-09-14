#ifndef BUFFER_H
#define BUFFER_H

#include <vector>;

#include "HoldStrategy.h"
#include "Request.h"

class Buffer {
public:
	Buffer() = delete;
	Buffer(HoldStrategy& holdStrategy):
	holdStrategy(holdStrategy){
	}
	void setStrategy(HoldStrategy holdStrategy) {
		this->holdStrategy = holdStrategy;
	}
private:
	std::vector<Request> claster;
	HoldStrategy holdStrategy;
};

#endif // BUFFER_H
