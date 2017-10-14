#ifndef SOURCE_H
#define SOURCE_H

//1.Источник
//1.1.Генерирует время появления заявки

#include <cstdlib>
#include <cmath>

#include "Request.h"
//@TODO
//Generator
class Source {
public:
	Source(int lambda, int sourceNumber);
	//generate some req
	Request generate();
private:
	int sourceNumber;
	int generateCounter;
	int lambda;
	float generationTime;
};

#endif // !SOURCE_H


//τ = –1/λ · Ln(r), r - random(0,1);