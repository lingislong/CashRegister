//virtoal class//
#pragma once
#include "pch.h"
#include "framework.h"
#include "kopa.h"
#include "kopaDlg.h"
#include "afxdialogex.h"


//template<class T>
class product
{
public:

	virtual ~product() {};
	virtual CString _getName() = 0;
	virtual CString _getDEPARTMENT() = 0;
	virtual double _getPrice() = 0;
	virtual double _getWeight() = 0;
	virtual int _getAmount() = 0;
	virtual void _incAmount() = 0;

};

