// ClientSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "ClientSocket.h"


// CClientSocket

CClientSocket::CClientSocket()
{
	m_pDlg = nullptr;
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket ��� �Լ�


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	char cBuff[1024] = { 0 };
	int nBytes = Receive(cBuff, sizeof(cBuff) - 1);
	
	if (nBytes > 0)
	{
		cBuff[nBytes] = '\0';
		CStringA ansiStr(cBuff);
		CString msgStr(ansiStr);

		TRACE(msgStr + _T("\n"));
		m_pDlg->AddStrToList(_T("[��]: ") + msgStr);
	}

	CAsyncSocket::OnReceive(nErrorCode);
}

void CClientSocket::SetChatDlg(CChatClientDlg* pDlg)
{
	m_pDlg = pDlg;
}

void CClientSocket::OnConnect(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0)
	{
		AfxMessageBox(_T("���� ����"));
	}
	else
	{
		int err = GetLastError();
		CString strErr;
		strErr.Format(_T("���� ���� (�����ڵ�: %d)"), err);
		AfxMessageBox(strErr);

		m_pDlg->CleanupClientSocket();
	}
	CAsyncSocket::OnConnect(nErrorCode);
}
