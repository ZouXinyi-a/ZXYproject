
// DB201812300019Doc.h : CDB201812300019Doc ��Ľӿ�
//


#pragma once
#include "DB201812300019Set.h"


class CDB201812300019Doc : public CDocument
{
protected: // �������л�����
	CDB201812300019Doc();
	DECLARE_DYNCREATE(CDB201812300019Doc)

// ����
public:
	CDB201812300019Set m_DB201812300019Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDB201812300019Doc();
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
