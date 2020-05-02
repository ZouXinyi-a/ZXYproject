
// MFC3.16View.h : CMFC316View 类的接口
//

#pragma once


class CMFC316View : public CView
{
protected: // 仅从序列化创建
	CMFC316View();
	DECLARE_DYNCREATE(CMFC316View)

// 特性
public:
	CMFC316Doc* GetDocument() const;

// 操作
public:
bool judge;
CPoint begin;
CPoint now;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC316View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.16View.cpp 中的调试版本
inline CMFC316Doc* CMFC316View::GetDocument() const
   { return reinterpret_cast<CMFC316Doc*>(m_pDocument); }
#endif

