#pragma once


// pagethriteen �Ի���

class pagethriteen : public CDialogEx
{
	DECLARE_DYNAMIC(pagethriteen)

public:
	pagethriteen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pagethriteen();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_usernumber;
};
