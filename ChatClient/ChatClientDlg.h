
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
	CListBox m_ChatList;
	CEdit m_ChatInput;
	CEdit m_IP;
	CEdit m_port;
	CStatic m_staticIP;

	BOOL m_isClient;
	CClientSocket* m_pClient;		// Ŭ���̾�Ʈ ����(���� ������ �ְ����)
	CServerSocket* m_pServer;		// ���� ����
	CList<CClientSocket*> m_childs;	// ���� �ڽ� ����(���� ������ �ְ����)

	void AddChildSocket(CChildSocket* pChild);		// ������ ����� �� ���� �߰�
	void CleanupClientSocket();						// ���� ����-Ŭ���̾�Ʈ
	void CleanupServerSocket();						// ���� ����-����

	void AddStrToList(CString strMsg);
	void SendMyMessage();							// �޽��� ������ �Լ�

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnRangeRadioGroup(UINT uID);		// ������ư Ŭ�� �Լ�

	afx_msg void OnBnClickedButtonClear();
};
