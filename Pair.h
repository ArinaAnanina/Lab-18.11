#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pair
{
	int First;
	double Second;
public:
	Pair();
	Pair(int First, double Second);
	Pair(const Pair& p);
	~Pair();
	void Show();
	void SetFirst(int N);
	void SetSecond(double D);
	int GetFirst()
	{
		return First;
	}
	double GetSecond()
	{
		return Second;
	}
	Pair& operator=(const Pair& p);
	Pair operator+(const Pair& p);
	Pair operator-(const Pair& p);
	Pair operator/(const Pair& p);
	friend ostream& operator<< (ostream& out, const Pair& p);
	friend istream& operator>> (istream& in, Pair& p);

	bool operator< (const Pair& r);
	bool operator> (const Pair& r);

	//Pair& operator++ ();
	Pair operator++ (int);
};

