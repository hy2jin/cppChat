#pragma once

// CServerSocket 명령 대상입니다.
class CChatClientDlg;

class CServerSocket : public CAsyncSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
	virtual void OnAccept(int nErrorCode);

	CChatClientDlg* m_pDlg;
	void SetChatDlg(CChatClientDlg* pDlg);
};


