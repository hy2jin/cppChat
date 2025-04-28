// ServerSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "ServerSocket.h"
#include "ChildSocket.h"

// CServerSocket

CServerSocket::CServerSocket()
{
	m_pDlg = nullptr;
}

CServerSocket::~CServerSocket()
{
}


// CServerSocket ��� �Լ�


void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CChildSocket* pChild = new CChildSocket();
	if (Accept(*pChild))
	{
		m_pDlg->AddChildSocket(pChild);
	}
	else
	{
		delete pChild;
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void CServerSocket::SetChatDlg(CChatClientDlg* pDlg)
{
	m_pDlg = pDlg;
}
