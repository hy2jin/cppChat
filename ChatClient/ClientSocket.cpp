// ClientSocket.cpp : 구현 파일입니다.
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


// CClientSocket 멤버 함수


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	char cBuff[1024] = { 0 };
	int nBytes = Receive(cBuff, sizeof(cBuff) - 1);

	if (nBytes > 0)
	{
		cBuff[nBytes] = '\0';
		CStringA ansiStr(cBuff);
		CString msgStr(ansiStr);

		m_pDlg->AddStrToList(_T("[남]: ") + msgStr);
	}
	CAsyncSocket::OnReceive(nErrorCode);
}

void CClientSocket::SetChatDlg(CChatClientDlg* pDlg)
{
	m_pDlg = pDlg;
}