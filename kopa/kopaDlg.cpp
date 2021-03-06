
// kopaDlg.cpp : implementation file
//

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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CAboutDlg dialog used for App About
listOfProduct myList;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CkopaDlg dialog



CkopaDlg::CkopaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KOPA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkopaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}

BEGIN_MESSAGE_MAP(CkopaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CkopaDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CkopaDlg::bananaButton)
	ON_BN_CLICKED(IDC_BUTTON2, &CkopaDlg::saveList)
	ON_BN_CLICKED(IDOK, &CkopaDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CkopaDlg::deleteItem_btn)
	ON_BN_CLICKED(IDC_BUTTON4, &CkopaDlg::AppleButton)
	ON_BN_CLICKED(IDC_BUTTON5, &CkopaDlg::deleteAll_btn)
	ON_BN_CLICKED(IDCANCEL, &CkopaDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON6, &CkopaDlg::loadMyList)
	ON_BN_CLICKED(IDC_BUTTON7, &CkopaDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CkopaDlg message handlers

BOOL CkopaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}

		// Ask Mfc to create/insert a column

		m_listCtrl.InsertColumn(NAME, L"Name", LVCFMT_LEFT, 100);
		m_listCtrl.InsertColumn(DEPARTMET, L"Department", LVCFMT_LEFT, 200);
		m_listCtrl.InsertColumn(AMOUNT, L"Amount", LVCFMT_LEFT, 100);
		m_listCtrl.InsertColumn(PRICE, L"Price per unit", LVCFMT_LEFT, 200);

		m_listCtrl.InsertColumn(
			ID,              // Rank/order of item 
			L"#",          // Caption for this header 
			LVCFMT_LEFT,    // Relative position of items under header 
			100);           // Width of items under header

		//// Set the icon for this dialog.  The framework does this automatically
		////  when the application's main window is not a dialog
		//SetIcon(m_hIcon, TRUE);			// Set big icon
		//SetIcon(m_hIcon, FALSE);		// Set small icon


		return TRUE;  // return TRUE  unless you set the focus to a control
	}

	return TRUE; 
}

void CkopaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CkopaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CkopaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CkopaDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	*pResult = 0;
}


void CkopaDlg::loadMyList()
{
	int* temparr = myList.loadMyList();
	m_listCtrl.DeleteAllItems();
	sendItemes(temparr, &m_listCtrl);
}

void CkopaDlg::saveList()
{
	if (myList.saveMyList())
	{
		//no save er
	}
	else {} //save

}

void CkopaDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();//*****see new windo
}


void CkopaDlg::OnBnClickedCancel()
{
	//***** diallog box ask to save if not
	CDialogEx::OnCancel();
}

void CkopaDlg::deleteAll_btn()
{
	m_listCtrl.DeleteAllItems();
	myList.resst();
	//*****ask if soo	
	
}

void CkopaDlg::deleteItem_btn()
{
	int index = m_listCtrl.GetSelectionMark();
	myList.removeItem(_ttoi(m_listCtrl.GetItemText(index, 0)));//remove from arr
	m_listCtrl.DeleteItem(index);//remove from list
}

void CkopaDlg::bananaButton()
{
	myList.add(1);//add to arry
	addToList<banana>(&m_listCtrl);//add to list - templat//newone 
}

void CkopaDlg::AppleButton()
{
	//old one
	/*Apple it;

	myList.add(it.id);
	btnItems(it, &m_listCtrl);*/

	myList.add(2);
	addToList<Apple>(&m_listCtrl);
}


void CkopaDlg::OnBnClickedButton7()
{
	
}
