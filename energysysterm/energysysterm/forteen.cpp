// forteen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "energysysterm.h"
#include "forteen.h"
#include "afxdialogex.h"
#include"EveryExtern.h"


// forteen �Ի���

IMPLEMENT_DYNAMIC(forteen, CDialogEx)

forteen::forteen(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG14, pParent)
{

}

forteen::~forteen()
{
}

void forteen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_listctrlaaa);
}


BEGIN_MESSAGE_MAP(forteen, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &forteen::OnLvnItemchangedList2)
END_MESSAGE_MAP()


// forteen ��Ϣ�������


BOOL forteen::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	//����ListctrlΪ������ʽ
	CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
	DWORD dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
	SetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
	//����listctrl��������ѡ�����������
	DWORD styles = pmyListCtrl->GetExtendedStyle();
	pmyListCtrl->SetExtendedStyle(styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//��listctrl����5��������
	TCHAR rgtsz[9][100] = { _T("���"),_T("����Ա"),_T("����"),_T("��˾"),_T("����"),_T("�绰"),_T("��ַ"),_T("����"),_T("���") };
	//�޸������С������ȷ����������û�����ȣ�����޸���������ݣ���ɫ���֣�ҲҪ���Ÿı�
	LV_COLUMN lvcolumn;
	CRect rect;
	pmyListCtrl->GetWindowRect(&rect);
	for (int i = 0; i<5; i++)
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT
			| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = rgtsz[i];
		lvcolumn.iSubItem = i;
		lvcolumn.iOrder = i;
		lvcolumn.cx = rect.Width() / 5;
		pmyListCtrl->InsertColumn(i, &lvcolumn);
	}

	char query[312];
	int i = 0;
	MYSQL_RES *result;
	mysql_init(&m_sqlCon);
	mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0);
	mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
	sprintf_s(query, "select * from user;");
	mysql_query(&m_sqlCon, query);
	result = mysql_store_result(&m_sqlCon);


	while (row = mysql_fetch_row(result))
	{

		m_listctrlaaa.InsertItem(i, (CString)row[0]);
		m_listctrlaaa.SetItemText(i, 1, (CString)row[1]);
		m_listctrlaaa.SetItemText(i, 2, (CString)row[2]);
		m_listctrlaaa.SetItemText(i, 3, (CString)row[3]);
		m_listctrlaaa.SetItemText(i, 4, (CString)row[4]);
		m_listctrlaaa.SetItemText(i, 5, (CString)row[5]);
		m_listctrlaaa.SetItemText(i, 6, (CString)row[6]);
		m_listctrlaaa.SetItemText(i, 7, (CString)row[7]);
		m_listctrlaaa.SetItemText(i, 8, (CString)row[8]);
		i++;
	}


	/*ifstream input("manager.dat");     //�������Լ���Ҫ�Ķ��ļ�����
	Manager manager;
	input.read((char *)&manager, sizeof(manager));
	while (input)
	{
	i = 0;
	CString strText;
	if (manager.tag == '#')
	{
	strText.Format(TEXT("%d"), manager.number);
	// Insert the item, select every other item.
	pmyListCtrl->InsertItem(LVIF_TEXT | LVIF_STATE, i, strText,
	(i % 2) == 0 ? LVIS_SELECTED : 0, LVIS_SELECTED, 0, 0);
	// Initialize the text of the subitems.

	strText.Format("%s", manager.name);          //�������Ҫ��������������ݣ�ע������
	pmyListCtrl->SetItemText(i, 1, strText);
	strText.Format("%s", manager.sex);
	pmyListCtrl->SetItemText(i, 2, strText);
	strText.Format("%d", manager.age);
	pmyListCtrl->SetItemText(i, 3, strText);
	strText.Format("%d", manager.year);
	pmyListCtrl->SetItemText(i, 4, strText);
	}
	input.read((char *)&manager, sizeof(manager));
	};
	input.close();*/
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void forteen::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
