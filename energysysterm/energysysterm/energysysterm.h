
#include "pageone0.h"
#include "pagelogin.h"
#include "pagethree0.h"
#include "pagefore.h"
#include "pagefive.h"
#include "pagesix.h"
#include "pageseven.h"
#include "pageseven.h"
#include "pageeight.h"
#include "pagenine.h"
//#include "pageten.h"
#include "pageeleven.h"
#include "pagetwolve.h"
#include "pagethriteen.h"
#include "forteen.h"
#include "mysql.h"
#include "winsock.h" 


// energysysterm.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�

//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CenergysystermApp: 
// �йش����ʵ�֣������ energysysterm.cpp
//

class CenergysystermApp : public CWinApp
{
public:
	CenergysystermApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CenergysystermApp theApp;