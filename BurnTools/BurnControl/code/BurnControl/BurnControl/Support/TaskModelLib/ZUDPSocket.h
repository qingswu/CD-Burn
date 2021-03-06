///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
	Project		ZMediaServer
	ZUDPSocket	Header File
	Create		20100611		ZHAOTT
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
#ifndef	_ZUDPSOCKET_H_
#define	_ZUDPSOCKET_H_
///////////////////////////////////////////////////////////////////////////////
#define  DEFAULT_UDP_BUFFER_USED        (1472)
///////////////////////////////////////////////////////////////////////////////
#include "ZSocket.h"
///////////////////////////////////////////////////////////////////////////////
class	ZUDPSocket :  public ZSocket
{
///////////////////////////////////////////////////////////////////////////////
public:
	ZUDPSocket(ZTask* pTask = NULL);
	virtual ~ZUDPSocket();
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	BOOL	Create(INT nAddrFamily = AF_INET);
	virtual	BOOL	Close();
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	BOOL	Unbind();
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	int		SendTo(const void* sdata,const int ndata,UINT RemoteAddr,UINT RemotePort,int* nSend = NULL);
	virtual	int		RecvFrom(void* sdata,const int ndata,UINT* RemoteAddr,UINT* RemotePort,int* nRead = NULL);
	virtual	int		SendTo(const void* sdata,const int ndata,sockaddr_in* RemoteAddr,int* nSend = NULL);
	virtual	int		RecvFrom(void* sdata,const int ndata,sockaddr_in* RemoteAddr,int* nRead = NULL);
///////////////////////////////////////////////////////////////////////////////
public:
	BOOL			GetRemoteAddr(UINT* RemoteAddr,UINT* RemotePort);
	BOOL			SetRemoteAddr(UINT RemoteAddr,UINT RemotePort);
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	int		StreamCreate();
	virtual	int		StreamClose();
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	int		StreamRead(char* sdata,int ndata);
	virtual	int		StreamWrite(const char* sdata,int ndata);
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	BOOL	StreamReadable();
	virtual	BOOL	StreamWriteable();
	virtual BOOL	StreamError();
///////////////////////////////////////////////////////////////////////////////
public:
	virtual	BOOL	JoinMulticast(UINT RemoteAddr);
	virtual	BOOL	LeaveMulticast(UINT RemoteAddr);
	virtual	BOOL	SetMulticastInterface(UINT LocalAddr);
	virtual	BOOL	SetMulticastTTL(UINT nTTL);
///////////////////////////////////////////////////////////////////////////////
protected:
	struct	sockaddr_in	m_RemoteAddr;
	BOOL				m_bRemoteAddr;
	BOOL				m_bStreamSocket;
///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
#endif	//_ZUDPSOCKET_H_
///////////////////////////////////////////////////////////////////////////////
