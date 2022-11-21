#include "DecStr.h"
#include <iostream>

using namespace std;

DecStr::DecStr(int val) :String(val)
{
	cout << "DecStr::DecStr(int val) :String(val)" << endl;
}
DecStr::DecStr(char ch) : String(ch)
{
	cout << "DecStr::DecStr(char ch) : String(ch)" << endl;
}
DecStr::DecStr(const char* Str) : String(Str)
{
	if (!((pCh[0] >= '0' && pCh[0] <= '9') || (pCh[0] == '-') || (pCh[0] == '+')))
	{
		cout << "Bad sumbol, pCh[0] = " << pCh[0] << endl;
		if (pCh)delete[]pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
	for (int i = 1; i < len; i++)
	{
		if (!(pCh[i] >= '0') && (pCh[i] <= '9'))
		{
			cout << "Bad String, pCh[" << i << "]=" << pCh[i] << endl;
			if (pCh)delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}

	cout << "DecStr::DecStr(const char* Str) : String(Str)" << endl;
}

DecStr::DecStr(const DecStr& from) : String(from)
{
	cout << "DecStr::DecStr(const DecStr & from) : String(from)" << endl;
}

DecStr::~DecStr()
{
	cout << "DecStr::~DecStr()" << endl;
}

DecStr& DecStr::operator= (const DecStr& DS)
{
	if (&DS != this)
	{
		delete[]pCh;
		len = strlen(DS.pCh);
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, DS.pCh);
	}
	cout << "DecStr& DecStr::operator= (const DecStr& DS)" << endl;
	return *this;
}

DecStr operator + (const DecStr& x1, const int x2) {
	int N1, N2;
	int Sch = 0;
	char* rezul;
	DecStr Vr(x1);
	N1 = atoi(Vr.GetStr());
	N2 = x2;
	int sum = N1 + N2;

	if ((N2 > 0 && sum < N1) || (N2 < 0 && sum > N1))
	{
		if (Vr.pCh) delete[] Vr.pCh;
		cout << "Ошибка, переполнение значения int" << endl;
		Vr.pCh = new char[1];
		Vr.pCh[0] = '\0';
		Vr.len = strlen(Vr.pCh);
		return Vr;
	}

	while (N2) {
		Sch++;
		N2 /= 10;
	}

	if (N2 < 0) {
		Sch++;
		N2 *= -1;
	}

	if (Vr.len < Sch) {
		rezul = new char[Sch + 2];
		_itoa_s(sum, rezul, Sch + 2, 10);
	}
	else
	{
		rezul = new char[Vr.len + 2];
		_itoa_s(sum, rezul, Vr.len + 2, 10);
	}

	if (Vr.pCh) delete[] Vr.pCh;
	Vr.pCh = rezul;
	Vr.len = strlen(Vr.pCh);
	return Vr;
};

DecStr operator + (const DecStr& x1, const DecStr& x2) {
	int num1, num2;
	DecStr tmp(x1);
	num1 = atoi(tmp.GetStr());
	num2 = atoi(x2.GetStr());
	int A = num1 + num2;
	char* pTmpCh;

	if (tmp.len >= x2.len)
	{
		pTmpCh = new char(tmp.len + 2);
		_itoa_s(A, pTmpCh, tmp.len + 2, 10);
	}
	else
	{
		pTmpCh = new char[x2.len + 2];
		_itoa_s(A, pTmpCh, x2.len + 2, 10);
	}
	if (tmp.pCh)delete[] tmp.pCh;
	tmp.pCh = pTmpCh;
	tmp.len = strlen(tmp.pCh);
	cout << "DecStr::operator(const DecStr& pobg1, const DecStr& pobg2)" << endl;
	return tmp;
};

DecStr operator + (const int x2, const DecStr& x1) {
	int N1, N2;
	int Sch = 0;
	char* rezul;
	DecStr Vr(x1);
	N1 = atoi(Vr.GetStr());
	N2 = x2;
	int sum = N1 + N2;

	if ((N2 > 0 && sum < N1) || (N2 < 0 && sum > N1))
	{
		if (Vr.pCh) delete[] Vr.pCh;
		cout << "Ошибка, переполнение значения int" << endl;
		Vr.pCh = new char[1];
		Vr.pCh[0] = '\0';
		Vr.len = strlen(Vr.pCh);
		return Vr;
	}

	while (N2) {
		Sch++;
		N2 /= 10;
	}

	if (N2 < 0) {
		Sch++;
		N2 *= -1;
	}

	if (Vr.len < Sch) {
		rezul = new char[Sch + 2];
		_itoa_s(sum, rezul, Sch + 2, 10);
	}
	else
	{
		rezul = new char[Vr.len + 2];
		_itoa_s(sum, rezul, Vr.len + 2, 10);
	}

	if (Vr.pCh) delete[] Vr.pCh;
	Vr.pCh = rezul;
	Vr.len = strlen(Vr.pCh);
	return Vr;
};

DecStr operator - (const DecStr& x1, const DecStr& x2) {
	int num1, num2;
	DecStr tmp(x1);
	num1 = atoi(tmp.GetStr());
	num2 = atoi(x2.GetStr());
	char* pTmpCh;
	int A = num1 - num2;
	if (x1.len >= x2.len)
	{
		pTmpCh = new char[tmp.len + 2];
		_itoa_s(A, pTmpCh, tmp.len + 2, 10);
	}
	else
	{
		pTmpCh = new char[x2.len + 2];
		_itoa_s(A, pTmpCh, x2.len + 2, 10);
	}
	if (tmp.pCh) delete[]tmp.pCh;
	tmp.pCh = pTmpCh;
	tmp.len = strlen(tmp.pCh);
	cout << "DecStr operator - for const DecStr& x1 and const DecStr& x2" << endl;
	return tmp;
};