#pragma once
#include"List_Head.h"
#include<iostream>
using namespace std;
class TPolinom :public THeadList<Monom>
{
public:
	TPolinom();
	TPolinom(int **mas, int size);
	TPolinom(TPolinom &p);
	Monom& GetMonom();
	void operator =(TPolinom &p);
	void InsMonom(Monom mon);
	TPolinom operator *(double k);
	void operator *=(double k);
	TPolinom operator *(Monom mon);
	void operator *=(Monom mon);
	TPolinom operator +(TPolinom &q);
	void operator +=(TPolinom &q);
	friend ostream& operator<<(ostream &out, TPolinom &p)
	{
		for (p.Reset(); !p.IsEnd(); p.GoNext())
		{
			if (p.pCurr->val.coeff == 0)  out << "0";
			else
			{
				out << "+" << "(" << p.pCurr->val.coeff << ")" << "x^(" << p.pCurr->val.px << ")y^(" << p.pCurr->val.py << ")z^(" << p.pCurr->val.pz << ")";

			}
		}
		if (p.IsEmpty()) out << "0";
		return out;
	}
	friend istream& operator>>(istream &in, TPolinom &p)
	{
		Monom m;
		in >> m;
		while (m.coeff != 0)
		{
			p.InsMonom(m);
			in >> m;
		}
		return in;
	}
};
TPolinom::TPolinom() :THeadList<Monom>()
{
	pHead->val.coeff = 0;
	pHead->val.pz = -1;
}

TPolinom::TPolinom(int **mas, int size) : THeadList<Monom>()
{
	pHead->val.coeff = 0;
	pHead->val.pz = -1;
	for (int i = 0; i < size; i++)
	{
		Monom mon;
		mon.coeff = mas[i][0];
		mon.px = mas[i][1] / 100;
		mon.py = mas[i][1] / 10 % 10;
		mon.pz = mas[i][1] % 10;
		InsMonom(mon);
	}
}

TPolinom::TPolinom(TPolinom &p) :THeadList<Monom>()
{
	pHead->val.pz = -1;
	for (Reset(); !IsEnd(); GoNext())
	{
		Monom mon;
		mon = p.pCurr->val;
		InsLast(mon);
	}
}
void TPolinom::operator =(TPolinom &p)
{
	DelList();
	pHead->val.pz = -1;
	for (p.Reset(); !p.IsEnd(); p.GoNext())
	{
		Monom mon;
		mon = p.pCurr->val;
		InsLast(mon);
	}
}

void TPolinom::InsMonom(Monom mon)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		if (pCurr->val == mon)
		{
			double k = mon.coeff + pCurr->val.coeff;
			if (k != 0) pCurr->val.coeff = k;
			else DelCurr();
			return;
		}
		if (mon > pCurr->val)
		{
			InsCurr(mon);
			return;
		}
	}
	InsLast(mon);
}

void TPolinom::operator *=(double k)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		pCurr->val.coeff *= k;
	}
}

TPolinom TPolinom::operator *(double k)
{
	TPolinom rez=*this;
	rez *= k;
	return rez;
}

void TPolinom::operator *=(Monom mon)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		pCurr->val.coeff *= mon.coeff;
		pCurr->val.px += mon.px;
		pCurr->val.py += mon.py;
		pCurr->val.pz += mon.pz;
	}
}

TPolinom TPolinom::operator *(Monom mon)
{
	TPolinom res(*this);
	res *= mon;
	return res;
}

void TPolinom::operator +=(TPolinom &q)
{
	Monom pm, qm, rm;
	Reset();
	q.Reset();
	while (!q.IsEnd())
	{
		pm = pCurr->val;
		qm = q.pCurr->val;
		if (pm > qm) GoNext();
		else
		{
			if (pm < qm)
			{
				InsCurr(qm);
				q.GoNext();
			}
			else
			{
				rm = pm;
				rm.coeff += qm.coeff;
				if (rm.coeff == 0)
				{
					DelCurr();
					q.GoNext();
				}
				else
				{
					pCurr->val = rm;
					if (&q == this)
					{
						q.GoNext();
					}
					else
					{
						q.GoNext();
						GoNext();
					}
				}
			}
		}
	}
}

TPolinom TPolinom::operator +(TPolinom &q)
{
	TPolinom rez(*this);
	rez += q;
	return rez;
}
Monom& TPolinom::GetMonom()
{
	return pCurr->val;
}
