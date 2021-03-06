
// kopa.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CkopaApp:
// See kopa.cpp for the implementation of this class
//

class CkopaApp : public CWinApp
{
public:
	CkopaApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CkopaApp theApp;
