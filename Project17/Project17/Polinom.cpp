#include "Polinom.h"
#include<iostream>
using namespace std;
TPolinom::TPolinom() :THeadList<Monom>()
{
	pHead->val.pz = -1;
}

TPolinom::TPolinom(int mas[][2], int size) : THeadList<Monom>()
{
	pHead->val.pz = -1;
	for (int i = 0; i < size; i++)
	{
		Monom mon;
		mon.coeff = mas[i][0];
		mon.px = mas[i][1] / 100;
		mon.py = mas[i][1] / 10 % 10;
		mon.pz = mas[i][1] % 100;
		InsLast(mon);
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
	p.DelList();
	pHead->val.pz = -1;
	for (Reset(); !IsEnd(); GoNext())
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
		pCurr->val.coeff = pCurr->val.coeff*k;
	}
}

TPolinom TPolinom::operator *(double k)
{
	TPolinom rez(*this);
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
		if (pm < qm)
		{
			InsCurr(qm);
			GoNext();
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
				q.GoNext();
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