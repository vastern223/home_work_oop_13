#include<iostream>
#include "Class.h"
using namespace std;

int main()
{
	List < double > ls;
	ls.AddToHead(1.2);
	ls.AddToHead(1.5);
	ls.AddToHead(5.2);
	ls.AddToHead(2.9);
	ls.Print();
	cout << endl;
	ls.List_search(4);
	system("pause");
	return 0;
}
