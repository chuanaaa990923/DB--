#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// pagefive �Ի���

class pagefive : public CDialogEx
{
	DECLARE_DYNAMIC(pagefive)

public:
	pagefive(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pagefive();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	int ssdasd;
	afx_msg void OnLbnSelchangeList1();
//	CListBox m_listboxone;
	virtual BOOL OnInitDialog();
	CListCtrl m_listboxone;
};
