#include "pch.h"
#include "item.h"

CString item::_getName()//const
{
	return _NAME;
}

CString item::_getDEPARTMENT()
{
	return _DEPARTMENT;
}

double item::_getPrice()
{
	return _PRICE;
}

double item::_getWeight()
{
	return _Weight;
}

int item::_getAmount()
{
	return _Amount;
}

int item::_getID()
{
	return _id;
}

void item::_incAmount()
{
	_Amount++;

}
