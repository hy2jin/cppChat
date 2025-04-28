#pragma once

// CServerSocket 명령 대상입니다.

class CServerSocket : public CAsyncSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
	virtual void OnAccept(int nErrorCode);
};


