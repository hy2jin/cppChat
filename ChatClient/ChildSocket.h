#pragma once

// CChildSocket 명령 대상입니다.
class CChatClientDlg;

class CChildSocket : public CAsyncSocket
{
public:
	CChildSocket();
	virtual ~CChildSocket();
	virtual void OnReceive(int nErrorCode);

	CChatClientDlg* m_pDlg;
	void SetChatDlg(CChatClientDlg* pDlg);
};


