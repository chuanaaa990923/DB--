#pragma once


// pagesix �Ի���

class pagesix : public CDialogEx
{
	DECLARE_DYNAMIC(pagesix)

public:
	pagesix(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pagesix();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStatica();
	virtual BOOL OnInitDialog();
};

