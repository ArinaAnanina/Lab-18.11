#include <iostream>
#include <list>
#include "Pair.h"
#include <cstdlib>
using namespace std;
typedef list<Pair> List;
List MakeList(int n)
{
	List l;
	for (int i = 0; i < n; i++)
	{
		Pair a;
		cin >> a;
		l.push_back(a);
	}
	return l;
}
void PrintList(List l)
{
	int n = l.size();
	for (int i = 0; i < n; i++)
	{
		cout << i << " элемент: " << l.front() << endl;
		l.pop_front();
	}
	cout << endl;
}
// Задание 3
Pair SredneeAr(List l)
{
	Pair s ;
	Pair n (l.size(), l.size());
	int len = l.size();
	for (int i = 0; i < len; i++)
	{
		s = s + l.front();
		l.pop_front();
	}
	return s / n;
}
void AddInList(List& l, Pair element, int pos)
{
	list<Pair>::iterator li = l.begin();
	for (int i = 0; i < pos; i++)
	{
		li++;
	}
	l.insert(li, element);
}
/*
void DeleteEl(List& l, int pos)
{
	list<int>::iterator li = l.begin();
	for (int i = 0; i < pos; i++)
	{
		li++;
	}
	l.erase(li);
}*/
// Задание 4
List Surch(List& l)
{
	list<Pair> tmp;
	Pair k1, k2;
	cout << "Введите диапазон для поиска в виде двух пар[k1, k2]: ";
	cin >> k1 >> k2;
	int n = l.size();
	for (int i = 0; i < n; i++)
	{
		if (l.front() < k1 || l.front() > k2)
		{
			tmp.push_back(l.front());
		}
		l.pop_front();
	}
	return tmp;
}
// Задание 5
List Decrease(List& l, Pair sr)
{
	list<Pair> tmp;
	int n = l.size();
	for (int i = 0; i < n; i++)
	{
		tmp.push_back(l.front() - sr);
		l.pop_front();
	}
	return tmp;
}
int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		list<Pair> list1;
		list<Pair>::iterator li = list1.begin();
		int n;
		cout << "Введите кол-во элеентов: ";
		cin >> n;
		list1 = MakeList(n);
		PrintList(list1);

		//Задание 3
		Pair el = SredneeAr(list1);
		cout << "На какую позицию вставить среднее арифетическое? " << endl;
		int pos;
		cin >> pos;
		if (pos > list1.size())
		{
			throw 1;
		}
		AddInList(list1, el, pos);
		PrintList(list1);
		//Задание 4
		list1= Surch(list1);
		PrintList(list1);
		//Задание 5
		Pair el2 = SredneeAr(list1);
		list1 = Decrease(list1, el2);
		PrintList(list1);
	}
	catch (int)
	{
		cout << "Ошибка!" << endl;
	}
}
