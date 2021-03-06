
// MFC3.31（3）View.h : CMFC331（3）View 类的接口
//

#pragma once


class CMFC331（3）View : public CView
{
protected: // 仅从序列化创建
	CMFC331（3）View();
	DECLARE_DYNCREATE(CMFC331（3）View)

// 特性
public:
	CMFC331（3）Doc* GetDocument() const;

// 操作
public:
CString str1;
CString str2;
CPoint cpoint,point;
int flag,h,x;
CRect rect;
CArray <CString,CString>m;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC331（3）View();
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.31（3）View.cpp 中的调试版本
inline CMFC331（3）Doc* CMFC331（3）View::GetDocument() const
   { return reinterpret_cast<CMFC331（3）Doc*>(m_pDocument); }
#endif

