// pageeleven.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pageeleven.h"
#include "afxdialogex.h"


// pageeleven �Ի���

IMPLEMENT_DYNAMIC(pageeleven, CDialogEx)

pageeleven::pageeleven(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG11, pParent)
{

}

pageeleven::~pageeleven()
{
}

void pageeleven::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(pageeleven, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &pageeleven::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &pageeleven::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &pageeleven::OnBnClickedButton7)
END_MESSAGE_MAP()


// pageeleven ��Ϣ�������


void pageeleven::OnBnClickedButton5()
{
	pagetwolve bbc;
	bbc.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void pageeleven::OnBnClickedButton6()
{
	pagethriteen bbc;
	bbc.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void pageeleven::OnBnClickedButton7()
{
	forteen bbc;
	bbc.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL pageeleven::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetDlgItem(IDC_STATICP)->SetWindowText(_T("sadasdsadsad"));
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
