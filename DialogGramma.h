#pragma once
#include "afxwin.h"


// CDialogGramma �Ի���

class CDialogGramma : public CDialog
{
	DECLARE_DYNAMIC(CDialogGramma)

public:
	CDialogGramma(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogGramma();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	CEdit m_edtEsp;
public:
	CEdit m_edtGrammer;
};
