// TreeBuilderDlg.h : header file
//

#if !defined(AFX_TREEBUILDERDLG_H__2A8CF5F2_9C63_425D_A863_E98D77596539__INCLUDED_)
#define AFX_TREEBUILDERDLG_H__2A8CF5F2_9C63_425D_A863_E98D77596539__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TCExpand.h"
#include "SortListCtrl.h"
#include "ReadOnlyComboBox.h"
#include <direct.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct ConversationText
{
	CString Text;
	CString Name;
} ConversationText;

typedef struct Conversation
{
	CString Name;
	int Flag[4];
	int FlagState[4];
	CString Attribute[4];
	int AttrTest[4];
	int AttrAmount[4];
	CString FailName;
	int ModFlag[4];
	int ModFlagState[4];
	CString ModAttribute[4];
	int ModAttrAmount[4];
	CString SpeakText;
	CString SpeakFile;
	int SpeakSpeed;
	CString ReplyText1;
	CString ReplyText2;
	CString ReplyText3;
	CString ReplyText4;
	CString ReplyText5;
	CString ReplyText6;
	CString ReplyCon1;
	CString ReplyCon2;
	CString ReplyCon3;
	CString ReplyCon4;
	CString ReplyCon5;
	CString ReplyCon6;
	BOOL ReplyExit1;
	BOOL ReplyExit2;
	BOOL ReplyExit3;
	BOOL ReplyExit4;
	BOOL ReplyExit5;
	BOOL ReplyExit6;
	CString Background;
	CString Icon;
	int IconX;
	int IconY;
	int SpeakX;
	int SpeakY;
	int SpeakWidth;
	int SpeakHeight;
	int SpeakFont;
	int ReplyX;
	int ReplyY;
	int ReplyWidth;
	int ReplyHeight;
	int ReplyFont;
} Conversation;

/////////////////////////////////////////////////////////////////////////////
// CTreeBuilderDlg dialog

class CTreeBuilderDlg : public CDialog
{
// Construction
public:
	CTreeBuilderDlg(CWnd* pParent = NULL);	// standard constructor

	void LoadConv();
	void Indent(int indent, FILE *f);
	CArray<ConversationText, ConversationText> Text;
	CArray<Conversation, Conversation> ConData;
	int ConPtr;
	TCHAR m_currentdir[512];
	CString Background;
	CString Icon;
	int SpeakX;
	int SpeakY;
	int SpeakWidth;
	int SpeakHeight;
	int SpeakFont;
	int ReplyX;
	int ReplyY;
	int ReplyWidth;
	int ReplyHeight;
	int ReplyFont;

// Dialog Data
	//{{AFX_DATA(CTreeBuilderDlg)
	enum { IDD = IDD_TREEBUILDER_DIALOG };
	CEdit	m_speedbox;
	CReadOnlyComboBox	m_replycontext6;
	CReadOnlyComboBox	m_replycontext5;
	CReadOnlyComboBox	m_replycontext4;
	CReadOnlyComboBox	m_replycontext3;
	CReadOnlyComboBox	m_replycontext2;
	CReadOnlyComboBox	m_replycontext1;
	CReadOnlyComboBox	m_replytext6;
	CReadOnlyComboBox	m_replytext5;
	CReadOnlyComboBox	m_replytext4;
	CReadOnlyComboBox	m_replytext3;
	CReadOnlyComboBox	m_replytext2;
	CReadOnlyComboBox	m_replytext1;
	CReadOnlyComboBox	m_speaktext;
	CReadOnlyComboBox	m_failname;
	CSortListCtrl	m_conlist1;
	CSortListCtrl	m_convlist;
	CString	m_editflag1;
	CString	m_editflag2;
	CString	m_editflag3;
	CString	m_editflag4;
	int		m_flagstate1;
	CString	m_coname;
	int		m_flagstate2;
	int		m_flagstate3;
	int		m_flagstate4;
	CString	m_editattr1;
	CString	m_editattr2;
	CString	m_editattr6;
	CString	m_editattr7;
	int		m_attrstate1;
	int		m_attrstate2;
	int		m_attrstate3;
	int		m_attrstate4;
	CString	m_editval1;
	CString	m_editval2;
	CString	m_editval6;
	CString	m_editval7;
	CString	m_fail;
	CString	m_modflag1;
	CString	m_modflag2;
	CString	m_modflag3;
	CString	m_modflag4;
	int		m_modflagstate1;
	int		m_modflagstate2;
	int		m_modflagstate3;
	int		m_modflagstate4;
	CString	m_modattr1;
	CString	m_modattr2;
	CString	m_modattr3;
	CString	m_modattr4;
	CString	m_modval1;
	CString	m_modval2;
	CString	m_modval3;
	CString	m_modval4;
	CString	m_speak;
	CString	m_reply1;
	CString	m_reply2;
	CString	m_reply3;
	CString	m_reply4;
	CString	m_reply5;
	CString	m_reply6;
	CString	m_replycon1;
	CString	m_replycon2;
	CString	m_replycon3;
	CString	m_replycon4;
	CString	m_replycon5;
	CString	m_replycon6;
	BOOL	m_replyexit1;
	BOOL	m_replyexit2;
	BOOL	m_replyexit3;
	BOOL	m_replyexit4;
	BOOL	m_replyexit5;
	BOOL	m_replyexit6;
	CString	m_speed;
	CString	m_soundfile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeBuilderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTreeBuilderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddconv();
	afx_msg void OnEditconv();
	afx_msg void OnDelconv();
	afx_msg void OnSaveconv();
	afx_msg void OnAddcon();
	afx_msg void OnClickConlist1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEditflag1();
	afx_msg void OnChangeEditflag2();
	afx_msg void OnChangeEditflag3();
	afx_msg void OnChangeEditflag4();
	afx_msg void OnRadioflag1();
	afx_msg void OnRadioflag3();
	afx_msg void OnRadioflag5();
	afx_msg void OnRadioflag4();
	afx_msg void OnRadio2();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	afx_msg void OnChangeEditattr1();
	afx_msg void OnChangeEditattr2();
	afx_msg void OnChangeEditattr6();
	afx_msg void OnChangeEditattr7();
	afx_msg void OnRadioeq1();
	afx_msg void OnRadiogt1();
	afx_msg void OnRadiolt1();
	afx_msg void OnRadioneq1();
	afx_msg void OnRadioeq2();
	afx_msg void OnRadioeq3();
	afx_msg void OnRadioeq4();
	afx_msg void OnRadiogt2();
	afx_msg void OnRadiogt3();
	afx_msg void OnRadiogt4();
	afx_msg void OnRadiolt2();
	afx_msg void OnRadiolt3();
	afx_msg void OnRadiolt4();
	afx_msg void OnRadioneq2();
	afx_msg void OnRadioneq3();
	afx_msg void OnRadioneq4();
	afx_msg void OnChangeEditval1();
	afx_msg void OnChangeEditval2();
	afx_msg void OnChangeEditval6();
	afx_msg void OnChangeEditval7();
	afx_msg void OnSelchangeFail();
	afx_msg void OnChangeEditflag5();
	afx_msg void OnChangeEditflag6();
	afx_msg void OnChangeEditflag7();
	afx_msg void OnChangeEditflag8();
	afx_msg void OnRadioflag2();
	afx_msg void OnRadioflag6();
	afx_msg void OnRadioflag7();
	afx_msg void OnRadioflag8();
	afx_msg void OnRadio3();
	afx_msg void OnRadio7();
	afx_msg void OnRadio8();
	afx_msg void OnRadio9();
	afx_msg void OnChangeEditattr3();
	afx_msg void OnChangeEditattr4();
	afx_msg void OnChangeEditattr8();
	afx_msg void OnChangeEditattr9();
	afx_msg void OnChangeEditval3();
	afx_msg void OnChangeEditval4();
	afx_msg void OnChangeEditval8();
	afx_msg void OnChangeEditval9();
	afx_msg void OnSelchangeSpeak();
	afx_msg void OnSelchangeReply1();
	afx_msg void OnSelchangeReply2();
	afx_msg void OnSelchangeReply3();
	afx_msg void OnSelchangeReply4();
	afx_msg void OnSelchangeReply5();
	afx_msg void OnSelchangeReply6();
	afx_msg void OnSelchangeReplycon1();
	afx_msg void OnSelchangeReplycon2();
	afx_msg void OnSelchangeReplycon3();
	afx_msg void OnSelchangeReplycon4();
	afx_msg void OnSelchangeReplycon5();
	afx_msg void OnSelchangeReplycon6();
	afx_msg void OnReplyexit1();
	afx_msg void OnReplyexit2();
	afx_msg void OnReplyexit3();
	afx_msg void OnReplyexit4();
	afx_msg void OnReplyexit5();
	afx_msg void OnReplyexit6();
	afx_msg void OnDelcon();
	afx_msg void OnSave();
	afx_msg void OnLoad();
	afx_msg void OnScript();
	afx_msg void OnChangeSpeed();
	afx_msg void OnSndbutton();
	afx_msg void OnChangeSoundfile();
	afx_msg void OnCustom();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEBUILDERDLG_H__2A8CF5F2_9C63_425D_A863_E98D77596539__INCLUDED_)
