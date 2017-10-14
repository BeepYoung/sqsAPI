#ifndef BUFFER_H
#define BUFFER_H

//при выборке элемента, после его извлечения необходимо вставить фейк реквест для сохранения целостности
//кольцевого буфера и переместить bufferPtr на следующий слот. Фейк реквест является таковым при req.getGenerationTime() == -1


//Нужно выбрать удобный контейнер + реализовать буфер(скорее всего list)
#include <list> 
#include <memory>

#include "Request.h"

//КЛАСТЬ ЭЛЕМЕНТЫ В СЕБЯ ОН НЕ УМЕЕТ
//ЗАБИРАТЬ САМ У СЕБЯ ЭЛЕМЕНТЫ ТОЖЕ НЕ УМЕЕТ

//Должен хранить эл-ты и давать
//необходимый функционал
//для менеджеров постановки в буфер
//и выборки с буфера

enum state_t {EMPTY, FILLED, FULL};

typedef std::list<Request>::iterator Iterator;

class Buffer {
public:
	Buffer() = delete;
	Buffer(int size);

	Request getElement();


	bool isEmpty();
	bool isFull();//est' li mesto
	Iterator getCurrentPtr();//@returns current iterator
	Iterator getBufferPtr();//returns bufferPtr

private:
	std::list<Request> claster;
	int size;
	Iterator bufferPtr;
};

#endif // BUFFER_H
