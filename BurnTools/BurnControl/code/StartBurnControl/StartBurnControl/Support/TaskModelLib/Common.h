///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
	Project		ZMediaServer
	Common		Header File
	Create		20100603		ZHAOTT
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
#ifndef	_COMMON_H_
#define	_COMMON_H_
///////////////////////////////////////////////////////////////////////////////
#include "public.h"
#include "ZOSMemory.h"
#include "ZLog.h"
#include "ErrorCodeTable.h"
#include "ZMath.h"
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
typedef	enum	_LOG_LEVEL_
{
	LOG_ERROR	= 0,
	LOG_WARNING,
	LOG_INFORMATION
}LOG_LEVEL;
///////////////////////////////////////////////////////////////////////////////
class	ZLog;
extern	ZLog*	pLog;
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifdef	_ASSERT_
#define	TMASSERT(c)															\
if(!c)																		\
{																			\
	char s[256];															\
	s[255] = 0;																\
	snprintf(s,255,"Assert: %s, %d, %s\r\n",__FILE__,__LINE__,#c);			\
	ZObject::Assert(s);														\
}
#define	ASSERT_VOLID_OBJECT(p)												\
if(ZObject::IsValidObject(p)>0)												\
{																			\
	char s[256];															\
	s[255] = 0;																\
	snprintf(s,255,"Assert: %s, %d, 0x%08X\r\n",__FILE__,__LINE__,(int)p);	\
	ZObject::Assert(s);														\
}
#else
#define	TMASSERT(c)
#define	ASSERT_VOLID_OBJECT(p)
#endif	//_ASSERT_
///////////////////////////////////////////////////////////////////////////////
#define	DEFAULT_OBJECT_LABEL			"\x4F\x42\x4A\x45\x43\x54\x00\x00"
#define	DEFAULT_OBJECT_LABEL_LENGTH		8
#define	DEFAULT_OBJECT_VPTR_SIZE		(1*sizeof(void*))
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class ZObject
{
///////////////////////////////////////////////////////////////////////////////
public:
	ZObject(const char* sObjectName = NULL);
	virtual ~ZObject();
///////////////////////////////////////////////////////////////////////////////
public:
	char*	GetObjectName();
///////////////////////////////////////////////////////////////////////////////
protected:
	char	m_sObjectLabel[DEFAULT_OBJECT_LABEL_LENGTH];
	char	m_sObjectName[(MAX_KEY_LABEL+4)];
///////////////////////////////////////////////////////////////////////////////
public:
	static void	Assert(const char *sAssert);
///////////////////////////////////////////////////////////////////////////////
public:
	static int IsValidObject(ZObject* pPoint);
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
UINT16	Common_set16(char* s,UINT16 n);
UINT32	Common_set24(char* s,UINT32 n);
UINT32	Common_set32(char* s,UINT32 n);
UINT64	Common_set64(char* s,UINT64 n);
BYTE	Common_get8(char* s);
UINT16	Common_get16(char* s);
UINT32	Common_get24(char* s);
UINT32	Common_get32(char* s);
UINT64	Common_get64(char* s);
UINT16	Common_swap16(UINT16 n);
UINT32	Common_swap24(UINT32 n);
UINT32	Common_swap32(UINT32 n);
UINT64	Common_swap64(UINT64 n);
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int	Common_Base64Encode(const char* sSource,int nSource,char* sTarget = NULL,int nTarget = 0);
int	Common_Base64Decode(const char* sSource,int nSource,char* sTarget = NULL,int nTarget = 0);
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define	SETUINT8(s,n)	(((char*)s)[0]=(n&0xFF))
#define	SETUINT16(s,n)	Common_set16(s,n)
#define	SETUINT24(s,n)	Common_set24(s,n)
#define	SETUINT32(s,n)	Common_set32(s,n)
#define	SETUINT64(s,n)	Common_set64(s,n)
#define	GETUINT8(s)		(((char*)s)[0]&0xFF)
#define	GETUINT16(s)	Common_get16(s)
#define	GETUINT24(s)	Common_get24(s)
#define	GETUINT32(s)	Common_get32(s)
#define	GETUINT64(s)	Common_get64(s)
#define	SWAP16(n)		Common_swap16(n)
#define	SWAP24(n)		Common_swap24(n)
#define	SWAP32(n)		Common_swap32(n)
#define	SWAP64(n)		Common_swap64(n)
///////////////////////////////////////////////////////////////////////////////
#endif	//_COMMON_H_
///////////////////////////////////////////////////////////////////////////////
