#pragma once
#include "afxcmn.h"


// forteen �Ի���

class forteen : public CDialogEx
{
	DECLARE_DYNAMIC(forteen)

public:
	forteen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~forteen();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG14 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listctrlaaa;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
};
