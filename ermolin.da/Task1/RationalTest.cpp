#include <iostream>
#include <locale.h>
#include "Rational.h"

using namespace std;

int main() 
{
int a, b;//���������� ��� ������
setlocale(LC_CTYPE, "Russian");//����������� ������� ��������
Rational Sum1(13,6), Sum2(12,6);
cout << "������� 2 �����\n";
cin >> Sum1>>Sum2;
cout << "�����: " << Sum1 + Sum2 << endl;
cout << "��������: " << Sum1 - Sum2 << endl;
cout << "������������: " << Sum1 * Sum2 << endl;
cout << "�������: " << Sum1 / Sum2 << endl;
return 0;
}