#include<iostream>
using namespace std;
#include"List.h"
#include<conio.h>
int main()
{
	TList<int> p;
	for (int i = 0; i < 5; i++)
	{
		p.InsFirst(i);
	}
	cout << p<<endl;
	p.Reset();
	p.SetPos(3);
	p.InsCurr(5);
	cout << p << endl;
	p.DelFirst();
	cout << p << endl;
	p.DelLast();
	cout << p << endl;
	_getch();
}