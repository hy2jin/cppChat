#pragma once

// CClientSocket 명령 대상입니다.
class CChatClientDlg;

class CClientSocket : public CAsyncSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();
	virtual void OnReceive(int nErrorCode);

	CChatClientDlg* m_pDlg;
	void SetChatDlg(CChatClientDlg* pDlg);
};


