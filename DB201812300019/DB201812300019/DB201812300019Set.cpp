
// DB201812300019Set.cpp : CDB201812300019Set ���ʵ��
//

#include "stdafx.h"
#include "DB201812300019.h"
#include "DB201812300019Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB201812300019Set ʵ��

// ���������� 2020��5��5��, 15:08

IMPLEMENT_DYNAMIC(CDB201812300019Set, CRecordset)

CDB201812300019Set::CDB201812300019Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDB201812300019Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f;DBQ=D:\\visual \x5b9e\x9a8c\\Database1.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CDB201812300019Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CDB201812300019Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);

}
/////////////////////////////////////////////////////////////////////////////
// CDB201812300019Set ���

#ifdef _DEBUG
void CDB201812300019Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB201812300019Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

