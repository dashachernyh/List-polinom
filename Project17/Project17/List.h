#pragma once
#include <iostream>
using namespace std;
template <class T>
struct TNode
{
	T val;
	TNode<T> *pNext;
};
template <class T>
class TList
{
protected: 
	TNode<T> *pFirst,*pLast,*pCurr,*pPrev,*pStop;
	int len, pos;
public:
	TList();
	~TList();
	void InsFirst(T el);
	void InsCurr(T el);
	void InsLast(T el);
	void InsOrder(T el);
	void DelFirst();
	void DelCurr();
	T GetCurr();
	void Reset();
	void GoNext();
	bool IsEnd();
};
template<class T>
TList<T>::TList()
{
	len = 0;
	pos = -1;
	pFirst = NULL;
	pLast = NULL;
	pCurr = NULL;
	pPrev = NULL;
	pStop = NULL;
}
template<class T>
TList<T>::~TList()
{
	TNode<T> *p;
	p = pFirst;
	while (pFirst == NULL)
	{
		p = pFirst->pNext;
		delete pFirst;
		pFirst = p;
	}
}
template<class T>
void TList<T>::InsFirst(T el)
{
	TNode<T> *pNewFirst = new TNode<T>;
	pNewFirst->val = el;
	pNewFirst->pNext = pFirst;
	pFirst = pNewFirst;
	len++;
}
template<class T>
void TList<T>::InsLast(T el)
{
	TNode<T> *pNew = new TNode<T>;
	pNew->val = el;
	pLast->pNext = pNew;
	pLast = pNew;
	len++;
}
template<class T>
void TList<T>::DelFirst()
{
	~TList();
	/*len--;
	pos = -1;
	pCurr = NULL;
	pPrev = NULL;
	delete pFirst;*/
}
template<class T>
void TList<T>::InsCurr(T el)
{
	if (pFirst==pCurr) InsFirst(el);
	TNode<T> *pNew = new TNode<T>;
	pNew->val = el;
	len++;
    pPrev->pNext=pNew;
	pNew->pNext=pCurr;
	pCurr = pNew;
}
template<class T>
void TList<T>::DelCurr()
{
	if (pFirst == pCurr) DelFirst();
	else
	{
		if (pLast == pCurr) pLast = pPrev;
		pPrew->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pPrev->pNext;
		len--;
	}
}
template<class T>
T TList<T>::GetCurr()
{
	return pCurr->val;
}
template<class T>
void TList<T>::Reset()
{
	pCurr = pFirst;
	pos = 0;
	pPrev = NULL;
}
template<class T>
void TList<T>::GoNext()
{
	pPrev = pCurr;
	pCurr = pCurr->pNext;
	pos++;
}
template<class T>
bool TList<T> ::IsEnd()
{
	if (pCurr == pStop) return true;
	else return false;
}
template<class T>
void TList<T>::InsOrder(T el)
{
	if (pFirst->val < el) InsFirst(el);
	if (pLast->val > el) InsLast(el);
	else
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			if (pCurr->val < el)
				InsCurr(el); break;
		}
	}
}