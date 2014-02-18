// SettingDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "COC.h"
#include "SettingDlg.h"
#include "afxdialogex.h" 
#include "COCDlg.h" 
#include "MainDoc.h"
#include "INI.h"
#include "Global.h" 

// CSettingDlg �Ի���

IMPLEMENT_DYNAMIC(CSettingDlg, CDialogEx)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingDlg::IDD, pParent)
	, m_autoStart(FALSE)
	, m_pop(FALSE) 
	, m_skinPath(_T(""))
	,m_contentChanged(FALSE)
	, m_radioValue(0)
{
	//m_autoMessage = RegisterWindowMessage(TEXT("QueryCancelAutoPlay"));
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_autoStart);
	DDX_Check(pDX, IDC_CHECK2, m_pop); 
	DDX_Text(pDX, IDC_EDIT1, m_skinPath);
	DDX_Radio(pDX, IDC_RADIO1, m_radioValue);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSettingDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CSettingDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CSettingDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CSettingDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK1, &CSettingDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CSettingDlg ��Ϣ�������


void CSettingDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);  
	// TODO: Add your control notification handler code here

	CCOCDlg* pMain  = (CCOCDlg*)AfxGetApp()->m_pMainWnd; 
	CMainDoc* pDoc	 = pMain->m_pMainDoc;
	CINI* pINI		 = pDoc->m_pINI;

	if ( pDoc->m_INI.m_usrINIPath == _T("") )
	{
		if (MessageBox(IDS_USER_SETTING_MISSING, NULL, MB_OKCANCEL) == IDOK){
			pDoc->m_INI.m_usrINIPath = pINI->CreateINI(pDoc->m_host);
			pINI->WriteVal(appName, g_INI[INI_USR_PATH], pDoc->m_INI.m_usrINIPath);
		}
		else
		{
			AfxMessageBox(IDS_SAVE_FAILED);
			return;
		}
	}

	//�Ƿ�������������������Ϣ 
	if (pDoc->m_INI.m_autoStart!=m_autoStart)
	{
		switch(m_autoStart)
		{
		case TRUE:
			if (FALSE == AutoStart(TRUE))
				AfxMessageBox(IDS_AUTOSTART_SET_FAILED);
			else
				AfxMessageBox(IDS_AUTOSTART_SET_SUCCESS);
			pDoc->m_INI.m_autoStart = TRUE;
			break;
		case FALSE:
			if (FALSE == AutoStart(FALSE))
				AfxMessageBox(IDS_AUTOSTART_CANCEL_FAILED);
			else
				AfxMessageBox(IDS_AUTOSTART_CANCEL_SUCCESS);
			pDoc->m_INI.m_autoStart = FALSE;
			break;
		default:
			break;
		}

	}
	
	//�Ƿ񵯳�������ʾ��Ϣ 
	switch(m_pop)
	{
	case TRUE:
		pDoc->m_INI.m_popUp = TRUE;
		break;
	case FALSE:
		pDoc->m_INI.m_popUp = FALSE;
		break;
	default:
		break;
	}


	//�������Ƿ����� 
	switch(m_radioValue)
	{
	case 0:
		pDoc->m_INI.m_AutoType = 0;
		break;
	case 1:
		pDoc->m_INI.m_AutoType = 1;
		break; 
	}
	if (pINI->GetValid() == FALSE)
		pINI->SetValid(TRUE);
	//д��Ƥ������·��
	pDoc->m_INI.m_skinPath=m_skinPath;
	pDoc->WriteINIInfo();
	m_contentChanged=false;
	CDialogEx::OnOK();
}


void CSettingDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filter=_T("Skin file (*.ssk)|*.ssk|Crazy Cursor Files (*.cc)|*.cc|All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, "Skin file(*.ssk)|*.ssk", "blue.ssk", OFN_FILEMUSTEXIST|OFN_ENABLESIZING |OFN_PATHMUSTEXIST , filter, this);
	if (IDOK != dlg.DoModal()) 
		return; 

	m_contentChanged=true;
	m_skinPath = dlg.GetPathName();
	UpdateData(FALSE);
}


void CSettingDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_contentChanged=TRUE;
	UpdateData(FALSE);
}


void CSettingDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_contentChanged=TRUE;
	UpdateData(FALSE);
}


void CSettingDlg::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_contentChanged=TRUE;
	UpdateData(FALSE);
}


BOOL CSettingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	// TODO: Add extra initialization here
	CCOCDlg* pMain  = (CCOCDlg*)AfxGetApp()->m_pMainWnd; 
	CMainDoc* pDoc	 = pMain->m_pMainDoc;
	CINI* pINI		 = pDoc->m_pINI;

	if (pINI->GetValid() == TRUE)
		pDoc->ReadINIInfo(); 

	UpdateCtrl();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


bool CSettingDlg::AutoStart(const bool &bStart)
{
	HKEY hKey;
	char path[MAX_PATH];
	::GetModuleFileName(NULL,path,MAX_PATH);
	CString str;
	str.Format("%s",path);
	LPCTSTR DATA_SET = _T("SoftWare\\Microsoft\\Windows\\CurrentVersion\\Run");
	
	if (ERROR_SUCCESS != RegOpenKeyEx(HKEY_LOCAL_MACHINE,DATA_SET,0,KEY_WRITE,&hKey))
		return FALSE;

	if (bStart)
	{
		if(ERROR_SUCCESS != ::RegSetValueEx(hKey,str,0,REG_SZ,(BYTE*)(LPCSTR)str,strlen(str)+1))
			return FALSE;

		::RegCloseKey(hKey);
	}
	else
	{
		if (ERROR_SUCCESS != ::RegSetValueEx(hKey,str,0,REG_SZ,NULL,NULL))
			return FALSE;

		::RegCloseKey(hKey);
	}

	return TRUE;
}


void CSettingDlg::UpdateCtrl(void)
{
	UpdateData(TRUE);
	CCOCDlg* pMain  = (CCOCDlg*)AfxGetApp()->m_pMainWnd; 
	CMainDoc* pDoc	 = pMain->m_pMainDoc; 
	 

	m_contentChanged=false;
	//��������ѡ��
	 m_autoStart = pDoc->m_INI.m_autoStart;
	//��������ѡ��
	m_pop = pDoc->m_INI.m_popUp;
	 
	//�������Ƿ�����
	m_radioValue = pDoc->m_INI.m_AutoType;
	 
	m_skinPath = pDoc->m_INI.m_skinPath; 
	UpdateData(FALSE);
}
 
