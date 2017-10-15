#ifndef BUFFER_H
#define BUFFER_H

//��� ������� ��������, ����� ��� ���������� ���������� �������� ���� ������� ��� ���������� �����������
//���������� ������ � ����������� bufferPtr �� ��������� ����. ���� ������� �������� ������� ��� req.getGenerationTime() == -1


//����� ������� ������� ��������� + ����������� �����(������ ����� list)
#include <iostream>
#include <list> 
#include <memory>

#include "Request.h"

//������ �������� � ���� �� �� �����
//�������� ��� � ���� �������� ���� �� �����

//������ ������� ��-�� � ������
//����������� ����������
//��� ���������� ���������� � �����
//� ������� � ������

enum state_t {EMPTY, FILLED, FULL};

typedef std::list<Request>::iterator Iterator;
typedef Iterator BufferPtrIter;

class Buffer {
public:
	Buffer() = delete;
	Buffer(int size);

	void setElement(Request req);
	Request getElementWithPrior(int sourceNum);
	void printBuffer();

	bool isEmpty();
	bool isFull();//est' li mesto
	bool isReqPriorThere(int sourceNum);
	Iterator getBufferPtr();//returns bufferPtr
	int getHighestPriority();
	
private:
	std::list<Request> claster;
	int size;
	Iterator bufferPtr;
	void incrementBufPtr(Iterator& bufferPtr);
};

#endif // BUFFER_H
