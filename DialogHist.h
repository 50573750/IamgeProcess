#pragma once


// CDialogHist �Ի���

class CDialogHist : public CDialog
{
	DECLARE_DYNAMIC(CDialogHist)

public:
	CDialogHist(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogHist();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	double m_realHist[256];
	int m_nHist;

	DECLARE_MESSAGE_MAP()
public:
	void SetDisplayHistData(double * argrealHist,int argnHist);
public:
	afx_msg void OnPaint();
public:
	afx_msg void OnNcDestroy();
};
