#ifndef BUFFER_H
#define BUFFER_H

//при выборке элемента, после его извлечения необходимо вставить фейк реквест для сохранения целостности
//кольцевого буфера и переместить bufferPtr на следующий слот. Фейк реквест является таковым при req.getGenerationTime() == -1


#include <vector>;//Нужно выбрать удобный контейнер + реализовать буфер(скорее всего list)
#include <list> 
#include <memory>

#include "Request.h"

class Buffer {
public:
	Buffer() = delete;
	Buffer(int size);

	Request getElement();
	bool putElement(Request request);

	bool isEmpty();
	bool isFull();
	

private:
	std::list<Request> claster;
	int size;
	int bufferPtr;
};

#endif // BUFFER_H
