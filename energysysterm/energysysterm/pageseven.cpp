// pageseven.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pageseven.h"
#include "afxdialogex.h"
#include "EveryExtern.h"


// pageseven �Ի���

IMPLEMENT_DYNAMIC(pageseven, CDialogEx)

pageseven::pageseven(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG7, pParent)
	, m_idnum(0)
{

}

pageseven::~pageseven()
{
}

void pageseven::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_idnum);
}


BEGIN_MESSAGE_MAP(pageseven, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &pageseven::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &pageseven::OnBnClickedButton2)
END_MESSAGE_MAP()


// pageseven ��Ϣ�������


void pageseven::OnBnClickedButton1()
{

	UpdateData(true);
	char query[255];
	MYSQL_RES *result;
	mysql_init(&m_sqlCon);
	mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
	sprintf_s(query, "delete from limited where L_Worknumber=%d", m_idnum);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void pageseven::OnBnClickedButton2()
{
	UpdateData(true);
	char* add;
	char query[255];
	MYSQL_RES *result;
	mysql_init(&m_sqlCon);
	mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
	sprintf_s(query, "select L_Permission from limited where L_Worknumber=%d", m_idnum);
	mysql_query(&m_sqlCon, query);
	result = mysql_store_result(&m_sqlCon);
	row = mysql_fetch_row(result);
	if(row == NULL)	 AfxMessageBox(_T("���û�������"));
	else
	{
		add = row[0];
	    if (strcmp(add,"2")) AfxMessageBox(_T("���û�Ȩ��Ϊ����Ա"));
	    else if (strcmp(add, "0")) AfxMessageBox(_T("���û�Ȩ��Ϊ��Դ��˾"));
	    else  AfxMessageBox(_T("���û�Ȩ��ΪԱ��"));
	}


	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
