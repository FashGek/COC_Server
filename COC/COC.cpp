
// COC.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "COC.h"
#include "COCDlg.h"
#include "MainDoc.h"
#include "INI.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCOCApp

BEGIN_MESSAGE_MAP(CCOCApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCOCApp ����

CCOCApp::CCOCApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	m_pMainDoc = new CMainDoc(); 
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCOCApp ����

CCOCApp theApp;


// CCOCApp ��ʼ��

BOOL CCOCApp::InitInstance()
{
	//��ֹ�����ظ�����

	HANDLE hMutex=CreateMutexW(NULL,TRUE,L"clash of clans server");   

	if(hMutex)   
	{   
		if(ERROR_ALREADY_EXISTS==GetLastError()){   
			AfxMessageBox(IDS_ALREADY_RUNNING);   
			return FALSE;   
		}   
	} 
	  
	if (m_pMainDoc->m_INI.m_skinPath.Compare("")!=0){

		skinppLoadSkin((LPSTR)(LPCTSTR)m_pMainDoc->m_INI.m_skinPath);
	} 
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CCOCDlg dlg;
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

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}



int CCOCApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	if(m_pMainDoc->m_INI.m_skinPath != _T("NULL"))
		skinppRemoveSkin();
	delete m_pMainDoc;
	return CWinApp::ExitInstance();
}
