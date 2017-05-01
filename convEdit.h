#if !defined(AFX_CONVEDIT_H__12E1A0A8_5B92_45E0_AEA5_76A1340011A6__INCLUDED_)
#define AFX_CONVEDIT_H__12E1A0A8_5B92_45E0_AEA5_76A1340011A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// convEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// convEdit dialog

class convEdit : public CDialog
{
// Construction
public:
	convEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(convEdit)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_name;
	CString	m_cname;
	CString	m_ctext;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(convEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(convEdit)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVEDIT_H__12E1A0A8_5B92_45E0_AEA5_76A1340011A6__INCLUDED_)
