
// ChatClientDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChatClientDlg ��ȭ ����



CChatClientDlg::CChatClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_isClient = TRUE;
	m_pClient = nullptr;
	m_pServer = nullptr;
}

void CChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ChatList);
	DDX_Control(pDX, IDC_EDIT1, m_ChatInput);
	DDX_Control(pDX, IDC_EDIT_IP, m_IP);
	DDX_Control(pDX, IDC_EDIT_PORT, m_port);
	DDX_Control(pDX, IDC_STATIC_IP, m_staticIP);
	DDX_Control(pDX, IDC_STATIC_PORT, m_staticPort);
}

BEGIN_MESSAGE_MAP(CChatClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CChatClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CChatClientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CChatClientDlg::OnBnClickedButtonConnect)

	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO2, &CChatClientDlg::OnRangeRadioGroup)
END_MESSAGE_MAP()


// CChatClientDlg �޽��� ó����

BOOL CChatClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CChatClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CChatClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChatClientDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SendMyMessage();
}


BOOL CChatClientDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN)	// Ű ����
	{
		if (pMsg->wParam == VK_RETURN)	// Enter
		{
			SendMyMessage();			// �Լ� ȣ��
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CChatClientDlg::AddStrToList(CString msg)	// ����Ʈ�� �߰��ϴ� �Լ�
{
	int cnt = m_ChatList.GetCount();
	m_ChatList.InsertString(cnt, msg);
}

void CChatClientDlg::SendMyMessage()
{
	CString tempInput;
	m_ChatInput.GetWindowTextW(tempInput);

	// �� �ɷ�����
	tempInput = tempInput.Trim();
	if (tempInput.IsEmpty())
	{
		AfxMessageBox(_T("���� ����"));
		return;
	}

	// �ѱ� �ȱ������� ����
	CStringA aMsg(tempInput);
	const char* data = aMsg.GetBuffer();
	int len = aMsg.GetLength();

	// ���� ���� Ȯ��
	if (m_isClient)
	{
		if (m_pClient == nullptr)
		{
			AfxMessageBox(_T("Ŭ���̾�Ʈ ���� ����"));
			return;
		}
		m_pClient->Send(data, len);
	}
	else if (m_isClient == FALSE)
	{
		if (m_pServer == nullptr)
		{
			AfxMessageBox(_T("���� ���� ����"));
			return;
		}
		if (m_childs.GetCount() == 0)
		{
			AfxMessageBox(_T("����� ���� ����"));
		}

		POSITION pos = m_childs.GetHeadPosition();
		while (pos != nullptr)
		{
			CChildSocket* pChild = m_childs.GetNext(pos);
			if (pChild)
				pChild->Send(data, len);
		}
	}


	// �� ����Ʈ�� �߰��ϰ� inputâ ����
	AddStrToList(_T("[��]: ") + tempInput);
	m_ChatInput.SetWindowTextW(_T(""));
}

void CChatClientDlg::AddChildSocket(CChildSocket* pChild)
{
	pChild->SetChatDlg(this);
	m_childs.AddTail(pChild);
}

void CChatClientDlg::CleanupServerSocket()
{
	if (m_pServer)
	{
		m_pServer->Close();
		delete m_pServer;
		m_pServer = nullptr;
	}

	POSITION pos = m_childs.GetHeadPosition();
	while (pos != nullptr)
	{
		CChildSocket* pChild = m_childs.GetNext(pos);
		if (pChild)
		{
			pChild->Close();
			delete pChild;
		}
		m_childs.RemoveAll();
	}
}

void CChatClientDlg::CleanupClientSocket()
{
	if (m_pClient)
	{
		m_pClient->Close();
		delete m_pClient;
		m_pClient = nullptr;
	}
}


void CChatClientDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}


void CChatClientDlg::OnBnClickedButtonConnect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// IP, Port �޾ƿ���
	CString inputIP, inputPort;
	m_IP.GetWindowTextW(inputIP);
	m_port.GetWindowTextW(inputPort);
	inputIP = inputIP.Trim();
	inputPort = inputPort.Trim();

	
	if (m_isClient)
	{	
		// Ŭ���̾�Ʈ�� IP, PORT �ʿ�
		if (inputIP.GetLength() == 0 || inputPort.IsEmpty())
		{
			return;
		}

		m_pClient = new CClientSocket();
		m_pClient->SetChatDlg(this);

		int iPort = _ttoi(inputPort);
		m_pClient->Create(iPort);
		m_pClient->Connect(inputIP, iPort);
	}
	else
	{
		// ������ PORT �ʿ�
		if (inputPort.IsEmpty())
		{
			return;
		}

		m_pServer = new CServerSocket();
		m_pServer->SetChatDlg(this);

		m_pServer->Create(_ttoi(inputPort));
		m_pServer->Listen();
	}
}

void CChatClientDlg::OnRangeRadioGroup(UINT uID)
{
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, uID);

	if (uID == IDC_RADIO1)	// Ŭ���̾�Ʈ
	{
		m_isClient = TRUE;
		m_staticIP.ShowWindow(SW_SHOW);
		m_IP.ShowWindow(SW_SHOW);


		CleanupServerSocket();
	}
	else if (uID == IDC_RADIO2)	// ����
	{
		m_isClient = FALSE;
		m_staticIP.ShowWindow(SW_HIDE);
		m_IP.ShowWindow(SW_HIDE);


		CleanupClientSocket();
	}
}