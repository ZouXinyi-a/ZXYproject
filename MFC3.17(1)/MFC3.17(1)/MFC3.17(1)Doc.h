
// MFC3.17(1)Doc.h : CMFC3171Doc ��Ľӿ�
//


#pragma once


class CMFC3171Doc : public CDocument
{
protected: // �������л�����
	CMFC3171Doc();
	DECLARE_DYNCREATE(CMFC3171Doc)

// ����
public:

// ����
public:
CPoint m_point;
bool judge;
int i;
int a,b;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC3171Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
