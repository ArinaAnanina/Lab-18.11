#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

template <class T>
class List
{
	queue<T> queue1;
	int len;
public:
	List(void);
	List(int n);
	void Print();
	~List(void);
	List(const List<T>& li);
	//3
	T SredneeAr();
	void AddInList(T el, int pos);
	//4
	void Search();
	//5
	void Decrease(T sr);
};

template <class T>
List<T>::List()
{
	len = 0;
}
template <class T>
List<T>::List(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cout << "¬ведите элемент: "<< endl;
		cin >> a;
		queue1.push(a);
	}
	len = queue1.size();
}
template <class T>
void List<T>::Print()
{
	vector <T> tmp;
	int n = queue1.size();
	for (int i = 0; i < n; i++)
	{
		tmp.push_back(queue1.front());
		queue1.pop();
	}
	for (int i = 0; i < n; i++)
	{
		cout << tmp[i] << endl;
	}

	for (int i = 0; i < n; i++)
	{
		queue1.push(tmp[i]);
	}
	cout << endl;
}
template <class T>
List<T>::~List(void)
{
}
template <class T>
List<T>::List(const List<T>& li)
{
	vector <T> tmp;
	int n = li.size();
	for (int i = 0; i < n; i++)
	{
		tmp.push_back(li.front());
		li.pop();
	}
	for (int i = 0; i < n; i++)
	{
		cout << tmp[i] << endl;
	}

	for (int i = 0; i < n; i++)
	{
		queue1.push(tmp[i]);
	}
}

template <class T>
T List<T>::SredneeAr()
{
	list<T> l = CopyQueueToList(queue1);
	int n = 1;
	T sum = queue1.front();
	queue1.pop();
	while (!queue1.empty())
	{
		sum = sum + queue1.front();
		queue1.pop();
		n++;
	}
	queue1 = CopyListToQueue(l);
	return sum / Pair(n,n);
}
template <class T>
void List<T>::AddInList(T el, int pos)
{
	list<T> l;
	T tmp;
	int i = 0;
	while (!queue1.empty())
	{
		tmp = queue1.front();
		if (i == pos)
		{
			l.push_back(el);
		}
	    l.push_back(tmp);
		queue1.pop();
		i++;
	}
	if (pos >= l.size())
	{
		l.push_back(el);
	}
	queue1 = CopyListToQueue(l);
}
template <class T>
void List<T>::Search()
{
	T k1, k2;
	cout << "¬ведите диапазон дл€ поиска в виде двух пар[k1, k2]: ";
	cin >> k1 >> k2;
	list<T> list1 = CopyQueueToList(queue1);
	int n = list1.size();
	list <T> tmp;
	for (int i = 0; i < n; i++)
	{
		if (list1.front() < k1 || list1.front() > k2)
		{
			tmp.push_back(list1.front());
		}
		list1.pop_front();
	}
	n = tmp.size();
	for (int i = 0; i < n; i++)
	{
		list1.push_back(tmp.front());
		tmp.pop_front();
	}
	queue1 = CopyListToQueue(list1);
}
template <class T>
void List<T>::Decrease(T sr)
{
	list<T> list1 = CopyQueueToList(queue1);
	list<T> tmp;
	int n = list1.size();
	for (int i = 0; i < n; i++)
	{
		tmp.push_back(list1.front() - sr);
		list1.pop_front();
	}
	for (int i = 0; i < n; i++)
	{
		list1.push_back(tmp.front());
		tmp.pop_front();
	}
	queue1 = CopyListToQueue(list1);
}
template <class T>
list<T> CopyQueueToList(queue<T> q)
{
	list<T> l;
	while (!q.empty())
	{
		l.push_back(q.front());
		q.pop();
	}
	return l;
}
template <class T>
queue<T> CopyListToQueue(list<T> l)
{
	queue<T> q;
	int n =l.size();
	for (int i = 0; i < n; i++)
	{
		q.push(l.front());
		l.pop_front();
	}
	return q;
}
