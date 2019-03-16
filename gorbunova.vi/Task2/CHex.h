#pragma once
#include <iostream>

class Hex
{
public:
	Hex(int _size); // ����������� ������
	Hex(const Hex &obj); // ����������� �����������
	~Hex(); // �����������
	Hex& operator=(const Hex &obj); // �������� ������������

	Hex operator+(const Hex &obj); // �������� ��������
	Hex operator-(const Hex &obj); // �������� ���������
	Hex operator*(const Hex &obj); // �������� ���������

	bool operator==(const Hex &obj); // �������� ���������: ��������� ����� � ���������� ������� ��������� � ���������� �� ����� �����
	bool operator!=(const Hex &obj); // ��������� ��������� ==
	bool operator>=(const Hex &obj); // �������� ���������: ��������� ����� � ���������� ������� ��������� � ���������� �� ����� �����
	bool operator<=(const Hex &obj); // �������� ���������: ��������� ����� � ���������� ������� ��������� � ���������� �� ����� �����
	bool operator>(const Hex &obj); // ��������� ��������� <=
	bool operator<(const Hex &obj); //  ��������� ��������� >=

	friend std::ostream& operator<<(std::ostream &stream, const Hex &obj); 
	friend std::istream& operator>>(std::istream &stream, Hex &obj); 
	
	unsigned char *pmem;
	int size;
};
