#ifndef SOURCE_H
#define SOUTCE_H

#include "Request.h"

class Source {
public:
	virtual Request generate() = 0;
};

#endif // !SOURCE_H
