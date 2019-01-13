#pragma once
#include <Windows.h>

class CBuffer
{
public:
	CBuffer(void);
	~CBuffer(void);

	ULONG GetBufferMaxLength();
	ULONG ReadBuffer(PBYTE Buffer, ULONG ulLength);
	ULONG GetBufferLength(); //�����Ч���ݳ���;
	ULONG DeAllocateBuffer(ULONG ulLength);
	VOID ClearBuffer();
	ULONG ReAllocateBuffer(ULONG ulLength);
	BOOL WriteBuffer(PBYTE Buffer, ULONG ulLength);
	PBYTE GetBuffer(ULONG ulPos=0);
	ULONG RemoveComletedBuffer(ULONG ulLength);
	VOID  ReleaseMember();
	VOID InitMember();

protected:
	PBYTE	m_Base;
	PBYTE	m_Ptr;
	ULONG	m_ulMaxLength;
	CRITICAL_SECTION  m_cs;
};