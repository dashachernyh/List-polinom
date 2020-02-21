#pragma once
#include <iostream>
using namespace std;
struct TMonomom
{
	double coeff;
	int px, py, pz;
	bool operator <(TMonomom &m)
	{
		if ((px < m.px)||(px==m.px && py<m.py)||(px==m.px && py==m.py && pz<m.pz)) return true;
	    else return false;
	}
	bool operator ==(TMonomom &m)
	{
		if (px == m.px && py == m.py && pz == m.pz) return true;
		else return false;
	}
	bool operator >(TMonomom &m)
	{
		if((px>m.px)||(px==m.px && py>m.py)||(px==m.px && py==m.py && pz>m.pz)) return true;
		else return false;
	}

};