#pragma once
#include "afxwin.h"

class CCOCDlg;

// CShutDownDlg �Ի���

class CShutDownDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShutDownDlg)

public:
	CShutDownDlg(CCOCDlg* pParent = NULL);   // ��׼���캯��
	virtual ~CShutDownDlg();
	CCOCDlg* m_pParent;

// �Ի�������
	enum { IDD = IDD_DIALOG_SHUTDOWN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1(); 
	afx_msg void OnBnClickedOk();
	void setTime(int time);
	int m_shutDownTime;
};
