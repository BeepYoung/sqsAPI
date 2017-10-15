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

class Buffer {
public:
	Buffer() = delete;
	Buffer(int size);

	void setElement(Request req);
	Request getElement();
	void printBuffer();

	bool isEmpty();
	bool isFull();//est' li mesto
	Iterator getCurrentPtr();//@returns current iterator
	Iterator getBufferPtr();//returns bufferPtr

	Iterator& operator++();// prefix increment (++it)
	Iterator operator++(int);  // postfix increment (it++)
private:
	std::list<Request> claster;
	int size;
	Iterator bufferPtr;
};

#endif // BUFFER_H
