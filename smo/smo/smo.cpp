#ifndef SMO_H
#define SMO_H

//�� � ��������� ���������� ������ � �������.
//
//�� � ��������� ������ ������ �� �������.
//�� � ��������� ����������, ��������� ��� ������ :
//
//-���������� ������ �� ������������ ��� � �������� ������ � ������ ���������� ��������� ��������;
//
//-���������� ����� ��� ��������� ������ �� ��, ���� � ������ �� �������� ��������� ����.
//
//�� � ��������� ������, ��������� ��� ������ :
//
//-�������� ������, �� ������� ����������� ������;
//
//-�������� ������ �� ��, ���� ��� ��� ����.
//
//5. �� ��1 ��2 �10�1 �10�1 �2�1 �2�5 ��1 ��2
//
//1.�������� ����������� N
//2.������������� ��� �����������
//3.����� ������������ �����������
//4.���������� �����������.�1��1 � �� ������; K
//�2�1 �2�5 ��1 ��2
//5.�1��1 � ����� ��� ����������.
//6.�2�1 � ��������� �� ������ �������.
//7.�2�5 � ��������� �� ������ ���������, ������ � ������.
//8.��1 � ������� ������� �����������; 3.2.��������� �����������
//����� ����� ���������� ��1 - ��2(�������������� �����).
//7.��2 � ��������������� ����� ������, ������� ���������;
//������������ ��������� �����������


#include <iostream>
#include <string>
#include <memory>
#include <utility>

//#include "Buffer.h"
#include "Sqs.h"
#include "Request.h"
#include "Source.h"

template<typename T>
void printVector(std::vector<T> data) {
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << data.at(i) << "\n";
	}
}

template<typename T>
void printVector2(std::vector<T> data, std::vector<T> data1) {
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << data.at(i) << "\t" << data1.at(i) << "\n";
	}
}

void printVector3(std::vector<Request> data, std::vector<Request> data1) {
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << data.at(i).getGenerationTime() << "\t\t" << data1.at(i).getGenerationTime() << "\n";
	}
}

int main() {
	std::shared_ptr<Source> src(new Source(14, 14));
	std::pair<int, int> somePair;

	//Request req (float(15.1), std::pair<int, int>(3, 15));
	typedef std::shared_ptr<Source> Source_t;

	std::vector<Source_t> sources;
	for (int i = 0; i < 15; i++) {
		sources.push_back(Source_t(new Source(rand() % 5, i)));
	}
	
	Source_t src1(new Source(1, 1));// ������ = 1
	Source_t src2(new Source(50, 2));//lyambda = 50
	std::vector<Request> rec1;
	std::vector<Request> rec2;

	
	//�� ���������� ����� �� ���� src, ����� ������� ����� �� ��� ���������� ����� ���������
	//����� ��� � ���������(�������� ������ � ����� ��������), ������� �� ��� �� ����� t
	//����� ������� ����� ��������� � �.�. ��������� ���
	//��� ������ ��������� ���������� � �����
	
	// ������ ������ ��� �������� ��������� ����� ������. � ����� ������ ������������
	//��������� �������� �� ���� �� ������:
	//		1.��������� ��������� � �����
	//		2.��������� ������ �� ������
	//		
	//
	//
	//
	//
	//
	//
	for (int i = 0; i < 50; i++) {

		rec1.push_back(src1->generate());
		rec2.push_back(src2->generate());
	}

	printVector3(rec1, rec2);

//	std::cout << req.getGenerationTime() << "\t" << req.getNumber().first << "\t" << req.getNumber().second << "\n";
	/*for (int i = 0; i < 50; i++) {
		Request req = src->generate();
		std::cout << req.getGenerationTime() << "\t" << req.getNumber().first << "\t" << req.getNumber().second << "\n";
	}
*/
	if (FULL == 1) {
		std::cout << "Yes\n";
	}
	else {
		std::cout << FULL<<"\n";
	}

	std::cout << "Hey!\n";
	system("pause");
}

#endif // !SMO_H

//=================================TECH
//1.��������
//1.1.���������� ����� ��������� ������
//2.�����
//2.1.������ ���� ��� ����� ������
//2.2.����� ?
//2.3.���� ?
//2.4.�������� / ������ ��������
//3.������ ������������ ������
//3.1.���������� ����� ������������ �������
//
//4.��������� ������������ ������(�� ���� � ����� �� ������)
//4.1.��������� ������
//4.1.1.����� ������ � �����
//4.2.��������� �������
//4.2.1.�������� ������ �� ������
//
//5.������ ����� ����� ������
