// pagethriteen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pagethriteen.h"
#include "afxdialogex.h"


// pagethriteen �Ի���

IMPLEMENT_DYNAMIC(pagethriteen, CDialogEx)

pagethriteen::pagethriteen(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG13, pParent)
	, m_usernumber(0)
{

}

pagethriteen::~pagethriteen()
{
}

void pagethriteen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_usernumber);
}


BEGIN_MESSAGE_MAP(pagethriteen, CDialogEx)
END_MESSAGE_MAP()


// pagethriteen ��Ϣ�������
