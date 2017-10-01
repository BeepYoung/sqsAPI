#ifndef SOURCE_H
#define SOUTCE_H

//1.Источник
//1.1.Генерирует время появления заявки

#include <cstdlib>
#include <cmath>

#include "Request.h"

class Source {
public:
	virtual Request generate();
private:
	int lambda;
};

#endif // !SOURCE_H


//τ = –1/λ · Ln(r), r - random(0,1);