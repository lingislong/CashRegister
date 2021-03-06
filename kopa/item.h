#pragma once
#include "product.h"

class item :public product
{
public:
	int _Amount;
	int _PRICE;
	double _Weight;
	CString _DEPARTMENT;
	CString _NAME;
	int _id;
	
	CString _getName();
	CString _getDEPARTMENT();
	double _getPrice();
	double _getWeight();//
	int _getAmount();
	int _getID();
	void _incAmount();
};