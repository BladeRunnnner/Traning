#pragma once

#include "String.h"

class IdentStr :public String
{
public:
	IdentStr(int = 0);//Конструкторы класса IdentStr
	IdentStr(char);
	IdentStr(const char*);
	IdentStr(const IdentStr&);
	~IdentStr();//Деструктор

	//Дружественные операторы класса IdentStr
	IdentStr& operator = (const IdentStr&);
	char& operator[](int);
	IdentStr operator ~ ();
	friend IdentStr operator + (const IdentStr&, const IdentStr&);
	friend IdentStr operator + (const IdentStr&, const char*);
	friend IdentStr operator + (const char*, const IdentStr&);
};