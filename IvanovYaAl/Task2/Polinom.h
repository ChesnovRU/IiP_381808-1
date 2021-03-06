#include <iostream>
#include <math.h>
#include <fstream>
#include <cstring>
#include <string.h>
#include <ostream>

using namespace std;

class Polinom {
public:
	int n;
	double *kof;
	Polinom();
	Polinom(int def);
	Polinom(const Polinom &c);
	~Polinom();
	int GetDl();
	double getkof(int i);
	Polinom& operator+(const Polinom &c);
	Polinom proizvod();
	friend istream &operator >> (istream &s, Polinom &c);
	friend ostream &operator << (ostream &s, Polinom &c);
	Polinom& operator = (const Polinom &c);
	double s4et(double x);
	void showProizvod(Polinom c);
};
ostream& operator << (ostream &stream, const Polinom &c);
istream& operator >> (istream &stream, Polinom &c);