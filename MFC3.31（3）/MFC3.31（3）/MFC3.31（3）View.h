
// MFC3.31��3��View.h : CMFC331��3��View ��Ľӿ�
//

#pragma once


class CMFC331��3��View : public CView
{
protected: // �������л�����
	CMFC331��3��View();
	DECLARE_DYNCREATE(CMFC331��3��View)

// ����
public:
	CMFC331��3��Doc* GetDocument() const;

// ����
public:
CString str1;
CString str2;
CPoint cpoint,point;
int flag,h,x;
CRect rect;
CArray <CString,CString>m;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC331��3��View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.31��3��View.cpp �еĵ��԰汾
inline CMFC331��3��Doc* CMFC331��3��View::GetDocument() const
   { return reinterpret_cast<CMFC331��3��Doc*>(m_pDocument); }
#endif

