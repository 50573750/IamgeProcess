// DialogThershold.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "DialogThershold.h"

#include "MainFrm.h"

// CDialogThershold �Ի���

IMPLEMENT_DYNAMIC(CDialogThershold, CDialog)

CDialogThershold::CDialogThershold(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogThershold::IDD, pParent)
{

}

CDialogThershold::~CDialogThershold()
{
}

void CDialogThershold::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edtTV);
}


BEGIN_MESSAGE_MAP(CDialogThershold, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogThershold::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDialogThershold ��Ϣ�������
double StrToDouble(CString str);

void CDialogThershold::OnBnClickedButton1()
{
	double thd;

	CString strd;
	m_edtTV.GetWindowText(strd);

	thd = StrToDouble(strd);

	CMainFrame* mf = (CMainFrame*)AfxGetMainWnd();
	mf->biDoc.ThresholdTran(thd);

	mf->GetActiveView()->Invalidate();
}
