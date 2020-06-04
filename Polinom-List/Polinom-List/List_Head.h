#pragma once
#include"List.h"

struct Monom
{
	double coeff;   //коэффициент монома
	int px, py, pz; //степени х,у,z
	Monom()         //консруктор инициализации по умолчанию
	{
		coeff = 0;
		px = 0;
		py = 0;
		pz = 0;
	}
	Monom(double _coeff, int _px, int _py, int _pz)  //конструктор
	{
		if (_px < 0 || _py < 0 || _pz < 0) throw "wrong power";
		coeff = _coeff;
		px = _px;
		py = _py;
		pz = _pz;
	}
	//операции сравнения
	bool operator <(const Monom &m);  //меньше?
	bool operator <=(const Monom &m); //меньше или равно?
	bool operator >(const Monom &m); //больше?
	bool operator >=(const Monom &m); //больше или равно?
	bool operator ==(const Monom &m); //равно?

	//дружественные функции, переопределение ввода и вывода
	friend istream& operator >>(istream& in, Monom &m)
	{
		int k;
		cout << "Enter coeff of monom:" << endl;
		in >> m.coeff;
		cout << "Enter poxer (123):" << endl;
		in >> k;
		m.px = k / 100;
		m.py = k / 10 % 10;
		m.pz = k % 10;
		return in;
	}
	friend ostream& operator <<(ostream&out, Monom &m)
	{
		out << m.coeff << "x^" << m.px << "y^" << m.py << "z^" << m.pz;
		return out;
	}
};

bool Monom:: operator <(const Monom &m)
{
	if ((px * 100 + py * 10 + pz) < (m.px * 100 + m.py * 10 + m.pz)) return true;
	else return false;
}
bool Monom:: operator <=(const Monom &m)
{
	if ((px * 100 + py * 10 + pz) <= (m.px * 100 + m.py * 10 + m.pz)) return true;
	else return false;
}
bool Monom:: operator ==(const Monom &m)
{
	if (px == m.px && py == m.py && pz == m.pz) return true;
	else return false;
}
bool Monom::operator >(const Monom &m)
{
	if ((px * 100 + py * 10 + pz) > (m.px * 100 + m.py * 10 + m.pz)) return true;
	else return false;
}
bool Monom::operator >=(const Monom &m)
{
	if ((px * 100 + py * 10 + pz) >= (m.px * 100 + m.py * 10 + m.pz)) return true;
	else return false;
}
template<class T>
class THeadList :public TList<T> //потомок класса TList
{
protected: TNode<T> *pHead;  //указатель на "голову" списка
public:
	THeadList();   //конструктор
	~THeadList();  //деструктор 
	//добавление
	void InsFirst(T el); //перед первым
	void InsCurr(T el);  //перед текущим
	void InsLast(T el);  //последним
	//удаление
	void DelFirst();   //удалить первое звено
	void DelCurr();    //удалить текущее звено
	void DelLast();    //удалить последнее звено
	//доступ
	bool IsEmpty();    //список пуст?
};
template<class T>
THeadList<T>::THeadList() :TList<T>()
{
	pHead = new TNode<T>;
	pStop = pHead;
	pFirst = pHead;
	pHead->pNext = pFirst;
}
template<class T>
void THeadList<T>::InsFirst(T el)
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
	TList<T> ::DelList();
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
	pHead->pNext = pFirst;
	TList<T>::InsLast(el);

}
template<class T>
void THeadList<T>::DelLast()
{
	TList<T>::DelLast();
	pHead->pNext = pFirst;
}
template<class T>
bool THeadList<T>::IsEmpty()
{
	if (pHead == pFirst) return true;
	else return false;
}