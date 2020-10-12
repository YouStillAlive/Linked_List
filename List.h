#pragma once
//#include <iostream>
struct Element
{
	char data;
	Element * Next;
	void Print()
	{
		std::cout<< data;
	}
};

class List
{
	Element * Head;
	int Count;

public:
	List();
	List(const List& obj);
	~List();

	void Add(char data);
	void Del();
	void DelAll();
	void Print();
	void InsertByPosition(char data, int position);
	void RemoveByPosition(int position);
	int GetCount();
	int Find(char key);

	List& operator = (const List & obj);
};
