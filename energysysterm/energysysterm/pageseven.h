#pragma once


// pageseven �Ի���

class pageseven : public CDialogEx
{
	DECLARE_DYNAMIC(pageseven)

public:
	pageseven(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pageseven();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_idnum;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
