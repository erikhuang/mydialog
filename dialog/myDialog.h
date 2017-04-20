#pragma once
#include "acuidialog.h"
#include "resource.h"
//#include "resource.h"

class myDialog :
	public CAcUiDialog
{
public:
	myDialog(CWnd* pParent=NULL);
	~myDialog(void);


	enum { IDD = IDD_DIALOG_MYTEST };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonPoint();
	int GetLineColor();
};

