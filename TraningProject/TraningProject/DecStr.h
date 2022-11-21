#pragma once

#include "String.h"

class DecStr :public String
{
public:
	DecStr(int = 0);//Конструкторы класса DecStr
	DecStr(char);
	DecStr(const char*);
	DecStr(const DecStr&);
	~DecStr();//Деструктор
	//Дружественные операторы класса DecStr
	DecStr& operator = (const DecStr&);
	friend DecStr operator + (const DecStr&, const DecStr&);
	friend DecStr operator + (const DecStr&, const int);
	friend DecStr operator + (const int, const DecStr&);
	friend DecStr operator - (const DecStr&, const DecStr&);
};