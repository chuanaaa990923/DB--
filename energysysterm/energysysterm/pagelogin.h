#pragma once


// pagelogin �Ի���

class pagelogin : public CDialogEx
{
	DECLARE_DYNAMIC(pagelogin)

public:
	pagelogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pagelogin();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	virtual BOOL OnInitDialog();
};
