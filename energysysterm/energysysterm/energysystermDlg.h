#include "pageone0.h"
#include "afxwin.h"
// energysystermDlg.h : ͷ�ļ�
//

#pragma once


// CenergysystermDlg �Ի���
class CenergysystermDlg : public CDialogEx
{
// ����
public:
	CenergysystermDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENERGYSYSTERM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeCombo1();
	CString User_id;
	CString User_password;
	afx_msg void OnEnChangeEdit2();
//	CString acc;
	CComboBox m_comboxa;
	afx_msg void OnEnChangeEdit1();
	int m_addd;
	afx_msg void OnStnClickedStaticaa();
};
