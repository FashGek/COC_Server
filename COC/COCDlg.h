
// COCDlg.h : ͷ�ļ�
//

#pragma once 
#include <vector>
#include "afxwin.h"
#include <afxstr.h> 
#include "Server.h"
#include "Message.h"
#include "IHListBox.h"
#include "TaskbarNotifier.h"

using namespace std;

#define WM_SHOWTASK WM_USER+1

class CMainDoc;
// CCOCDlg �Ի���
class CCOCDlg : public CDialogEx
{
	// ����
public:
	CCOCDlg(CWnd* pParent = NULL);	// ��׼���캯��

	// �Ի�������
	enum { IDD = IDD_COC_DIALOG };

	// ʵ����������
	NOTIFYICONDATA m_nid;
	// ��ʶ�Ƿ��ǵ���ģʽ��Ĭ�ϲ���
	bool m_bAlone;
	// ����IP��ַ
	vector<CString> m_ipAdds;
	CString m_curIP;//����ѡ�е�IP
	
	// ������ 
	CServer m_server; 

	// �����Ķ˿�
	int m_port;

	// ״̬
	int m_status;//0��ʾδ���1��ʾ�����ӣ�
	// ���ڱ�������
	CString m_windowName;

	// ���ھ��
	CWnd* pWndPrev;

	// ��ʱ�ػ�
	int m_shutDown;
	bool m_shutTimerFlag;

	CMainDoc*				m_pMainDoc;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	// ʵ��
protected:
	HICON m_hIcon;
	CTaskbarNotifier		m_wndTaskbarNotifier;	//��������
	CStatusBar				m_statusBar;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnShowTask(WPARAM wParam,LPARAM lParams);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy); 
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnCbnSelchangeCombo1();
	// ��ȡ��������IP��ַ
	bool GetIPadd(void);
	// IP��ַ���б�
	CComboBox m_ipList;
	CButton m_ButtonStart;
	void EnableControls(bool flag);
	CButton m_checkBox;
	// ��ʼ����ˢ��
	void startService(void);
	void stopService(void);
	bool startServer(void);
	bool stopServer(void);

	CIHListBox m_messageList;

	bool findCOCWindow(void);
	bool openCOC(void);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void updateMessage(CString message);
	bool validatePassword(char* pwd);
	CString m_password;

	void OnReceive( int nErrorCode );
	void OnConnect( int nErrorCode );
	void OnOutOfBandData( int nErrorCode );
	void OnAccept( int nErrorCode );
	void OnSend( int nErrorCode );
	void handleMessage(char* data);
	bool findNextToken(char* des,char* data, int& posotion, char sp);
	void InitTaskbarNotifier(void);
	void setShutDownTime(int time);
	void updateTime(void);
};
