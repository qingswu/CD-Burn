///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
	Project		ZMediaServer
	ZBaseStream	Header File
	Create		20100707		ZHAOTT
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
#ifndef	_ZBASESTREAM_H_
#define	_ZBASESTREAM_H_
///////////////////////////////////////////////////////////////////////////////
#include "public.h"
///////////////////////////////////////////////////////////////////////////////
class	ZBaseStream;
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define	ZSOCKET_CLOSED		0	//socket closed
#define	ZSOCKET_TIMEOUT		-1	//socket timeout
#define	ZSOCKET_ERROR		-2	//socket error
///////////////////////////////////////////////////////////////////////////////
class ZBaseStream
{
///////////////////////////////////////////////////////////////////////////////
public:
	ZBaseStream();
	virtual	~ZBaseStream();
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	int	StreamCreate()									= 0;
	virtual	int	StreamClose()									= 0;
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	int		StreamRead(char* sdata,int ndata)			= 0;
	virtual	int		StreamWrite(const char* sdata,int ndata)	= 0;
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	BOOL	StreamSeek(UINT64 nPos)						= 0;
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	BOOL	StreamReadable()							= 0;
	virtual	BOOL	StreamWriteable()							= 0;
	virtual BOOL	StreamError()								= 0;
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	BOOL	RequestEvent(UINT nEvent)					= 0;
	virtual	BOOL	RemoveEvent(UINT nEvent)					= 0;
///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
#endif	//_ZBASESTREAM_H_
///////////////////////////////////////////////////////////////////////////////
