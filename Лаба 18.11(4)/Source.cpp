#include <iostream>
#include <list>
#include "C:\Users\Арина\source\repos\Лаба 18.11(3)\Pair.h"
#include "List.h"
#include <vector>
#include <queue>
#include <list>
#include <cstdlib>
using namespace std;
typedef list<Pair> ListPair;

int main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");

	List <Pair> list(3);
	list.Print();

	Pair sr = list.SredneeAr();
	cout << sr << endl;
	cout << "На какую позицию поставить среднее арифметическое ?" << endl;
	int p;
	cin >> p;
	list.AddInList(sr, p);
	list.Print();

	list.Search();
	list.Print();

	List<Pair> list3(4);
	sr = list3.SredneeAr();
	list3.Decrease(sr);
	list3.Print();
	
	return 0;
}