// ImageProcessDoc.h : CImageProcessDoc ��Ľӿ�
//


#pragma once


class CImageProcessDoc : public CDocument
{
protected: // �������л�����
	CImageProcessDoc();
	DECLARE_DYNCREATE(CImageProcessDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CImageProcessDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


