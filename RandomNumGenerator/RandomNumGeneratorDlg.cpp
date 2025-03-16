
// RandomNumGeneratorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "RandomNumGenerator.h"
#include "RandomNumGeneratorDlg.h"
#include "afxdialogex.h"
#include <Windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRandomNumGeneratorDlg 对话框



CRandomNumGeneratorDlg::CRandomNumGeneratorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RANDOMNUMGENERATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRandomNumGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, M_list);
	DDX_Control(pDX, IDC_EDIT2, M_edit);
}

BEGIN_MESSAGE_MAP(CRandomNumGeneratorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRandomNumGeneratorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CRandomNumGeneratorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CRandomNumGeneratorDlg::OnBnClickedButton2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CRandomNumGeneratorDlg::OnDeltaposSpin1)
	ON_BN_CLICKED(IDC_BUTTON4, &CRandomNumGeneratorDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CRandomNumGeneratorDlg 消息处理程序

BOOL CRandomNumGeneratorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	M_list.InsertColumn(0, TEXT("序号"), 0, 80);
	M_list.InsertColumn(1, TEXT("学号"), 0, 120);
	M_list.InsertColumn(2, TEXT("姓名"), 0, 400);

	lineCnt = 0;
	frequency = 5;
	textRewrite(frequency);
	M_DataInterface.SetFilePath("C:\\settingfile.txt");
	if (M_DataInterface.isOpen())
	{
		M_DataInterface.Open();
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRandomNumGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRandomNumGeneratorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRandomNumGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRandomNumGeneratorDlg::eraseLine()
{
	M_list.DeleteAllItems();
}

void CRandomNumGeneratorDlg::insertLine(List::node* p_content)
{
    CString str;
    str.Format(TEXT("%d"), this->lineCnt);
    M_list.InsertItem(this->lineCnt, str);

    CString numStr;
    numStr.Format(TEXT("%d"), p_content->num); // Convert int to CString
    M_list.SetItemText(this->lineCnt, 1, numStr);

	M_list.SetItemText(this->lineCnt, 2, p_content->name.c_str());

    this->lineCnt++;
}

void CRandomNumGeneratorDlg::textRewrite(int content)
{
	CString numStr;
	numStr.Format(TEXT("%d"), content);
	M_edit.SetWindowTextA(numStr);
}


void CRandomNumGeneratorDlg::OnBnClickedButton1()
{
	// 选择文件路径
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;
	if (IDOK == fileDlg.DoModal())
	{
		strFilePath = fileDlg.GetPathName();
		M_DataInterface.SetFilePath(strFilePath);
	}

	// 刷新操作
	this->eraseLine();
	this->lineCnt = 0;
	M_DataInterface.Open();
	return;
}

void CRandomNumGeneratorDlg::OnBnClickedButton3()
{
	// 刷新操作
	this->eraseLine();
	this->lineCnt = 0;
	M_DataInterface.Open();
	return;
}

void CRandomNumGeneratorDlg::OnBnClickedButton2()
{
	// 抽号/生成随机数 部分
	if (!M_DataInterface.isOpen())
	{
		MessageBox(TEXT("未打开预设文件"));
		return;
	}

	auto p = M_DataInterface.Generate();

	if (p == nullptr)
	{
        MessageBox(TEXT("生成数量已达上限"));
		return;
	}

	this->insertLine(p);
	M_DataInterface.delItem(p->num);
	return;
}

void CRandomNumGeneratorDlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// SpinControl 部分
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	if (pNMUpDown->iDelta == -1)
	{
		if (this->frequency < _MAX_FREQUENCY)
		{
			this->frequency++;
		}
	}
	else
	{
		if (this->frequency > _MIN_FREQUENCY)
		{
			this->frequency--;
		}
	}
	textRewrite(this->frequency);

	*pResult = 0;
}

void CRandomNumGeneratorDlg::OnBnClickedButton4()
{
	//实现多个生成
	if (!M_DataInterface.isOpen())
	{
		MessageBox(TEXT("未打开预设文件"));
		return;
	}

	for (int i = 0;i < this->frequency;i++)
	{
		auto p = M_DataInterface.Generate();

		if (p == nullptr)
		{
			MessageBox(TEXT("生成数量已达上限"));
			return;
		}

		this->insertLine(p);
		M_DataInterface.delItem(p->num);
	}
	return;
}
