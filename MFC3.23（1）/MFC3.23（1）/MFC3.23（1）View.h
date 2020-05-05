
// MFC3.23（1）View.h : CMFC323（1）View 类的接口
//

#pragma once


class CMFC323（1）View : public CView
{
protected: // 仅从序列化创建
	CMFC323（1）View();
	DECLARE_DYNCREATE(CMFC323（1）View)

// 特性
public:
	CMFC323（1）Doc* GetDocument() const;

// 操作
public:
	int r;
	int t;
	CRect rect;
	CPoint point;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC323（1）View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnGradualcircle();
	afx_msg void OnGradualcolor();
};

#ifndef _DEBUG  // MFC3.23（1）View.cpp 中的调试版本
inline CMFC323（1）Doc* CMFC323（1）View::GetDocument() const
   { return reinterpret_cast<CMFC323（1）Doc*>(m_pDocument); }
#endif

