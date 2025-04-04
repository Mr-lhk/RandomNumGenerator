
// RandomNumGeneratorDlg.h: 头文件
//

#pragma once

#include "DataInterface.h"
#include "List.h"

// CRandomNumGeneratorDlg 对话框
class CRandomNumGeneratorDlg : public CDialogEx
{
// 构造
public:
	CRandomNumGeneratorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RANDOMNUMGENERATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	int lineCnt = 0;
	int frequency = 0;
	const int _MAX_FREQUENCY=50, _MIN_FREQUENCY=1;

	void eraseLine();
	void insertLine(List::node* p_content);
	void textRewrite(int content);
	void refresh();
	bool F_generate();
public:
	CListCtrl M_list;
	CEdit M_edit;
	DataInterface M_DataInterface;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton4();
};
