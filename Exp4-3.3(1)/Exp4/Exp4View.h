
// Exp4View.h : CExp4View ��Ľӿ�
//

#pragma once


class CExp4View : public CView
{
protected: // �������л�����
	CExp4View();
	DECLARE_DYNCREATE(CExp4View)

// ����
public:
	CExp4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExp4View();
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
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Exp4View.cpp �еĵ��԰汾
inline CExp4Doc* CExp4View::GetDocument() const
   { return reinterpret_cast<CExp4Doc*>(m_pDocument); }
#endif

