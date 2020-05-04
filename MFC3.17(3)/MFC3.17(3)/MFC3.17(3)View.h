
// MFC3.17(3)View.h : CMFC3173View 类的接口
//

#pragma once


class CMFC3173View : public CView
{
protected: // 仅从序列化创建
	CMFC3173View();
	DECLARE_DYNCREATE(CMFC3173View)

// 特性
public:
	CMFC3173Doc* GetDocument() const;

// 操作
public:
	int N;
	CArray <CRect , CRect>cr;
	bool set;
	bool s;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3173View();
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
};

#ifndef _DEBUG  // MFC3.17(3)View.cpp 中的调试版本
inline CMFC3173Doc* CMFC3173View::GetDocument() const
   { return reinterpret_cast<CMFC3173Doc*>(m_pDocument); }
#endif

