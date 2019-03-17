#include <iostream>
#include <clocale>
#include "Calendar.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Calendar cal(1, 9, 1939, "������ ������ ������� �����");	// Sozdaiom kalendar
	cal.add(2, 9, 1945, "����� ������ ������� �����");			// Dobavlaem sobitie
	cout << cal << endl;										// Vivodim calendar
	cout << cal.getDate("����� ������ ������� �����") << endl;	// Vivodim daty opredelennogo sobitiya
	cout << cal.getDifference(17, 03, 2019, "����� ������ ������� �����");	// Vivodim raznicy megdy datoi i sobitiem
	cal.dateShift("������ ������ ������� �����", 2192);			// Sdvigem sobitie
	cout << cal << endl;
	getchar();
	return 0;
}