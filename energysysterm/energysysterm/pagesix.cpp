// pagesix.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pagesix.h"
#include "afxdialogex.h"
#include "EveryExtern.h"


// pagesix �Ի���

IMPLEMENT_DYNAMIC(pagesix, CDialogEx)

pagesix::pagesix(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

pagesix::~pagesix()
{
}

void pagesix::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(pagesix, CDialogEx)
	ON_STN_CLICKED(IDC_STATICA, &pagesix::OnStnClickedStatica)
END_MESSAGE_MAP()


// pagesix ��Ϣ�������


void pagesix::OnStnClickedStatica()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}





BOOL pagesix::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	MYSQL_RES *result;
	mysql_init(&m_sqlCon);
	mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
	mysql_query(&m_sqlCon, "select P_Price from price");
	result = mysql_store_result(&m_sqlCon);
	CString a,b,c;
	for (int ttt = 0;ttt <= 2; ttt++)
	{
		row = mysql_fetch_row(result);
		if(ttt==0)  a = row[0];
		if (ttt == 1)b = row[0];
		if (ttt == 2)c = row[0];
	}

	GetDlgItem(IDC_STATICA)->SetWindowText(a);
	GetDlgItem(IDC_STATICB)->SetWindowText(b);
	GetDlgItem(IDC_STATICC)->SetWindowText(c);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
