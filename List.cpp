#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
	Head = nullptr;
	Count = 0;
}

List::List(const List & obj)
{
	Head = nullptr;
	Element *temp = obj.Head;
	while (temp)
	{
		Add(temp->data);
		temp = temp->Next;
	}

	Count = obj.Count;

	temp = Head;

	Element *Array = new Element[Count];

	Element *Swap = Head;
	for (int i = 0; i < Count; i++)
	{
		Array[i].data = temp->data;
		temp = temp->Next;
	}

	for (int i = 0, j = Count - 1; i < Count / 2; i++, j--)
	{
		Swap->data = Array[i].data;

		Array[i].data = Array[j].data;

		Array[j].data = Swap->data;
	}

	temp = Head;

	for (int i = 0; i < Count; i++)
	{
		temp->data = Array[i].data;
		temp = temp->Next;
	}
	delete[] Array;
}

void List::InsertByPosition(char data, int position)
{
	if (position > -1 && position <= Count)
		if (position == 0 || position == Count + 1)
		{
			Add(data);
		}
		else
		{
			Element *temp = Head;
			while (position > 1)
			{
				position--;
				temp = temp->Next;
			}

			Element *temp_temp = new Element;
			temp_temp->data = data;

			temp_temp->Next = temp->Next;

			temp->Next = temp_temp;
			Count++;
		}
	else return;
}

void List::RemoveByPosition(int position)
{
	if (position > 0 || position <= Count)
		if (position == 0)
		{
			Del();
		}
		else
		{
			Element *temp = Head;
			while (position > 1)
			{
				position--;
				temp = temp->Next;
			}

			Element *temp_temp = new Element;
			temp_temp = temp->Next;

			temp->Next = temp_temp->Next;
			delete temp_temp;
		}
	else return;
}


List::~List()
{
	DelAll();
}

int List::GetCount()
{
	return Count;
}

int List::Find(char key)
{
	Element *temp = Head;

	for (int i = 0; i < Count - 1; i++)
	{
		if (temp->data == key)
			return i;

		temp = temp->Next;
	}

	return -1;
}

List & List::operator=(const List & obj)
{
	if (this == &obj)
		return *this;

	DelAll();
	//Head = nullptr;
	Element *temp = obj.Head;
	while (temp)
	{
		Add(temp->data);
		temp = temp->Next;
	}

	Count = obj.Count;

	temp = Head;

	Element *Array = new Element[Count];

	Element *Swap = Head;
	for (int i = 0; i < Count; i++)
	{
		Array[i].data = temp->data;
		temp = temp->Next;
	}

	for (int i = 0, j = Count - 1; i < Count / 2; i++, j--)
	{
		Swap->data = Array[i].data;

		Array[i].data = Array[j].data;

		Array[j].data = Swap->data;
	}
	temp = Head;

	for (int i = 0; i < Count; i++)
	{
		temp->data = Array[i].data;
		temp = temp->Next;
	}
	delete[] Array;

	return *this;
}

void List::Add(char data)
{

	Element * temp = new Element;

	temp->data = data;

	temp->Next = Head;

	Head = temp;

	Count++;
}

void List::Del()
{
	if (Head)
	{
		Element * temp = Head->Next;
		delete Head;
		Head = temp;
		Count--;
	}
}

void List::DelAll()
{
	while (Head != nullptr)
		Del();
}

void List::Print()
{
	Element * temp = Head;
	if (temp == nullptr)
	{
		cout << "List is empty!";
		return;
	}
	while (temp)
	{
		cout << temp->data;
		temp = temp->Next;
	}
	cout << endl;
}