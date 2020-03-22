#include<iostream>
using namespace std;
#include"List.h"
#include"List_head.h"
#include"Polinom.h"
#include<conio.h>
int main()
{
	/*TList<int> p;
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
	p.SetPos(1);
	p.DelCurr();
	cout << p << endl;
	p.InsLast(6);
	cout << p << endl;*/
	TPolinom p1, p2;
	cin >> p1;
	cout << p1 << endl;
	cin >> p2;
	cout << p2 << endl;
	p1 += p2;
	cout << p1 << endl;
	double k = 4;
	p2 *= k;
	cout << p2 << endl;
	_getch();
}