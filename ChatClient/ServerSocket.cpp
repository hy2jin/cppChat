// ServerSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ServerSocket.h"


// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// CServerSocket ��� �Լ�


void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CAsyncSocket::OnAccept(nErrorCode);
}
