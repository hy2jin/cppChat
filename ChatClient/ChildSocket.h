#pragma once

// CChildSocket ��� ����Դϴ�.
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


