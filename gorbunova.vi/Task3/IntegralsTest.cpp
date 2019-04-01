#include <clocale>
#include <iostream>
#include <fstream>
#include "integrals.h"
using namespace std;

void vyvod(double a, double b, int n,double rez,double(*function)(double))//������� ��� ������ ������ 
{
	double I;
	int w;
	cin >> w;
	switch (w)
	{
	case 1:
	{   
		integrals c(a, b, n,rez, function);
		I =c.LeftRectangle();
		cout << "���������:" << I << endl;
		break;
	}
	case 2:
	{
		integrals c(a, b, n, rez, function);
		I = c.RightRectangle();
		cout << "���������:" << I << endl;
		break;
	}
	case 3:
	{
		integrals c(a, b, n, rez, function);
		I = c.CentralRectangle();
		cout << "���������:" << I << endl;
		break;
	}
	}

}

int main()
{
	int q;
	double a, b,rez=0;
	int n;
	setlocale(LC_ALL, "Rus");
	cout << "������� ������� ���������:" << endl;
	cin >> a >> b;
	cout << "������� ���-�� �����:" << endl;
	cin >> n;
	cout << "�������� ��� �������:\n1)sin(x)\n2)cos(x)\n3)exp(x)" << endl;
	cin >> q;
	switch (q)
	{
	case 1:
		cout << "�������� ����� ���������:\n1)����� ����� ���������������\n2)����� ������ ���������������\n3)����� ������� ���������������" << endl;
		{
		   vyvod(a,b,n,rez,sin);
		}
		break;
	case 2:
		cout << "�������� ����� ���������:\n1)����� ����� ���������������\n2)����� ������ ���������������\n3)����� ������� ���������������" << endl;
		{
		   vyvod(a,b,n,rez,cos);
		}
		break;
	case 3:
		cout << "�������� ����� ���������:\n1)����� ����� ���������������\n2)����� ������ ���������������\n3)����� ������� ���������������" << endl;
		{
		   vyvod(a,b,n,rez,exp);
		}
		break;

	}
}
