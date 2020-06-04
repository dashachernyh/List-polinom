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
	TPolinom p1, p2,p;
	double k ;
	Monom m;
	/*cout << "enter firts polinom" << endl;
	cin >> p1;
	cout <<"Polinom: "<< p1 << endl;*/
	cout << "enter second polinom" << endl;
	cin >> p2;
	p = p2;
	cout <<"Polinom: "<< p2 << endl;
	/*p1 += p2;
	cout << "Polinomial addition: "<<p1 << endl;*/
	cout << "enter multiplier(number)" << endl;
	cin >> k;
	p2 *= k;
	cout <<"Polinomial multiplication (second polinom * const): "<< p2 << endl;
	cout << "enter monom" << endl;
	cin >> m;
	p *= m;
	cout << "Polinomial multiplication (second polinom * monom): " << p << endl;
	_getch();
}