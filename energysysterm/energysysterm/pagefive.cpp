// pagefive.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pagefive.h"
#include "afxdialogex.h"
#include"EveryExtern.h"


// pagefive �Ի���

IMPLEMENT_DYNAMIC(pagefive, CDialogEx)

pagefive::pagefive(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
//	, ssdasd(0)
{

}

pagefive::~pagefive()
{
}

void pagefive::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_LBIndex(pDX, IDC_LIST1, ssdasd);
	//  DDX_Control(pDX, IDC_LIST1, m_listboxone);
	DDX_Control(pDX, IDC_LIST1, m_listboxone);
}


BEGIN_MESSAGE_MAP(pagefive, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &pagefive::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &pagefive::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// pagefive ��Ϣ�������


void pagefive::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void pagefive::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL pagefive::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��




		//����ListctrlΪ������ʽ
		CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
		DWORD dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
		SetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
		//����listctrl��������ѡ�����������
		DWORD styles = pmyListCtrl->GetExtendedStyle();
		pmyListCtrl->SetExtendedStyle(styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		//��listctrl����5��������
		TCHAR rgtsz[5][100] = { _T("ʱ��"),_T("ˮ��"),_T("���"),_T("����"),_T("���ı�") };
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


		char query[100];
		MYSQL_RES *result;
		mysql_init(&m_sqlCon);
		mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0);
		mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
		sprintf_s(query, "Select R_Time, R_Water, R_Electric, R_Gas,R_Change From Recorder Where R_Number='%S'; ", m_unumber);
		mysql_query(&m_sqlCon, query);
		result=mysql_use_result(&m_sqlCon);
		int i = 0;
		while (row = mysql_fetch_row(result))
		{

	        m_listboxone.InsertItem(i, (CString)row[0]);
			m_listboxone.SetItemText(i, 1, (CString)row[1]);
			m_listboxone.SetItemText(i, 2, (CString)row[2]);
			m_listboxone.SetItemText(i, 3, (CString)row[3]);
			m_listboxone.SetItemText(i, 4, (CString)row[4]);
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
		
	


	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
