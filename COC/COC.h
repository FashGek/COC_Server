
// COC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "SkinPPWTL.h" 
#include "Global.h"
// CCOCApp:
// �йش����ʵ�֣������ COC.cpp
//
class CMainDoc;

class CCOCApp : public CWinApp
{
public:
	CCOCApp();

	CMainDoc*				m_pMainDoc;

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
private: 
	DECLARE_MESSAGE_MAP()
public:
	virtual int ExitInstance();
};

extern CCOCApp theApp;