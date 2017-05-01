#if !defined(AFX_CUSTOM_H__13BEC55F_F641_4694_B3E1_5ABB50BDC880__INCLUDED_)
#define AFX_CUSTOM_H__13BEC55F_F641_4694_B3E1_5ABB50BDC880__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// custom.h : header file
//

#include <direct.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>

/////////////////////////////////////////////////////////////////////////////
// custom dialog

class custom : public CDialog
{
// Construction
public:
	custom(CWnd* pParent = NULL);   // standard constructor
	TCHAR m_currentdir[512];

// Dialog Data
	//{{AFX_DATA(custom)
	enum { IDD = IDD_DIALOG3 };
	CString	m_back;
	CString	m_icon;
	CString	m_replyx;
	CString	m_replyy;
	CString	m_replyfont;
	CString	m_replyheight;
	CString	m_replywidth;
	CString	m_speakfont;
	CString	m_speakheight;
	CString	m_speakwidth;
	CString	m_speakx;
	CString	m_speaky;
	CString	m_iconx;
	CString	m_icony;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(custom)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(custom)
	afx_msg void OnBackbutton();
	afx_msg void OnIconbutton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOM_H__13BEC55F_F641_4694_B3E1_5ABB50BDC880__INCLUDED_)
