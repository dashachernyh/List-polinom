#pragma once

#include"List.h"

struct Monom
{
	double coeff;
	int px, py, pz;
	Monom()
	{
		coeff = 0;
		px = 0;
		py = 0;
		pz = 0;
	}
	Monom(double _coeff, int _px, int _py, int _pz)
	{
			coeff = _coeff;
			px = _px;
			py = _py;
			pz = _pz;
	}
};

bool operator <(const Monom &m1,const Monom &m2)
{
	if ((m1.px*100+m1.py*10+m1.pz)<(m2.px*100+m2.py*10+m2.pz)) return true;
	else return false;
}
bool operator ==(const Monom &m1,const Monom &m2)
{
	if (m1.px == m2.px && m1.py == m2.py && m1.pz == m2.pz) return true;
	else return false;
}
bool operator >(const Monom &m1,const Monom &m2)
{
	if ((m1.px > m2.px) || (m1.px == m2.px && m1.py > m2.py) || (m1.px == m2.px && m1.py == m2.py && m1.pz > m2.pz)) return true;
	else return false;
}

template<class T>
class THeadList :public TList<T>
{
protected: TNode<T> *pHead;
public:
	THeadList();
	void InsFirst(T el);
	void DelFirst();
	void InsCurr(T el);
	void DelCurr();
	void InsLast(T el);
	void DelLast();
	~THeadList();
};
template<class T>
THeadList<T>::THeadList():TList<T>()
{
	pHead = new TNode<T>;
	pStop = pHead;
	pFirst = pHead;
	pHead->pNext = pFirst;
}
template<class T>
void THeadList<T>:: InsFirst(T el)
{
	TNode<T> *p = new TNode<T>;
	p->val = el;
	pHead->pNext = p;
	p->pNext = pFirst;
	pFirst = p;
	size++;
}
template<class T>
void THeadList<T>::DelFirst()
{
	TList<T>::DelFirst();
	pHead->pNext = pFirst;
}

template<class T>
THeadList<T>::~THeadList()
{
	TNode<T> *p;
	p = pFirst;
	while (pFirst == pStop)
	{
		p = pFirst->pNext;
		delete pFirst;
		pFirst = p;
	}
	delete pHead;
}
template<class T>
void THeadList<T>::InsCurr(T el)
{
	TList<T>::InsCurr(el);
	pHead->pNext = pFirst;
}
template<class T>
void THeadList<T>::DelCurr()
{
	TList<T>::DelCurr();
	pHead->pNext = pFirst;
}
template<class T>
void THeadList<T>::InsLast(T el)
{
	TList<T>::InsLast(el);
	pHead->pNext = pFirst;
}
template<class T>
void THeadList<T>::DelLast()
{
	TList<T>::DelLast();
	pHead->pNext = pFirst;
}