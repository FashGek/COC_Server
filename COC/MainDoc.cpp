/*
*MainDoc.cpp
*
*2011-08
*
*
*/

#include "stdafx.h"
#include "Global.h"
/*
*although i don't  use marco in resource.h file, if i don't include this file,
*complier would remind of error.
*/
#include "resource.h"	
#include "MainDoc.h" 
#include "INI.h"

CMainDoc::CMainDoc()
{ 
	m_pINI = new CINI();
	ASSERT( m_pINI != NULL ); 
	m_host="";
	Init();
	 
}

CMainDoc::~CMainDoc()
{
	UnInit(); 
}

void
CMainDoc::Init()
{  
	
	//��ʼ������������Ϣ
	m_INI.m_autoStart=0;  
	m_INI.m_popUp=0;
	m_INI.m_AutoType=0;
	m_INI.m_skinPath=_T("");
	m_INI.m_usrINIPath=_T("");
	if ( m_pINI->GetValid() == TRUE){
		ReadINIInfo();
	} 
}
void
CMainDoc::UnInit()
{
	//д�ļ�����
	WriteINIInfo(); 
}
void
CMainDoc::ReadINIInfo()
{
	 
	int inVal;
	CString inStr;
	//��ȡ�û������ļ�·��
	if (m_pINI->GetStrVal(appName, g_INI[INI_USR_PATH], inStr) == TRUE){
			m_INI.m_usrINIPath = inStr;
	}
	else{
		m_INI.m_usrINIPath = _T("");
	}
// ///////////////////////////////////////////////////////////
	//modify by luwei
	if (m_INI.m_usrINIPath == _T(""))
	{
		m_pINI->SetValid(FALSE);
		return;
	}

	if (m_pINI->IsFileExist(m_INI.m_usrINIPath) == FALSE)
	{
		m_INI.m_usrINIPath = _T("");
		m_pINI->SetValid(FALSE);
		return;
	}

	//���û������ļ��»�ȡ����
	m_pINI->SetValid(TRUE);

	//��ȡ������������Ϣ
	if (m_pINI->GetIntVal(appName, g_INI[INI_AUTO_START], m_INI.m_usrINIPath, inVal) == TRUE){
			m_INI.m_autoStart = inVal;
	}
	else{
		m_INI.m_autoStart = FALSE;
	}
	
	//��ȡ�Ƿ񵯳�������ʾ��Ϣ
	if (m_pINI->GetIntVal(appName, g_INI[INI_POP_UP_NOTIFY], m_INI.m_usrINIPath , inVal) == TRUE){
		m_INI.m_popUp = inVal;
	}
	else{
		m_INI.m_popUp = FALSE;
	}
	 
	 
	//////////////////////////////////////////////////////////////////////////////////////
	//add by luwei
	//��ȡ�Զ�����������Ϣ
	if (m_pINI->GetIntVal(appName, g_INI[INI_AUTO_TYPE], m_INI.m_usrINIPath , inVal) == TRUE){
		m_INI.m_AutoType = inVal;
	}
	else{
		m_INI.m_AutoType = 0;
	}

	//��ȡƤ��������Ϣ
	if (m_pINI->GetStrVal(appName, g_INI[INI_SKIN_PATH], m_INI.m_usrINIPath , inStr) == TRUE){
		m_INI.m_skinPath = inStr;
	}
	else{
		m_INI.m_skinPath = _T("");
	}
	 
}


void
CMainDoc::WriteINIInfo()
{
	 
	if ( m_INI.m_usrINIPath == _T("") )
	{
		if (MessageBox(NULL,IDS_CONFIG_MISSING, NULL, MB_OKCANCEL) == IDOK){
			m_INI.m_usrINIPath = m_pINI->CreateINI(m_host);
			m_pINI->WriteVal(appName, g_INI[INI_USR_PATH],m_INI.m_usrINIPath);
		}
		else{
			AfxMessageBox(IDS_SAVE_FAILED);
			return;
		}
	}
	if (m_pINI->IsFileExist(m_INI.m_usrINIPath) == FALSE)
	{
		AfxMessageBox(IDS_SAVE_FAILED);
		return;
	}
	//д���û������ļ�·����Ϣ
	m_pINI->WriteVal(appName, g_INI[INI_USR_PATH], m_INI.m_usrINIPath);
	//д�뿪��������Ϣ
	switch(m_INI.m_autoStart)
	{
	case TRUE:
		m_pINI->WriteVal(appName, g_INI[INI_AUTO_START], m_INI.m_usrINIPath, _T("1"));
		break;
	
	case FALSE:
		m_pINI->WriteVal(appName, g_INI[INI_AUTO_START], m_INI.m_usrINIPath, _T("0"));
		break;

	default:
		break;
	}
	//д���Ƿ񵯳�������ʾ��Ϣ
	switch(m_INI.m_popUp)
	{
	case TRUE:
		m_pINI->WriteVal(appName, g_INI[INI_POP_UP_NOTIFY], m_INI.m_usrINIPath, _T("1"));
		break;

	case FALSE:
		m_pINI->WriteVal(appName, g_INI[INI_POP_UP_NOTIFY], m_INI.m_usrINIPath, _T("0"));
		break;

	default:
		break;
	}
	 
	/////////////////////////////////////////////////////////////////////////////////
	//add by luwei
	//д���Զ���������
	switch(m_INI.m_AutoType)
	{
	case 0:
		m_pINI->WriteVal(appName, g_INI[INI_AUTO_TYPE], m_INI.m_usrINIPath, _T("0"));
		break;
		
	case 1:
		m_pINI->WriteVal(appName, g_INI[INI_AUTO_TYPE], m_INI.m_usrINIPath, _T("1"));
		break;
	 
	default:
		break;
	}

	//д��Ƥ���ļ�·��
	m_pINI->WriteVal(appName, g_INI[INI_SKIN_PATH],m_INI.m_skinPath);
	m_pINI->WriteVal(appName, g_INI[INI_SKIN_PATH], m_INI.m_usrINIPath,(LPSTR)(LPCTSTR)m_INI.m_skinPath);
	 
}
 