
// MFC3.31��2��View.h : CMFC331��2��View ��Ľӿ�
//

#pragma once


class CMFC331��2��View : public CView
{
protected: // �������л�����
	CMFC331��2��View();
	DECLARE_DYNCREATE(CMFC331��2��View)

// ����
public:
	CMFC331��2��Doc* GetDocument() const;

// ����
public:
CString str;
CPoint point1,point2;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC331��2��View();
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFC3.31��2��View.cpp �еĵ��԰汾
inline CMFC331��2��Doc* CMFC331��2��View::GetDocument() const
   { return reinterpret_cast<CMFC331��2��Doc*>(m_pDocument); }
#endif

