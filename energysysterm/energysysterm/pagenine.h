#pragma once
#include "afxcmn.h"


// pagenine �Ի���

class pagenine : public CDialogEx
{
	DECLARE_DYNAMIC(pagenine)

public:
	pagenine(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pagenine();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl c_listone;
};
