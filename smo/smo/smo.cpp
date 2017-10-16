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
#include "GettingManager.h"

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

	Sqs sqs(5, 5, 1, 10);
	sqs.work();


	//�� ���������� ����� �� ���� src, ����� ������� ����� �� ��� ���������� ����� ���������
	//����� ��� � ���������(�������� ������ � ����� ��������), ������� �� ��� �� ����� t
	//����� ������� ����� ��������� � �.�.
	//��� ������ ��������� ���������� � �����
	
	// ������ ������ ��� �������� ��������� ����� ������. � ����� ������ ������������
	//��������� �������� �� ���� �� ������:
	//		1.��������� ��������� � �����
	//		2.��������� ������ �� ������
	//		

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
