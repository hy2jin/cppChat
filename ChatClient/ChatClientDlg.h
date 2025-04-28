
// ChatClientDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "ClientSocket.h"
#include "ServerSocket.h"
#include "ChildSocket.h"


// CChatClientDlg ��ȭ ����
class CChatClientDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CChatClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CHATCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_ChatList;	// ä�� ���̴� ����Ʈ
	CEdit m_ChatInput;		// ä�� �Է�â

	afx_msg void OnBnClickedButton1();				// ������ ��ư Ŭ��
	virtual BOOL PreTranslateMessage(MSG* pMsg);	// ����Ű ����

	void AddStrToList(CString msg);					// ���� ����Ʈ�� �߰��ϴ� �Լ�
	void SendMyMessage();
	void SendClientMessage();
	void SendServerMessage();
	afx_msg void OnBnClickedOk();					// ����
	afx_msg void OnRangeRadioGroup(UINT uID);		// ������ư Ŭ�� �Լ�
	afx_msg void OnBnClickedButtonConnect();		// ���� ��ư Ŭ�� �Լ�


	CClientSocket* m_pClient;		// Ŭ���̾�Ʈ ����(���� ������ �ְ����)
	CServerSocket* m_pServer;		// ���� ����
	CList<CChildSocket*> m_childs;	// ���� �ڽ� ����(���� ������ �ְ����)


	CEdit m_IP;				// ip �Է�â
	CEdit m_port;			// port �Է�â
	CStatic m_staticIP;		// ip static
	CStatic m_staticPort;	// port static

	
	BOOL m_isClient;		// ���-TRUE:Ŭ���̾�Ʈ, FALSE:����
};
