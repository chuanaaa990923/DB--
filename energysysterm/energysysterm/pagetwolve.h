#pragma once
#include "afxwin.h"


// pagetwolve �Ի���

class pagetwolve : public CDialogEx
{
	DECLARE_DYNAMIC(pagetwolve)

public:
	pagetwolve(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pagetwolve();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_one;
//	CEdit g_num;
//	int g_num;
//	int g_name;
	int g_user;
	CString g_name;
	CString m_password;
	int g_phone;
	CString g_adess;
	CString g_part;
	afx_msg void OnBnClickedOk();
};
