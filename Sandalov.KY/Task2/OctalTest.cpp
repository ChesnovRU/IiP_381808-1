#include "Octal.h"
#include <locale>
#include <fstream>



int main()
{
	setlocale(LC_ALL, "rus");
	Octal a, b, c;
	cout << "������� a � b" << endl;
m:
	int num = 0;
	// ��������� ����������
	try
	{
		int number = 0;
		cin >> a;
		num++;
		cin >> b;
	}
	catch (Exeption& ex)
	{
		if (num == 0)
			cout << "�������� ������ � " << ex.pos << " ����� a" << endl;
		else
			cout << "�������� ������ � " << ex.pos << " ����� b" << endl;
		goto m;

	}
	cout << "a = " << a;
	cout << "b = " << b;
	if (a == b)
		cout << "a = b" << endl;
	if (a != b)
		cout << "a != b" << endl;
	if (a < b)
		cout << "a < b" << endl;
	if (a > b)
		cout << "a > b" << endl;
	if (a <= b)
		cout << "a <= b" << endl;
	if (a >= b)
		cout << "a >= b" << endl;
	c = a + b;
	cout << "a + b = " << c;
	c = a - b;
	cout << "a - b = " << c;
	c = b - a;
	cout << "b - a = " << c;
	c = a * b;
	cout << "a * b = " << c;

	ofstream out("OutFile.txt"); // ������ � ����
	out << a << ' ' << b;
	out.close();
	ifstream in("OutFile.txt"); // ������ �� �����
	in >> a >> b;
	cout << "a � b �� ����� OutFile.txt " << endl << a << b;
	return 0;
}