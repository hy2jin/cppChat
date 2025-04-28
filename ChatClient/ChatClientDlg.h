
// ChatClientDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "ClientSocket.h"


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
	afx_msg void OnBnClickedButton1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	void AddStrToList();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLbnSelchangeList1();

	CClientSocket m_client;
	CEdit m_IP;
	CEdit m_port;
	afx_msg void OnBnClickedButtonConnect();
};
