// MainFrm.h : CMainFrame ��Ľӿ�
//

#include "imagebmp.h"
#pragma once

class CMainFrame : public CFrameWnd
{
private:
	char strChar[40];
	double dChar[40][6];

private:
	CString strfl;

protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:
	CImageBmp biDoc;
	CImageBmp biPreDoc;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpen();
public:
	afx_msg void OnExit();
public:
	afx_msg void OnHist();
public:
	afx_msg void OnGray();
public:
	afx_msg void OnTransLintran();
public:
	afx_msg void On32780();
public:
	afx_msg void OnGrammaTran();
public:
	afx_msg void OnHistEq();
public:
	afx_msg void OnHistSt();
public:
	afx_msg void OnThreshosd();
public:
	afx_msg void OnSpaceAvgSmooth();
public:
	afx_msg void OnSpaceGaussSmooth();
public:
	afx_msg void OnSpaceAdapterSmooth();
public:
	afx_msg void OnMidFilter();
public:
	afx_msg void OnLowFilter();
public:
	afx_msg void OnHighFilter();
public:
	afx_msg void OnSobel();
public:
	afx_msg void OnLaplace();
public:
	afx_msg void OnLog();
public:
	afx_msg void OnLogBig();
public:
	afx_msg void OnFft();
public:
	afx_msg void OnIfft();
public:
	afx_msg void OnIdealLpf();
public:
	afx_msg void OnGaussFilter();
public:
	afx_msg void OnGaussHpf();
public:
	afx_msg void OnSquareErode();
public:
	afx_msg void OnCrossErode();
public:
	afx_msg void OnLaplaceHfd();
public:
	afx_msg void OnUndo();
public:
	bool DoIt(void);
protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void OnSquareDilate();
public:
	afx_msg void OnCrossDilate();
public:
	afx_msg void OnSquareClose();
public:
	afx_msg void OnCrossClose();
public:
	afx_msg void OnSquareOpen();
public:
	afx_msg void OnCrossOpen();
public:
	afx_msg void OnTraceBoundary();
public:
	afx_msg void OnReginFill();
public:
	POINT ptClick;
public:
	afx_msg void OnReverse();
public:
	afx_msg void On32848();
public:
	afx_msg void OnConnectionRegion();
public:
	afx_msg void OnThining();
public:
	afx_msg void OnPixelImage();
public:
	afx_msg void OnConvex();
public:
	afx_msg void OnTopHat();
public:
	afx_msg void OnText();
public:
	afx_msg void OnExceptBorder();
public:
	afx_msg void OnPlateFind();
public:
	afx_msg void OnBluePlate();
public:
	afx_msg void OnSplit();
public:
	afx_msg void OnRead();
public:
	afx_msg void OnHistMid();
public:
	afx_msg void OnMinHist();
public:
	afx_msg void OnHistMinTrans();
public:
	afx_msg void OnThreadHistTran();
public:
	afx_msg void OnVproject();
public:
	afx_msg void OnHproject();
public:
	afx_msg void OnPreFindPlate();
public:
	afx_msg void OnSplitTrans();
public:
	afx_msg void OnSwallowHistTran();
public:
	afx_msg void On32891();
public:
	afx_msg void OnConRegin();
public:
	afx_msg void OnBpNetTrain();
public:
	afx_msg void OnGridIt();
public:
	afx_msg void OnNetSim();
public:
	afx_msg void OnNormal();
public:
	afx_msg void OnCheckd();
public:
	afx_msg void OnPicOut();
public:
	afx_msg void OnSimInit();
public:
	afx_msg void OnOdTest();
public:
	afx_msg void OnStrike();
public:
	afx_msg void OnHistK();
public:
	afx_msg void OnBluePassage();
public:
	afx_msg void OnAlldo();
public:
	afx_msg void OnSizeFit();
public:
	afx_msg void OnRename();
public:
	afx_msg void OnBinaryPic();
public:
	afx_msg void OnRightImage();
public:
	afx_msg void OnGjyTrain();
public:
	afx_msg void OnGjyReg();
public:
	afx_msg void OnSign();
public:
	afx_msg void OnNewSimIniti();
public:
	afx_msg void On32934();
public:
	afx_msg void On32935();
public:
	afx_msg void OnRealDo();
};


