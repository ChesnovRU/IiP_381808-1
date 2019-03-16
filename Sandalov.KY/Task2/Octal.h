#pragma once
#include <iostream>
#include <string>

using namespace std;
// ���������� ���������, ������� ����� ����� ����������
enum ExType {strNOTOCTA};
struct Exeption
{
	ExType ext;
	int pos;
	Exeption(ExType _ext, int _pos): ext(_ext), pos(_pos) {}
};

class Octal
{
	int size; // ������ ������� ��������� ���� unsigned char
	int lng; // ����������� ����� ������������� �����
	unsigned char* octa; // ��������� �� ������, ��� �������� ������ ���� ������������� �����
public:
	Octal(); // ����������� �� ���������
	Octal(int _size); // ����������� � ���������� �������� ������� 
	Octal(const string& _str); // ����������� �������������� ���� �� ������ 
	Octal(const Octal& _oct); // ����������� �����������
	// ���������� ����������
	Octal& operator= (const Octal& _oct);
	Octal operator+ (const Octal& _oct);
	Octal operator- (const Octal& _oct);
	Octal operator* (const Octal& _oct);
	bool operator== (const Octal& _oct);
	bool operator!= (const Octal& _oct);
	bool operator< (const Octal& _oct);
	bool operator>= (const Octal& _oct);
	bool operator> (const Octal& _oct);
	bool operator<= (const Octal& _oct);
	friend ostream& operator<< (ostream& stream, const Octal& _oct);
	friend istream& operator>> (istream& stream, Octal& _oct);
	// ���������� 
	~Octal();
};