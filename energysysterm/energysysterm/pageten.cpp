// pageten.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "energysysterm.h"
#include "pageten.h"
#include "afxdialogex.h"


// pageten �Ի���

IMPLEMENT_DYNAMIC(pageten, CDialogEx)



BEGIN_MESSAGE_MAP(pageten, CDialogEx)
	ON_BN_CLICKED(IDOK, &pageten::OnBnClickedOk)
END_MESSAGE_MAP()


// pageten ��Ϣ�������


void pageten::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


BOOL pageten::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	//����ListctrlΪ������ʽ
	CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	DWORD dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
	SetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
	//����listctrl��������ѡ�����������
	DWORD styles = pmyListCtrl->GetExtendedStyle();
	pmyListCtrl->SetExtendedStyle(styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//��listctrl����5��������
	TCHAR rgtsz[5][10] = { _T("ʱ��"),_T("ˮ��"),_T("���"),_T("����"),_T("���ı�") };
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
