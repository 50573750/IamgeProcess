#pragma once
#include "afxwin.h"


// CDialogLogTran �Ի���

class CDialogLogTran : public CDialog
{
	DECLARE_DYNAMIC(CDialogLogTran)

public:
	CDialogLogTran(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogLogTran();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edtFc;
public:
	afx_msg void OnBnClickedButton1();
};
