#pragma once
#include "afxwin.h"


// CDialogThershold �Ի���

class CDialogThershold : public CDialog
{
	DECLARE_DYNAMIC(CDialogThershold)

public:
	CDialogThershold(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogThershold();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edtTV;
public:
	afx_msg void OnBnClickedButton1();
};
