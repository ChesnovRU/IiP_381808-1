#include "Octal.h"
// ����������� �� ���������
Octal::Octal()
{
	size = 0;
	lng = 0;
	octa = 0;
}
// ����������� � ���������� �������� �������
Octal::Octal(int _size)
{
	lng = size = _size;
	octa = new unsigned char[size];
	for (int i = 0; i < lng; ++i)
		octa[i] = 0;
}
// ����������� �������������� ���� �� ������
Octal::Octal(const string& _str)
{
	lng = size = _str.length();
	octa = new unsigned char[size];
	for (int i = 0; i < lng; ++i)
		if (_str[lng - 1 - i] - '0' >= 0 && _str[lng - 1 - i] - '0' < 8)
			octa[i] = _str[lng - 1 - i] - '0';
		else
			throw Exeption(strNOTOCTA, lng - i); // ����������� ���������� � ������, ���� ������� ������ ������ ������������� �����
}
// ����������� �����������
Octal::Octal(const Octal& _oct)
{
	lng = size = _oct.size;
	octa = new unsigned char[size];
	for (int i = 0; i < lng; ++i)
		octa[i] = _oct.octa[i];

}
// �������, ������� ��������� ������� ����� ����������� � ����������� ����� � ���������� ����� ��������� ��� ����� � ��������� �� ������� � ������� ������������ �����
void find_min_max(unsigned char* octa, unsigned char* _octa, int lng, int _lng, int* mins, int* maxs, unsigned char** max_a, unsigned char** min_b)
{
	
	if (lng < _lng)
	{
		*mins = lng;
		*min_b = octa;
		*max_a = _octa;
		*maxs = _lng;
	}
	else
	{
		*mins = _lng;
		*min_b = _octa;
		*max_a = octa;
		*maxs = lng;
	}
	return;
}
// ���������� ��������� ������������
Octal& Octal::operator= (const Octal& _oct)
{
	if (this != &_oct)
	{
		if (lng != _oct.lng)
		{
			lng = size = _oct.size;
			delete[] octa;
			octa = new unsigned char[size];
		}
		for (int i = 0; i < lng; ++i)
			octa[i] = _oct.octa[i];
	}
	return *this;
}
// ���������� �������������� �����������
// +
Octal Octal::operator+ (const Octal& _oct)
{
	int mins, maxs; // ����� �������� � �������� �����
	unsigned char *max_a, *min_b; // ��������� �� ������� � ������ �����
	find_min_max(octa, _oct.octa, lng, _oct.lng, &mins, &maxs, &max_a, &min_b);
	Octal tmp(maxs + 1); // ������� ������ ������ � ������ ����������� ����� + 1, �� ����, � ������� �� ��������� ��� ������ ������� ������������� ����� ��� ��������
	int pls = 0; // ������� �� ����� ���� ���� ������� � ��������� 
	for (int i = 0; i < mins; ++i) // ���������� �������� �������� ����� � �������, ���� ������� �� ����������
	{
		tmp.octa[i] = (octa[i] + _oct.octa[i] + pls) % 8;
		pls = (octa[i] + _oct.octa[i] + pls) / 8;
	}
	if (_oct.lng != lng) // ������, ���� ����� ���� ����� �� �����, �� ������ ������ ���������� ����� �������� �����, �������� ������� � ��������� ������
	{
		for (int i = mins; i < maxs; ++i)
		{
			tmp.octa[i] = (max_a[i] + pls) % 8;
			pls = (max_a[i] + pls) / 8;
			
		}
		if (pls == 0) // ������� �� ��������� �������, ���� �� ����� ����, �� ����������� ����� ����� ������ ������ ����� ����������� �� ���������
		{
			tmp.lng = maxs;
		}
		else // ����� ��������� �� ���� ������ ������, ���������� ��� �������� 1
		{
			tmp.octa[maxs] = 1;
			pls = 0;
		}
	}
	else
	{
		if (pls == 0)
		{
			tmp.lng = mins;
		}
		else
		{
			tmp.lng = mins + 1;
			tmp.octa[mins] = 1;
			pls = 0;
		}
	}
	return tmp;
}
//������ ���������� � ���������� +
Octal Octal::operator- (const Octal& _oct)
{
	int mins, maxs;
	unsigned char *max_a, *min_b;
	find_min_max(octa, _oct.octa, lng, _oct.lng, &mins, &maxs, &max_a, &min_b);
	Octal tmp(maxs);
	unsigned char pls = 0; // �������� �� �������� �������
	for (int i = 0; i < mins; ++i) // ��������� �� �������� ��������, ���� ������� �� �������������
	{
		
		if (octa[i] - pls < _oct.octa[i])
		{
			tmp.octa[i] = octa[i] - pls + 8 - _oct.octa[i];
			pls = 1;
		}
		else
		{
			tmp.octa[i] = octa[i] - pls - _oct.octa[i];
			pls = 0;
		}
	}
	if (lng != _oct.lng) // � ���� ����� ����� �� �����, �� ������ ���������� ����� �������� �����
	{
		for (int i = mins; i < maxs; ++i)
		{
			if (lng < _oct.lng) // ���� ����� �����, �� �������� �������� ����� ������ ����� ����������� (�� ����, �������� �� 0)
			{
				tmp.octa[i] = 8 - (_oct.octa[i] + pls);
				pls = 1;
			}
			else // ������ ���������� ������� ����� �� �������� ��������, ��������, �������� �� �� ������� �������� ��� ���
			{
				if (octa[i] - pls < 0)
				{
					tmp.octa[i] = octa[i] - pls + 8;
					pls = 1;
				}
				else
				{
					tmp.octa[i] = octa[i] - pls;
					pls = 0;
				}
			}
		}
	}
	return tmp;
}
// ������ ���������� � ���������� +
Octal Octal::operator* (const Octal& _oct)
{
	int mins, maxs;
	unsigned char *max_a, *min_b;
	find_min_max(octa, _oct.octa, lng, _oct.lng, &mins, &maxs, &max_a, &min_b);
	Octal tmp(maxs + mins); // ����� �����, ������� ��������� � ���������� ��������� ����� � ������� + 1, � ������ ��������� ������ ��� �������� �� ����������
	for (int i = 0; i < mins; ++i) // ���������� ��������� �������� ����� �� ��������� ����� ��������, ������� � 1-�� �� ��������� �� 1 ������ � ������ ���������� ��� ������������
	{
		unsigned char pls = 0; //������� � ������� ������
		Octal trnst(maxs + i + 1); // ����� ���������� ������� ������������ � ������ �������� �� 1 ������ � ������� ��� ��������� ������ �������
		int j = 0;
		while(j < i) // �������� ������� �������, � ������� ����������
		{
			trnst.octa[j] = 0;
			j++;
		}
		int k = 0;
		for (j; j < maxs + i; j++) // ��������� �������� ����� �� ��������� ����� ��������, ������� � 1-��
		{
			if ((max_a[k] * min_b[i] + pls) < 8) // ��� ��������
			{
				trnst.octa[j] = max_a[k] * min_b[i] + pls;
				pls = 0;
			}
			else // � ������ �������� � ������� ������
			{
				unsigned char ff = max_a[k] * min_b[i] + pls;
				while (ff - 8 >= 0)
					ff -= 8;
				trnst.octa[j] = ff;
				pls =((max_a[k] * min_b[i] + pls) / 8);
			}
			k++;
		}
		if (pls != 0) // ���������, �������� �� ����� ������� ������, ���� ��, �� ��������� ���, ���� ���, �� ����������� ����� ������������ ������������ � ����� �������� ���������
		{
			trnst.octa[maxs + i] = pls;
			pls = 0;
		}
		else
		{
			trnst.lng = trnst.size - 1;
		}
		tmp = tmp + trnst; // ����� ������������
		
	}
	
	return tmp;
}
// ���������� ���������� ���������
bool Octal::operator== (const Octal& _oct)
{
	if (lng != _oct.lng) return false;
	for (int i = 0; i < _oct.lng; ++i)
	{
		if (octa[i] != _oct.octa[i])
			return false;
	}
	return true;
}

bool Octal::operator!= (const Octal& _oct)
{
	return !(*this == _oct);
}

bool Octal::operator> (const Octal& _oct)
{
	if (lng > _oct.lng)
	{
		return true;
	}
	if (lng < _oct.lng)
	{
		return false;
	}
	for (int i = lng - 1; i >= 0; --i)
	{
		if (octa[i] > _oct.octa[i])
			return true;
	}
	return false;

}

bool Octal::operator<= (const Octal& _oct)
{
	return !(*this > _oct);
}

bool Octal::operator< (const Octal& _oct)
{
	if (lng < _oct.lng)
	{
		return true;
	}
	if (lng > _oct.lng)
	{
		return false;
	}
	for (int i = lng - 1; i >= 0; --i)
	{
	if (octa[i] < _oct.octa[i])
		return true;	
	}
	return false;
}

bool Octal::operator>= (const Octal& _oct)
{
	return !(*this < _oct);
}
// ���������� ���������� ��������� �����-������
ostream& operator<< (ostream& stream, const Octal& _oct)
{
	if (_oct.octa[_oct.lng - 1] != 0) //��� ������ ��������� ������� ����� �� ������ ������� ��������
	{
		for (int i = _oct.lng - 1; i >= 0; --i)
		{
			stream << (int)_oct.octa[i];
		}
		cout << endl;
	}
	else // � ���� ��� ��� �����, �� ������� ������ ��� ������, �� ����, ������ �� ������� ��
	{
		int i = _oct.lng - 1;
		while (_oct.octa[i] == 0 && i >= 1)
		{
			i--;
		}
		for (int j = i; j >= 0; --j)
		{
			stream << (int)_oct.octa[j];
		}
		cout << endl;
	}
	return stream;
}

istream& operator>> (istream& stream, Octal& _oct)
{
	string str;
	stream >> str;
	_oct = str;
	return stream;
}
// ����������
Octal::~Octal()
{
	lng = size = 0;
	delete[] octa;
}
