
// energysysterm.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "energysysterm.h"
#include "energysystermDlg.h"
#include "afxdialogex.h"
#include "Every.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CenergysystermApp

BEGIN_MESSAGE_MAP(CenergysystermApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CenergysystermApp ����

CenergysystermApp::CenergysystermApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CenergysystermApp ����

CenergysystermApp theApp;


// CenergysystermApp ��ʼ�� 

BOOL CenergysystermApp::InitInstance()
{	

	mysql_init(&m_sqlCon);
	//localhost:������ root/123456Ϊ�˺����� managesystemdbΪ���ݿ��� 3306Ϊ�˿�  
	if (!mysql_real_connect(&m_sqlCon, "localhost", "root", NULL, "tpch", 3306, NULL, 0))
	{
		AfxMessageBox(_T("�������ݿ�ʧ��!"));
		//CString e = mysql_error(&m_sqlCon);//��Ҫ����Ŀ�������ַ����޸�Ϊ��ʹ�ö��ֽ��ַ�������δ���á�
		//MessageBox(e);
		//return;
	}
	else
	{
		AfxMessageBox(_T("���ݿ����ӳɹ�!"));
		mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");//��������ݿ��ж�ȡ���ݺ���������ʾ������
	}

	while (TRUE)
	{

		pagelogin one_dialog;
		pageeight two_dialog;
		pageone0 three_dialog;
		pageeleven fore_dialog;
		CenergysystermDlg login_Dialog;
		CString str_User;
		CString str_Password;
		CString str_Have;
		MYSQL_RES *result;
		int kkk = 0;
		int ooo = 0;

		//ģ̬�Ի���  
		int nReturn = login_Dialog.DoModal();//����IDOK��IDCANCEL��������ص���IDCANCEL����Ҫ����WindowsCommDlgExtendedError������ȷ���Ƿ�����һ������IDOK��IDCANCEL���ǳ������������û�ѡ�����OK��ť����Cancel��ť  

		if (nReturn == IDCANCEL)
		{//���ȡ��  
			return FALSE;
		}
		if (nReturn == IDOK)//���ȷ��  
		{
			str_User = login_Dialog.User_id;
			str_Password = login_Dialog.User_password;
		}
		int m_choose = login_Dialog.m_addd;
		if (m_choose == 1)
		{
			mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
			mysql_query(&m_sqlCon, "select U_Pastkey,U_Number,U_name,U_Money from user");
		}
		else
		{
			mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
			mysql_query(&m_sqlCon, "select L_Pastkey,L_Worknumber,L_Permission,L_Permission from limited");
		}

		result = mysql_store_result(&m_sqlCon);
		row = NULL;

		//�ظ���ȡ�У������ݷ����б��У�ֱ��rowΪNULL
		do
		{
			//	int cols = mysql_num_fields(result);
			//	for (int rols = 0; rols < cols; rols++)
			//	{
			//	}
			if (ooo != 0)
			{
				if (str_User == row[1] && str_Password == row[0])
				{
					kkk = 1;
					if (!(m_choose == 1)) str_Have = row[2];
					break;
				}
				
			}
			ooo++;
		} while (row = mysql_fetch_row(result));
		if (kkk == 1)
		{	
			
			//mysql_close(&m_sqlCon);
			m_unumber = row[1];
			m_uname = row[2];
			m_umoney = row[3];

			if (m_choose == 1)one_dialog.DoModal();          //�û�
			else if (str_Have == "2") two_dialog.DoModal();
			else if (str_Have == "0") three_dialog.DoModal();
			else  fore_dialog.DoModal();
			break;
		}
		else  MessageBox(NULL, _T("�û�ID���������\n ���������룡"), _T("��¼ʧ�ܣ�"), MB_OKCANCEL | MB_ICONERROR);

	}


	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

/*	CenergysystermDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}
*/


#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

