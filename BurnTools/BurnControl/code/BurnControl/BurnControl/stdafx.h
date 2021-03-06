
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展

#include <afxdisp.h>        // MFC 自动化类

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

//////////////////////////////////////////////////////////////////////////

#pragma warning(disable:4996)

//to make a unique message value
#define DECLARE_USER_MESSAGE(name) \
    static const UINT name = ::RegisterWindowMessage(name##_MSG);

#include "TaskModel.h"
#include "NCX.h"

#include "BtnST.h"
#include "ConfigurableFile.h"
#include "DialogCustom.h"
#include "CustomStatic.h"
#include "PicStatic.h"
#include "CharsetConvertMFC.h"
#include "SystemTray.h"
#include "WindowsProcess.h"
#include "NetUtil.h"
#include "CommonUtil.h"
#include "Ini.h"
#include "tinyxml.h"

#define BURNCONTROL_TAG_NAME        "burnControl"
#define BURNCONTROL_LOG_PATH        "C:\\CS\\BurnControl\\Log\\"
#define BURNCONTROL_CFG_PATH        "C:\\CS\\BurnControl\\config\\"
#define XML_RTBBACKUP_PATH          "C:\\CS\\BurnControl\\config\\RTBBackup.xml"

#define FILEANYWHERE_PORT           18479
#define BURNSERVER_PORT             8888
#define BURNCONTROL_SERVER_PORT     7788