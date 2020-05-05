
// MFC3.24（3）View.h : CMFC324（3）View 类的接口
//

#pragma once


class CMFC324（3）View : public CView
{
protected: // 仅从序列化创建
	CMFC324（3）View();
	DECLARE_DYNCREATE(CMFC324（3）View)

// 特性
public:
	CMFC324（3）Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC324（3）View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowline();
	afx_msg void OnShowrectangle();
	afx_msg void OnShowellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.24（3）View.cpp 中的调试版本
inline CMFC324（3）Doc* CMFC324（3）View::GetDocument() const
   { return reinterpret_cast<CMFC324（3）Doc*>(m_pDocument); }
#endif

