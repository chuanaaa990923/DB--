// pagetwolve.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pagetwolve.h"
#include "afxdialogex.h"
#include "EveryExtern.h"


// pagetwolve �Ի���

IMPLEMENT_DYNAMIC(pagetwolve, CDialogEx)

pagetwolve::pagetwolve(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG12, pParent)
	, g_user(0)
	, g_name(_T(""))
	, m_password(_T(""))
	, g_phone(0)
	, g_adess(_T(""))
	, g_part(_T(""))
{

}

pagetwolve::~pagetwolve()
{
}

void pagetwolve::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT8, m_one);
	//  DDX_Control(pDX, IDC_EDIT8, g_num);
	//  DDX_Text(pDX, IDC_EDIT8, g_num);
	//  DDX_Text(pDX, IDC_EDIT1, g_name);
	DDX_Text(pDX, IDC_EDIT8, g_user);
	DDX_Text(pDX, IDC_EDIT1, g_name);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	DDX_Text(pDX, IDC_EDIT5, g_phone);
	DDX_Text(pDX, IDC_EDIT6, g_adess);
	DDX_Text(pDX, IDC_EDIT7, g_part);
}


BEGIN_MESSAGE_MAP(pagetwolve, CDialogEx)
	ON_BN_CLICKED(IDOK, &pagetwolve::OnBnClickedOk)
END_MESSAGE_MAP()


// pagetwolve ��Ϣ�������


void pagetwolve::OnBnClickedOk()
{
	UpdateData(true);
	char query[255];
	MYSQL_RES *result;
	mysql_init(&m_sqlCon);
	mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0);

	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'225");
	sprintf_s(query, "insert into user(U_Number,U_Name,U_Pastkey,U_Phone,U_Address,U_Department,U_Worknumber) values('%d','%S','%S','%d','%S','%S','%S');", g_user,g_name, m_password, g_phone, g_adess, g_part, m_unumber);

	if (mysql_query(&m_sqlCon, query))  AfxMessageBox(_T("ע���û�ʧ��"));
	else AfxMessageBox(_T("ע���û��ɹ�"));
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
