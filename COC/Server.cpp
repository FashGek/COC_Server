// Server.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "COC.h"
#include "Server.h"
#include "COCDlg.h"


// CServer

CServer::CServer(CCOCDlg* pwnd)
{
	m_pWnd = pwnd;
}

CServer::~CServer()
{
}


// CServer ��Ա����


void CServer::OnAccept(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_pWnd->OnAccept(nErrorCode);
	CAsyncSocket::OnAccept(nErrorCode);
}

 

void CServer::OnConnect(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_pWnd->OnConnect(nErrorCode);
	CAsyncSocket::OnConnect(nErrorCode);
}


void CServer::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_pWnd->OnReceive(nErrorCode);
	CAsyncSocket::OnReceive(nErrorCode);
}


void CServer::OnSend(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_pWnd->OnSend(nErrorCode);
	CAsyncSocket::OnSend(nErrorCode);
}


void CServer::setCallBackDlg(CCOCDlg* callBackDlg)
{
	m_pWnd = callBackDlg;
}


void CServer::OnOutOfBandData(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_pWnd->OnOutOfBandData(nErrorCode);
	CAsyncSocket::OnOutOfBandData(nErrorCode);
}
