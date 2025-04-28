
// ChatClientDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "ClientSocket.h"


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
