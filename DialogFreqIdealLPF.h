#pragma once


// CDialogFreqIdealLPF �Ի���

class CDialogFreqIdealLPF : public CDialog
{
	DECLARE_DYNAMIC(CDialogFreqIdealLPF)

public:
	CDialogFreqIdealLPF(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogFreqIdealLPF();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
