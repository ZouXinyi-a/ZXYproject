
// MFC2-3.24��ʾλͼView.h : CMFC2324��ʾλͼView ��Ľӿ�
//

#pragma once


class CMFC2324��ʾλͼView : public CView
{
protected: // �������л�����
	CMFC2324��ʾλͼView();
	DECLARE_DYNCREATE(CMFC2324��ʾλͼView)

// ����
public:
	CMFC2324��ʾλͼDoc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;//λͼ����
	int m_nWidth;
	int m_nHeight;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC2324��ʾλͼView();
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
	afx_msg void OnShowmap();
};

#ifndef _DEBUG  // MFC2-3.24��ʾλͼView.cpp �еĵ��԰汾
inline CMFC2324��ʾλͼDoc* CMFC2324��ʾλͼView::GetDocument() const
   { return reinterpret_cast<CMFC2324��ʾλͼDoc*>(m_pDocument); }
#endif

