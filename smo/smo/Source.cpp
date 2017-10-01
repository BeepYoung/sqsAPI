#include "Source.h"

//τ = –1/λ · Ln(r), r - random(0,1);

Request Source::generate() {
	float lambda = 1;
	int tau;
	float randInt = (rand() % 99 + 1)/100;
	tau = -1 / lambda*log(randInt);
	
}