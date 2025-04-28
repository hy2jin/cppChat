
// ChatClientDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CChatClientDlg 대화 상자



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


// CChatClientDlg 메시지 처리기

BOOL CChatClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChatClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChatClientDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SendMyMessage();
}


BOOL CChatClientDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN)	// 키 누름
	{
		if (pMsg->wParam == VK_RETURN)	// Enter
		{
			SendMyMessage();			// 함수 호출
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CChatClientDlg::AddStrToList(CString msg)	// 리스트에 추가하는 함수
{
	int cnt = m_ChatList.GetCount();
	m_ChatList.InsertString(cnt, msg);
}

void CChatClientDlg::SendMyMessage()
{
	CString tempInput;
	m_ChatInput.GetWindowTextW(tempInput);

	// 빈값 걸러내기
	tempInput = tempInput.Trim();
	if (tempInput.IsEmpty())
	{
		AfxMessageBox(_T("내용 없음"));
		return;
	}

	// 한글 안깨지도록 변경
	CStringA aMsg(tempInput);
	const char* data = aMsg.GetBuffer();
	int len = aMsg.GetLength();

	// 소켓 연결 확인
	if (m_isClient)
	{
		if (m_pClient == nullptr)
		{
			AfxMessageBox(_T("클라이언트 소켓 없음"));
			return;
		}
		m_pClient->Send(data, len);
	}
	else if (m_isClient == FALSE)
	{
		if (m_pServer == nullptr)
		{
			AfxMessageBox(_T("서버 소켓 없음"));
			return;
		}
		if (m_childs.GetCount() == 0)
		{
			AfxMessageBox(_T("연결된 소켓 없음"));
		}

		POSITION pos = m_childs.GetHeadPosition();
		while (pos != nullptr)
		{
			CChildSocket* pChild = m_childs.GetNext(pos);
			if (pChild)
				pChild->Send(data, len);
		}
	}


	// 내 리스트레 추가하고 input창 비우기
	AddStrToList(_T("[나]: ") + tempInput);
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CChatClientDlg::OnBnClickedButtonConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// IP, Port 받아오기
	CString inputIP, inputPort;
	m_IP.GetWindowTextW(inputIP);
	m_port.GetWindowTextW(inputPort);
	inputIP = inputIP.Trim();
	inputPort = inputPort.Trim();

	
	if (m_isClient)
	{	
		// 클라이언트는 IP, PORT 필요
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
		// 서버는 PORT 필요
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

	if (uID == IDC_RADIO1)	// 클라이언트
	{
		m_isClient = TRUE;
		m_staticIP.ShowWindow(SW_SHOW);
		m_IP.ShowWindow(SW_SHOW);


		CleanupServerSocket();
	}
	else if (uID == IDC_RADIO2)	// 서버
	{
		m_isClient = FALSE;
		m_staticIP.ShowWindow(SW_HIDE);
		m_IP.ShowWindow(SW_HIDE);


		CleanupClientSocket();
	}
}