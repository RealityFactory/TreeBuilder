#if !defined(AFX_CONNAME_H__F5501847_B615_4EA6_B47F_D335177C5111__INCLUDED_)
#define AFX_CONNAME_H__F5501847_B615_4EA6_B47F_D335177C5111__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// conname.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// conname dialog

class conname : public CDialog
{
// Construction
public:
	conname(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(conname)
	enum { IDD = IDD_DIALOG2 };
	CString	m_conn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(conname)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(conname)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNAME_H__F5501847_B615_4EA6_B47F_D335177C5111__INCLUDED_)
