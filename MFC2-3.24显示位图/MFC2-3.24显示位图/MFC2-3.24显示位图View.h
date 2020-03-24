
// MFC2-3.24显示位图View.h : CMFC2324显示位图View 类的接口
//

#pragma once


class CMFC2324显示位图View : public CView
{
protected: // 仅从序列化创建
	CMFC2324显示位图View();
	DECLARE_DYNCREATE(CMFC2324显示位图View)

// 特性
public:
	CMFC2324显示位图Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;//位图对象
	int m_nWidth;
	int m_nHeight;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC2324显示位图View();
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
	afx_msg void OnShowmap();
};

#ifndef _DEBUG  // MFC2-3.24显示位图View.cpp 中的调试版本
inline CMFC2324显示位图Doc* CMFC2324显示位图View::GetDocument() const
   { return reinterpret_cast<CMFC2324显示位图Doc*>(m_pDocument); }
#endif

