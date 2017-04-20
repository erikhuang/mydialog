// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#if !defined(AFX_STDAFX_H__5A964FB5_3201_11D2_8C8D_0040054247F9__INCLUDED_)
#define AFX_STDAFX_H__5A964FB5_3201_11D2_8C8D_0040054247F9__INCLUDED_

#if defined(_DEBUG) && !defined(AC_FULL_DEBUG)
#define WAS_DEBUG
#undef _DEBUG
#endif

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            //  从 Windows 头文件中排除极少使用的信息
#endif

#include <afx.h>
#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <iostream>
// Windows 头文件:
#include <windows.h>



// TODO: 在此处引用程序需要的其他头文件


#include <math.h>

#include "accmd.h"
#include "acdb.h"
#include "acdbabb.h"
#include "aced.h"
#include "acedinpt.h"
#include "acestext.h"
#include "acgi.h"
#include "acgiutil.h"
#include "AcGsManager.h"
#include "acgs.h"
#include "gs.h"
#include "AcDbLMgr.h"
#include "actrans.h"
#include "adesk.h"
#include "adeskabb.h"
#include "ads.h"
#include "adscodes.h"
#include "adsdef.h"
#include "adsdlg.h"
#include "adslib.h"
#include "adsrxdef.h"
#include "appinfo.h"
#include "dbacis.h"
#include "dbapserv.h"
#include "dbaudita.h"
#include "dbbody.h"
#include "dbboiler.h"
#include "dbcfilrs.h"
#include "dbcurve.h"
#include "dbdate.h"
#include "dbdict.h"
#include "dbdictdflt.h"
#include "dbelipse.h"
#include "dbents.h"
#include "dbfcf.h"
#include "dbfiler.h"
#include "dbfilter.h"
#include "dbframe.h"
#include "dbgroup.h"
#include "dbhandle.h"
#include "dbhatch.h"
#include "dbid.h"
#include "dbidar.h"
#include "dbidmap.h"
#include "dbid_ops.h"
#include "dbimage.h"
#include "dbindex.h"
#include "dbintar.h"
#include "dbjig.h"
#include "dblayout.h"
#include "dblead.h"
#include "dbltrans.h"
#include "dblyfilt.h"
#include "dblyindx.h"
#include "dbmain.h"
#include "dbmline.h"
#include "dbmstyle.h"
#include "dbmtext.h"
#include "dbole.h"
#include "dbpl.h"
#include "dbplhldr.h"
#include "dbplotsettings.h"
#include "dbproxy.h"
#include "dbptrar.h"
#include "dbray.h"
#include "dbregion.h"
#include "dbsol3d.h"
#include "dbspline.h"
#include "dbspfilt.h"
#include "dbspindx.h"
#include "dbsubeid.h"
#include "dbsymtb.h"
#include "dbxline.h"
#include "dbxrecrd.h"
#include "dbxutil.h"
#include "geapln3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "geassign.h"
#include "geblok2d.h"
#include "geblok3d.h"
#include "gebndpln.h"
#include "gecbndry.h"
#include "gecint2d.h"
#include "gecint3d.h"
#include "gecomp2d.h"
#include "gecomp3d.h"
#include "gecone.h"
#include "gecspl2d.h"
#include "gecspl3d.h"
#include "gecurv2d.h"
#include "gecurv3d.h"
#include "gecylndr.h"
#include "gedblar.h"
#include "gedll.h"
#include "gedwgio.h"
#include "gedxfio.h"
#include "geell2d.h"
#include "geell3d.h"
#include "geent2d.h"
#include "geent3d.h"
#include "geextc2d.h"
#include "geextc3d.h"
#include "geextsf.h"
#include "gefileio.h"
#include "gefiler.h"
#include "gegbl.h"
#include "gegblabb.h"
#include "geintarr.h"
#include "geintrvl.h"
#include "gekvec.h"
#include "gelent2d.h"
#include "gelent3d.h"
#include "gelibver.h"
#include "geline2d.h"
#include "geline3d.h"
#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gemat2d.h"
#include "gemat3d.h"
#include "genurb2d.h"
#include "genurb3d.h"
#include "genurbsf.h"
#include "geoffc2d.h"
#include "geoffc3d.h"
#include "geoffsf.h"
#include "gepent2d.h"
#include "gepent3d.h"
#include "geplanar.h"
#include "geplane.h"
#include "geplin2d.h"
#include "geplin3d.h"
#include "gepnt2d.h"
#include "gepnt3d.h"
#include "geponc2d.h"
#include "geponc3d.h"
#include "geponsrf.h"
#include "gepos2d.h"
#include "gepos3d.h"
#include "gept2dar.h"
#include "gept3dar.h"
#include "geray2d.h"
#include "geray3d.h"
#include "gescl2d.h"
#include "gescl3d.h"
#include "gesent2d.h"
#include "gesent3d.h"
#include "gesphere.h"
#include "gesurf.h"
#include "getol.h"
#include "getorus.h"
#include "gevc2dar.h"
#include "gevc3dar.h"
#include "gevec2d.h"
#include "gevec3d.h"
#include "gevptar.h"
#include "gexbndsf.h"
#include "graph.h"
#include "imgdef.h"
#include "imgent.h"
#include "imgvars.h"
#include "lngtrans.h"
//#include "migrtion.h"
#include "oleaprot.h"
#include "ol_errno.h"
#include "rxboiler.h"
#include "rxclass.h"
#include "rxdefs.h"
#include "rxdict.h"
#include "rxditer.h"
#include "rxdlinkr.h"
#include "rxiter.h"
#include "rxkernel.h"
#include "rxmfcapi.h"
#include "rxnames.h"
#include "rxobject.h"
#include "rxregsvc.h"
#include "rxsrvice.h"
#include "xgraph.h"
#include "adui.h"
#include "acui.h"
#include "acuiDialog.h"




#endif // !defined(AFX_STDAFX_H__5A964FB5_3201_11D2_8C8D_0040054247F9__INCLUDED_)

