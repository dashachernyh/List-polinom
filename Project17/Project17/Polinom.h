#pragma once
#include"List_head.h"
class TPolinom:public THeadList<Monom>
{
public:
	TPolinom();
	TPolinom(int mas[][2], int size);
	TPolinom(TPolinom &p);
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
			out << p.pCurr->val.coeff << "x^";
			out << p.pCurr->val.px << "y^";
			out << p.pCurr->val.py << "z^";
			out<< p.pCurr->val.pz;
		}
		return out;
	}
	friend istream& operator>>(istream &in, TPolinom &p)
	{
		double k;
		p.Reset();
		in >> k;
		while (k != 0)
		{
			p.pCurr->val.coeff = k;
			in >> p.pCurr->val.px;
			in >> p.pCurr->val.py;
			in >> p.pCurr->val.pz;
			p.GoNext();
			in >>k;
		}
		return in;
	}
};
