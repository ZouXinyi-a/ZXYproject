
// MFC3.09（2）Doc.h : CMFC309（2）Doc 类的接口
//


#pragma once


class CMFC309（2）Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFC309（2）Doc();
	DECLARE_DYNCREATE(CMFC309（2）Doc)

// 特性
public:

// 操作
public:
CArray<CRect,CRect&> ca;
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFC309（2）Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
