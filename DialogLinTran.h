#pragma once
#include "afxwin.h"


// CDialogLinTran �Ի���

class CDialogLinTran : public CDialog
{
	DECLARE_DYNAMIC(CDialogLinTran)

public:
	CDialogLinTran(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogLinTran();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	CEdit m_edtFa;
public:
	CEdit m_edtFb;
};
