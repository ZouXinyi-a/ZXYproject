
// MFC2-3.24��ʾλͼ.h : MFC2-3.24��ʾλͼ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC2324��ʾλͼApp:
// �йش����ʵ�֣������ MFC2-3.24��ʾλͼ.cpp
//

class CMFC2324��ʾλͼApp : public CWinAppEx
{
public:
	CMFC2324��ʾλͼApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC2324��ʾλͼApp theApp;
