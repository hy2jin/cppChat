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

	CAsyncSocket::OnReceive(nErrorCode);
}

void CChildSocket::SetChatDlg(CChatClientDlg* pDlg)
{
	m_pDlg = pDlg;
}