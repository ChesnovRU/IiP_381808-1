
#include <iostream>


using namespace std;

class Triangle
{
public:
	bool exist()
	{
		if ((a + b <= c) || (a + c <= b) || (b + c <= a))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	};
	const char* bedr()
	{
		if (a == b == c)
		{
			return "��������������";
		}
		else
			if ((a == b) || (a == c) || (c == b))
			{
				return "��������������";
			}
			else
				return "��������������";
	};
	double square(double a, double b, double c)
	{
		double p = (a + b + c) / 2.0;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
	double perimetr(double a, double b, double c)
	{
		return a + b + c;
	}
	double cos(double a, double b, double c)
	{
		return (a*a + b * b - c * c) / (a + c);
	};
	const char* type()
	{
		if (exist())
		{
			if ((cos(a, b, c) == 0) || (cos(b, c, a) == 0) || (cos(c, a, b) == 0))
			{
				return "�������������";
			}
			else
			{
				if ((cos(a, b, c) > 0) || (cos(b, c, a) > 0) || (cos(c, a, b) > 0))
				{
					return "������������";
				}
				else
				{
					return "�������������";
				}
			}
		}
		else return "�� ����������";
	}
	Triangle(double _a, double _b, double _c)
	{
		a = _a;
		b = _b;
		c = _c;
	}

	~Triangle()
	{
		a = 0; b = 0; c = 0;
	}
private:
	double a, b, c;
};





int main()
{
	setlocale(LC_ALL, "Rus");
	double a, b, c;
	cout << "������� ������� ������������" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	Triangle Y(a, b, c);
	cout << (Y.exist() ? "����������� ����������: " : "����������� �� ���������� ") << endl;
	if (Y.exist())
	{
		cout << Y.bedr() << endl;
		cout << "������� ������������ = " << Y.square(a, b, c) << endl;
		cout << "�������� ������������ = " << Y.perimetr(a, b, c);
	}
	getchar();
	getchar();
}
