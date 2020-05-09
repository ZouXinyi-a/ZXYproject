
// MFC4.13(3)View.h : CMFC4133View 类的接口
//

#pragma once


class CMFC4133View : public CView
{
protected: // 仅从序列化创建
	CMFC4133View();
	DECLARE_DYNCREATE(CMFC4133View)

// 特性
public:
	CMFC4133Doc* GetDocument() const;

// 操作
public:
	CPoint point;
	CRect rect;
	bool set;
bool judge;
bool m_move,m_LorR;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4133View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4.13(3)View.cpp 中的调试版本
inline CMFC4133Doc* CMFC4133View::GetDocument() const
   { return reinterpret_cast<CMFC4133Doc*>(m_pDocument); }
#endif

