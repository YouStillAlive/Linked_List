#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List lst;
	char s[] = "Hello, World !!!\n";
	cout << s << endl;

	int len = (int)strlen(s);
	for(int i = len-1; i >=0; i--)
		lst.Add(s[i]);
	lst.Print();

	cout << "InsertByPosition - ";
	lst.InsertByPosition('A', 2);
	lst.Print();

	cout << "RemoveByPosition - ";
	lst.RemoveByPosition(0);
	lst.Print();

	cout << "Find('A') position - ";

	int p = lst.Find('A');
	cout << p;

	cout << "\n\ncopy constr lst2 = lst - ";
	List lst2 = lst;
	lst2.Print();

	cout << "operator =(const List & obj) - ";
	lst = lst2;
	lst.Print();

	system("pause");
}