///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
	Project		ZMediaServer
	ZMath		Header File
	Create		20111226		ZHAOTT
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
#include "Common.h"
///////////////////////////////////////////////////////////////////////////////
#ifndef	_ZMD5_H_
#define	_ZMD5_H_
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class ZMD5
{
///////////////////////////////////////////////////////////////////////////////
public:
	ZMD5();
	virtual	~ZMD5();
///////////////////////////////////////////////////////////////////////////////
public:
	CHAR*	MD5String(CHAR* sString);
	CHAR*	MD5Memory(BYTE* pData,UINT nData);
///////////////////////////////////////////////////////////////////////////////
protected:
	VOID	MD5Init();
	BOOL	MD5Update(CHAR* sBuffer,UINT nBufferLen);
	BOOL	MD5Final(CHAR sMD5Code[16]);
	VOID	MD5Transform(INT32 nMD5Buffer[4],CHAR sMD5In[64]);
///////////////////////////////////////////////////////////////////////////////
protected:
	INT32		m_nMD5Buffer[4];
	INT32		m_nMD5Bits[2];
	CHAR		m_sMD5In[64];
///////////////////////////////////////////////////////////////////////////////
protected:
	STATIC	VOID	MD5Memset(CHAR* output,INT32 nVal,INT32 len);
	STATIC	VOID	MD5Memcopy(CHAR* output,CHAR* input,INT32 len);
///////////////////////////////////////////////////////////////////////////////
protected:
	STATIC	BOOL	Encode (CHAR* output,INT32 outputlen,INT32* input,INT32 inputlen);
	STATIC	BOOL	Decode (INT32* output,INT32 outputlen,CHAR* input,INT32 inputlen);
///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
#endif	//_ZMD5_H_
///////////////////////////////////////////////////////////////////////////////
