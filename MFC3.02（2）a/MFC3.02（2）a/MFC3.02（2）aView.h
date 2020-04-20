
// MFC3.02（2）aView.h : CMFC302（2）aView 类的接口
//

#pragma once


class CMFC302（2）aView : public CView
{
protected: // 仅从序列化创建
	CMFC302（2）aView();
	DECLARE_DYNCREATE(CMFC302（2）aView)

// 特性
public:
	CMFC302（2）aDoc* GetDocument() const;

// 操作
public:
CArray<CRect,CRect&> ca;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC302（2）aView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.02（2）aView.cpp 中的调试版本
inline CMFC302（2）aDoc* CMFC302（2）aView::GetDocument() const
   { return reinterpret_cast<CMFC302（2）aDoc*>(m_pDocument); }
#endif

