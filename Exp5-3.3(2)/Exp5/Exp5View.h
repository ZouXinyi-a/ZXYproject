
// Exp5View.h : CExp5View ��Ľӿ�
//

#pragma once


class CExp5View : public CView
{
protected: // �������л�����
	CExp5View();
	DECLARE_DYNCREATE(CExp5View)

// ����
public:
	CExp5Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExp5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Exp5View.cpp �еĵ��԰汾
inline CExp5Doc* CExp5View::GetDocument() const
   { return reinterpret_cast<CExp5Doc*>(m_pDocument); }
#endif

