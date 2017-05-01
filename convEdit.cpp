// convEdit.cpp : implementation file
//

#include "stdafx.h"
#include "TreeBuilder.h"
#include "convEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// convEdit dialog


convEdit::convEdit(CWnd* pParent /*=NULL*/)
	: CDialog(convEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(convEdit)
	m_cname = _T("");
	m_ctext = _T("");
	//}}AFX_DATA_INIT
}


void convEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(convEdit)
	DDX_Control(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_NAME, m_cname);
	DDX_Text(pDX, IDC_TEXT, m_ctext);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(convEdit, CDialog)
	//{{AFX_MSG_MAP(convEdit)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// convEdit message handlers
