/*
*Type.h
*
*2011-08
*
*
*/
#ifndef _TYPE_H_
#define _TYPE_H_

    
typedef struct tagINIFile
{
	BOOL	m_autoStart;		//���������� 
	BOOL	m_popUp;			//�������� 
	CString m_usrINIPath;		//�û������ļ�·�� 
	int		m_AutoType;			//�Զ���������
	CString m_skinPath;
}INI;
 

typedef int (__stdcall *InstallHook)(HWND vRecieveWindow);
typedef BOOL (*UnHook)(); 




#endif