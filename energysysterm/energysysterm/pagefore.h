#pragma once


// pagefore �Ի���

class pagefore : public CDialogEx
{
	DECLARE_DYNAMIC(pagefore)

public:
	pagefore(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~pagefore();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	float g_money;
	int g_money;
};
