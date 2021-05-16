#include "Pair.h"
#include <iostream>
#include <string>

using namespace std;

Pair::Pair()
{
	First = 0;
	Second = 0;
}

Pair::Pair(int First, double Second)
{
	this->First = First;
	this->Second = Second;
}

Pair::Pair(const Pair& p)
{
	this->First = p.First;
	this->Second = p.Second;
}

Pair::~Pair() {}

void Pair::Show()
{
	cout << First << " : " << Second << endl;
}

void Pair::SetFirst(int N)
{
	First = N;
}

void Pair::SetSecond(double D)
{
	Second = D;
}

bool Pair::operator< (const Pair& r) {
	return (First < r.First) && (Second < r.Second);
}

bool Pair::operator> (const Pair& r) {
	return (First > r.First) && (Second > r.Second);
}

/*Pair& Pair::operator++ ()
{
	First++;
	Second++;
	return *this;
}*/

Pair Pair::operator++ (int)
{
	Pair old(First, Second);
	Second++;
	return old;
}

ostream& operator << (ostream& out, const Pair& p)
{
	out << p.First << " : " << p.Second << endl;
	return out;
}
istream& operator>> (istream& in, Pair& p)
{
	cout << "¬ведите первое число: "; in >> p.First;
	cout << "¬ведите второе число: "; in >> p.Second;
	return in;
}
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)
	{
		return *this;
	}
	this->First = p.First;
	this->Second = p.Second;
	return *this;
}
Pair Pair:: operator+(const Pair& p)
{
	Pair p1;
	p1.First = this->First + p.First;
	p1.Second = this->Second + p.Second;
	return p1;
}
Pair Pair::operator/(const Pair& p)
{
	Pair p1;
	p1.First = this->First / p.First;
	p1.Second = this->Second / p.Second;
	return p1;
}
Pair Pair:: operator-(const Pair& p)
{
	Pair p1;
	p1.First = this->First - p.First;
	p1.Second = this->Second - p.Second;
	return p1;
}