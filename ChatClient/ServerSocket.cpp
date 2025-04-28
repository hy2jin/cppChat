// ServerSocket.cpp : 구현 파일입니다.
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


// CServerSocket 멤버 함수


void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
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
