#pragma once
#include "item.h"
#include "pch.h"
#include "framework.h"

#include "kopa.h"
#include "kopaDlg.h"
#include "afxdialogex.h"

#include "Apple.h"
#include "banana.h"

#include "product.h"
#include "listOfProduct.h"
#include "Doc.h"
#include "info.h"

#include <vector>
using std::vector;


//static item<> = { banana it ,Apple it };//no


static vector<item> AllItim{ banana() ,Apple() ,Apple() ,Apple() ,Apple() ,Apple() ,Apple() ,Apple() ,Apple() };


static void btnItems(item it, CListCtrl* m_listCtrl) {

	int nItem, i;
	
	bool have = false;//flag have
	CString tempCS = it._getName();

	for (i = 0; i < (*m_listCtrl).GetItemCount(); i++)
		if ((*m_listCtrl).GetItemText(i, NAME) == tempCS) {

			int x = (_ttoi((*m_listCtrl).GetItemText(i, AMOUNT))); //convert to int from cstring
			x++;
			tempCS.Format(L"%d", x);//covert to cstring
			(*m_listCtrl).SetItemText(i, AMOUNT, tempCS);//

			x = (_ttoi((*m_listCtrl).GetItemText(i, 4)));
			tempCS.Format(L"%d", x);//covert to cstring
			(*m_listCtrl).SetItemText(i, 4, tempCS);

			have = true;
			break;
		}
	if (!have)//add new product
	{
		tempCS.Format(L"%d", ((int)(*m_listCtrl).GetItemCount() + 1));

		nItem = (*m_listCtrl).InsertItem(0, tempCS);
		(*m_listCtrl).SetItemText(nItem, NAME, it._getName());
		(*m_listCtrl).SetItemText(nItem, DEPARTMET, it._getDEPARTMENT());

		(*m_listCtrl).SetItemText(nItem, AMOUNT, L"1");
		tempCS.Format(L"%d", ((int)it._getPrice()));
		(*m_listCtrl).SetItemText(nItem, PRICE, tempCS);
	}

}

template <typename T>//try
static void addToList( CListCtrl* m_listCtrl) {
	T it;
	btnItems(it, m_listCtrl);

}


static void sendItemes(int *arr, CListCtrl* m_listCtrl) {

	for (int i = 0, j ; i < NUM; i++)//**
	{
		j = 0;

		while (j < arr[i])//now mach itimes have
		{
			item it = AllItim[i];
			btnItems(it, m_listCtrl);
			j++;
		}
		
	}
}





