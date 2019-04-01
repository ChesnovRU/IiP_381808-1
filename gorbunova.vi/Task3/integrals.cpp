#include "integrals.h"
#include <string>
#include <iostream>
#include <locale>
#include <algorithm>
#pragma once

using namespace std;
integrals::integrals()//����������� �� ���������
{
	a = b = n= rez =0;
	function = NULL;
}

integrals::integrals(double _a, double _b, int _n,double _rez, double(*_function)(double))//����������� �������������
{
	a = _a;
	b = _b;
	n = _n;
	rez = _rez;
	function = _function;
}

integrals::integrals(integrals &obj)//����������� �����������
{
	a = obj.a;
	b = obj.b;
	n = obj.n;
	rez =obj.rez;
	function = obj.function;
	
}

integrals::~integrals()//����������
{
	a = b = n =rez= 0;
	function = NULL;
}


double integrals::LeftRectangle()//����� ����� ���������������
{
	double h = (b - a) / n;
	double I = 0;
	for (int i = 0; i < n; i++)
		I =I +function(a + i * h)*h;
	rez = I;
	return I;
}

double integrals::RightRectangle()//����� ������ ���������������
{
	double h = (b - a) / n;
	double I = 0;
	for (int i = 1; i <= n; i++)
		I = I + function(a + i * h)*h;
	rez = I;
	return I;
}

double integrals::CentralRectangle()//����� ������� ���������������
{
	double h = (b - a) / n;
	double I = 0;
	for (int i = 0; i < n; i++)
		I = I + function(a + (i * h) / 2)*h;
	rez = I;
	return I;
}

ostream & operator<<(std::ostream & stream,integrals &obj)
 {
	 stream << obj.a << obj.b << obj.n;
	 return stream;
 }

 std::istream& operator>>(std::istream &stream, integrals &obj)
 {
	 stream >> obj.rez;
	 return stream;
 }



 






	




