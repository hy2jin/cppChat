
// ChatClientDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "ClientSocket.h"
#include "ServerSocket.h"
#include "ChildSocket.h"


// CChatClientDlg 대화 상자
class CChatClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CChatClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHATCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_ChatList;
	CEdit m_ChatInput;
	CEdit m_IP;
	CEdit m_port;
	CStatic m_staticIP;

	BOOL m_isClient;
	CClientSocket* m_pClient;		// 클라이언트 소켓(실제 데이터 주고받음)
	CServerSocket* m_pServer;		// 서버 소켓
	CList<CClientSocket*> m_childs;	// 서버 자식 소켓(실제 데이터 주고받음)

	void AddChildSocket(CChildSocket* pChild);		// 서버로 사용할 때 연결 추가
	void CleanupClientSocket();						// 소켓 정리-클라이언트
	void CleanupServerSocket();						// 소켓 정리-서버

	void AddStrToList(CString strMsg);
	void SendMyMessage();							// 메시지 보내는 함수

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnRangeRadioGroup(UINT uID);		// 라디오버튼 클릭 함수

	afx_msg void OnBnClickedButtonClear();
};
