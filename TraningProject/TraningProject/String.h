#pragma once

class String
{
protected:
	int len;
	char* pCh;

public:
	String(int = 0);//Конструкторы класса String
	String(char);
	String(const char*);
	String(const String&);
	~String();//Деструктор
	//Методы класса String
	char* GetStr(void)const { return pCh; }
	int GetLen(void)const { return len; }
	void Show(void);
};