#include "Source.h"

//τ = –1/λ · Ln(r), r - random(0,1);

Source::Source(int lambda, int sourceNumber) {
	this->lambda = lambda;
	this->sourceNumber = sourceNumber;
	generateCounter = 0;
	generationTime = 0;
}

Request Source::generate() {
	
	float randInt = (float)(rand() % 99 + 1)/100.0;
	generationTime += float(-1.0 / lambda*log(randInt));
	//generationTime += lambda * randInt;
	generateCounter++;
	return Request(generationTime,std::pair<int,int>(sourceNumber,generateCounter));
}