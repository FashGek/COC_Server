// ShutDownDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "COC.h"
#include "ShutDownDlg.h"
#include "afxdialogex.h"
#include "COCDlg.h"


// CShutDownDlg �Ի���

IMPLEMENT_DYNAMIC(CShutDownDlg, CDialogEx)

CShutDownDlg::CShutDownDlg(CCOCDlg* pParent /*=NULL*/)
	: CDialogEx(CShutDownDlg::IDD, pParent)
	, m_shutDownTime(0)
{
	m_pParent = pParent;
}

CShutDownDlg::~CShutDownDlg()
{
}

void CShutDownDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX); 
	DDX_Text(pDX, IDC_EDIT1, m_shutDownTime);
	DDV_MinMaxInt(pDX, m_shutDownTime, 0, 86400);
}


BEGIN_MESSAGE_MAP(CShutDownDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CShutDownDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CShutDownDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CShutDownDlg ��Ϣ�������


void CShutDownDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CShutDownDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_pParent->setShutDownTime(m_shutDownTime);
	CDialogEx::OnOK();
}


void CShutDownDlg::setTime(int time)
{
	m_shutDownTime = time; 
}
