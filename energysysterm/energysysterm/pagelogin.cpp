// pagelogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pagelogin.h"
#include "afxdialogex.h"
#include "pageone0.h"
#include "EveryExtern.h"

// pagelogin �Ի���

IMPLEMENT_DYNAMIC(pagelogin, CDialogEx)

pagelogin::pagelogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

pagelogin::~pagelogin()
{
}

void pagelogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(pagelogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &pagelogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &pagelogin::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &pagelogin::OnBnClickedButton3)
END_MESSAGE_MAP()


// pagelogin ��Ϣ�������


void pagelogin::OnBnClickedButton1()
{
	pagefore bbc;
	bbc.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void pagelogin::OnBnClickedButton2()
{
	pagefive bbc;
	bbc.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void pagelogin::OnBnClickedButton3()
{
	pagesix bbc;
	bbc.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



BOOL pagelogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_STATICH)->SetWindowText(m_uname);
	GetDlgItem(IDC_STATICI)->SetWindowText(m_umoney);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
