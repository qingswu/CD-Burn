///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
	Project			ZMediaServer
	ZRTSPRequest	Header File
	Create			20100728		ZHAOTT		RTSP
	Modify			20110602		ZHAOTT		RTCP
	Modify			20110708		ZHAOTT		RTP Over RTSP
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
#ifndef	_ZTSPREQUEST_H_
#define	_ZTSPREQUEST_H_
///////////////////////////////////////////////////////////////////////////////
#include "ZRTSPProtocol.h"
#include "ZRTSPMessage.h"
///////////////////////////////////////////////////////////////////////////////
class	ZHeaderParser;
class	ZRTSPSession;
class	ZRTSPRequest;
///////////////////////////////////////////////////////////////////////////////
class ZRTSPRequest : public ZRTSPMessage , public ZRequest
{
///////////////////////////////////////////////////////////////////////////////
public:
	ZRTSPRequest(ZSession* pSession,ZSessionStream* pStream);
	virtual ~ZRTSPRequest();
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	int		SendRequest(DWORD nMethod);
	virtual	int		ReadRequest();
	virtual	int		CleanRequest();
///////////////////////////////////////////////////////////////////////////////
protected:
	virtual	BOOL	ParseFirstLine(ZHeaderParser* pHeader);
///////////////////////////////////////////////////////////////////////////////
protected:
	virtual	void	GetFirstLine(char*);
	virtual	void	GetEndLine(char*);
///////////////////////////////////////////////////////////////////////////////
protected:
	BOOL	ParseURI(ZHeaderParser* pHeader,int* nPos);
///////////////////////////////////////////////////////////////////////////////
public:
	friend	class	ZRTSPSession;
///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
#endif	//_ZTSPREQUEST_H_
///////////////////////////////////////////////////////////////////////////////
