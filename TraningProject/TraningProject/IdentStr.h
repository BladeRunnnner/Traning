#pragma once

#include "String.h"

class IdentStr :public String
{
public:
	IdentStr(int = 0);//???????????? ?????? IdentStr
	IdentStr(char);
	IdentStr(const char*);
	IdentStr(const IdentStr&);
	~IdentStr();//??????????

	//????????????? ????????? ?????? IdentStr
	IdentStr& operator = (const IdentStr&);
	char& operator[](int);
	IdentStr operator ~ ();
	friend IdentStr operator + (const IdentStr&, const IdentStr&);
	friend IdentStr operator + (const IdentStr&, const char*);
	friend IdentStr operator + (const char*, const IdentStr&);
};