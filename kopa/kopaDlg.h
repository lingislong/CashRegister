
// kopaDlg.h : header file
//


#pragma once

// CkopaDlg dialog
class CkopaDlg : public CDialogEx
{
// Construction
public:
	CkopaDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KOPA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void bananaButton();
	CListCtrl m_listCtrl;
	afx_msg void saveList();
	afx_msg void OnBnClickedOk();
	afx_msg void deleteItem_btn();
	afx_msg void AppleButton();
	afx_msg void deleteAll_btn();
	afx_msg void OnBnClickedCancel();
	afx_msg void loadMyList();
	afx_msg void OnBnClickedButton7();
};
