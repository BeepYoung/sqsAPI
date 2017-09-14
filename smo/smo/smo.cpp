#ifndef SMO_H
#define SMO_H

#include <iostream>

#include "Buffer.h"
#include "HoldStrategy.h"

class SimpleStrategy :public HoldStrategy {
public:
	SimpleStrategy() {
		x = 1;
		std::cout << "I'm new strategy.I have var x and x equals " << x << "\n";
	}
	int x;
};

int main() {
	SimpleStrategy* strategy = new SimpleStrategy();
	Buffer* buff = new Buffer((HoldStrategy)(*strategy));

	system("pause");
}

#endif // !SMO_H
