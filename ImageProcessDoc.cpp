// ImageProcessDoc.cpp : CImageProcessDoc ���ʵ��
//

#include "stdafx.h"
#include "ImageProcess.h"

#include "ImageProcessDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessDoc

IMPLEMENT_DYNCREATE(CImageProcessDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageProcessDoc, CDocument)
END_MESSAGE_MAP()


// CImageProcessDoc ����/����

CImageProcessDoc::CImageProcessDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CImageProcessDoc::~CImageProcessDoc()
{
}

BOOL CImageProcessDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CImageProcessDoc ���л�

void CImageProcessDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CImageProcessDoc ���

#ifdef _DEBUG
void CImageProcessDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageProcessDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageProcessDoc ����
