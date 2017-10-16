#ifndef BUFFER_H
#define BUFFER_H

//��� ������� ��������, ����� ��� ���������� ���������� �������� ���� ������� ��� ���������� �����������
//���������� ������ � ����������� bufferPtr �� ��������� ����. ���� ������� �������� ������� ��� req.getGenerationTime() == -1


//����� ������� ������� ��������� + ����������� �����(������ ����� list)
#include <iostream>
#include <list> 
#include <vector>
#include <memory>

#include "Request.h"

//������ �������� � ���� �� �� �����
//�������� ��� � ���� �������� ���� �� �����

//������ ������� ��-�� � ������
//����������� ����������
//��� ���������� ���������� � �����
//� ������� � ������

enum state_t {EMPTY, FILLED, FULL};

typedef std::vector<Request>::iterator Iterator;
typedef Iterator BufferPtrIter;

class Buffer {
public:
	Buffer() = delete;
	Buffer(int size,int sourceNum);

	void setElement(Request req);
	Request getElement();
	/*Request getElementWithPrior(int sourceNum);*/
	void printBuffer();

	/*bool isReqPriorThere(int sourceNum);*/
	bool isPackFinished();
	Iterator getBufferPtr();//returns bufferPtr
	int getHighestPriority();
	void generatePack();
	
private:
	std::vector<Request> claster;
	std::vector<int> packIndexes;
	int size;
	Iterator bufferPtr;
	void incrementBufPtr(Iterator& bufferPtr);
	int currPackPriority;
	int sourceNum;
	//bool isInPack(int Index);
};

#endif // BUFFER_H
