#pragma once


// pageeight �Ի���

class pageeight : public CDialogEx
{
	DECLARE_DYNAMIC(pageeight)

public:
	pageeight(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pageeight();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	//afx_msg void OnBnClickedButton4();
};
