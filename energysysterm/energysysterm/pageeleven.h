#pragma once


// pageeleven �Ի���

class pageeleven : public CDialogEx
{
	DECLARE_DYNAMIC(pageeleven)

public:
	pageeleven(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pageeleven();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	virtual BOOL OnInitDialog();
};
