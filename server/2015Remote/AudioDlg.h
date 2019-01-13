#pragma once

#include "IOCPServer.h"
#include "Audio.h"

// CAudioDlg �Ի���

class CAudioDlg : public CDialog
{
	DECLARE_DYNAMIC(CAudioDlg)

public:
	CAudioDlg(CWnd* pParent = NULL, IOCPServer* IOCPServer = NULL, CONTEXT_OBJECT *ContextObject = NULL);   // ��׼���캯��
	virtual ~CAudioDlg();
	CONTEXT_OBJECT* m_ContextObject;
	IOCPServer*     m_iocpServer;
	HICON          m_hIcon;
	CString       m_strIPAddress;
	DWORD         m_nTotalRecvBytes;
	BOOL          m_bIsWorking;
	BOOL		  m_bThreadRun;
	HANDLE        m_hWorkThread;
	CAudio		  m_AudioObject;

	static DWORD  CAudioDlg::WorkThread(LPVOID lParam);

	void CAudioDlg::OnReceiveComplete(void);
// �Ի�������
	enum { IDD = IDD_DIALOG_AUDIO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bSend;
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
};