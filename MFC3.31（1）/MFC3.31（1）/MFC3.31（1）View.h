
// MFC3.31��1��View.h : CMFC331��1��View ��Ľӿ�
//

#pragma once


class CMFC331��1��View : public CView
{
protected: // �������л�����
	CMFC331��1��View();
	DECLARE_DYNCREATE(CMFC331��1��View)

// ����
public:
	CMFC331��1��Doc* GetDocument() const;

// ����
public:
	CString s;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC331��1��View();
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFC3.31��1��View.cpp �еĵ��԰汾
inline CMFC331��1��Doc* CMFC331��1��View::GetDocument() const
   { return reinterpret_cast<CMFC331��1��Doc*>(m_pDocument); }
#endif

