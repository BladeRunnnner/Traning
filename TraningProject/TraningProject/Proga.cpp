#include "String.h"
#include "IdentStr.h"
#include "DecStr.h"
#include <iostream>

using namespace std;

int main()
{

	//לגלגלûגגלûגלûגלûגל
	//ûגלûגלûגלûגלûגלûגלû
	//ûגלûגלûגלûגלûגלûגל
	//sdfsdfsdfsdfsdfsdfsd
	//sdfsdfsdfsdfsdfsdfsd
	//sdfsdfsdfsdfsdfsdfsdf

	setlocale(LC_ALL, "Russian");

	String obj("FBIT");
	obj.Show();
	String obj1 = obj;
	obj1.Show();
	cout << obj1.GetStr() << endl;
	String obj2('F');
	obj2.Show();
	cout << obj2.GetLen() << endl;
	cout << obj1.GetStr() << endl;
	cout << obj2.GetStr() << endl;
	cout << obj2.GetLen() << endl;
	IdentStr obj3("FBIT");
	obj3.Show();
	IdentStr obj4("1FBIT");
	obj4.Show();
	IdentStr obj5('V');
	obj5.Show();
	IdentStr obj6('_');
	obj6.Show();
	IdentStr obj7("case");
	obj7.Show();
	IdentStr obj8 = "FBIT";
	obj8.Show();
	IdentStr obj9("ITMO");
	obj8 = obj9;
	obj8.Show();
	obj8 = obj9 = "N3153";
	obj8.Show();
	obj8[3] = 'X';
	obj8.Show();
	obj8[0] = '9';
	obj8.Show();
	IdentStr obj11 = ~obj9;
	obj11.Show();
	obj9 = ~obj8;
	obj9.Show();
	IdentStr test{ "tyuio5" };
	test.Show();
	test = ~test;
	test.Show();
	IdentStr obj12{ "N3153" };
	IdentStr obj13{ "FBIT" };
	obj13 = obj13 + obj12;
	obj13.Show();
	DecStr obj17("065535");
	DecStr obj18("-2147483648");
	obj18.Show();
	DecStr obj19("65535");
	obj19 = obj19 + 65535;
	obj19.Show();
	DecStr obj20("-2147483648");
	obj20 = obj20 + (-2);
	obj20.Show();
	DecStr obj21("2147483647");
	obj21 = obj21 + 1;
	obj21.Show();
	DecStr obj22("+65535");
	obj22 = obj22 + 65535535;
	obj20.Show();

	String** ptrs = new String * [6];
	ptrs[0] = new String("FBIT");
	ptrs[1] = new String("constructurs");
	ptrs[2] = new IdentStr("GoodMorning");
	ptrs[3] = new IdentStr("Good_Night");
	ptrs[4] = new DecStr("123");
	ptrs[5] = new DecStr("80");

	ptrs[0]->Show();
	String* obj100 = dynamic_cast <String*>(ptrs[0]); //הטםאלטקוסךמו ןנטגוהוםטו עטןא 
	obj100->Show();
	//Stroka* obj200 = dynamic_cast <Stroka*>(ptrs[1]);
	//*(obj100) = *(obj200);
	//obj100->Show();

	((IdentStr*)ptrs[2])->Show();
	//((IdentStr*)ptrs[3])->Show();
	((DecStr*)ptrs[4])->Show();
	//((DecStr*)ptrs[5])->Show();

	delete[] ptrs; //מקטסעךא ptrs 

	return 0;
}