// ChildSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "ChildSocket.h"


// CChildSocket

CChildSocket::CChildSocket()
{
	m_pDlg = nullptr;
}

CChildSocket::~CChildSocket()
{
}


// CChildSocket ��� �Լ�


void CChildSocket::OnReceive(int nErrorCode)
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

void CChildSocket::SetChatDlg(CChatClientDlg* pDlg)
{
	m_pDlg = pDlg;
}