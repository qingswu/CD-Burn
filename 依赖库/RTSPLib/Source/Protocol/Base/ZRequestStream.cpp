#include "ZRequestStream.h"
#include "ZEvent.h"
///////////////////////////////////////////////////////////////////////////////
//#define	DEFAULT_REQUEST_OUTPUT	1
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ZRequestStream::ZRequestStream()
:ZSessionStream()
{
}
ZRequestStream::~ZRequestStream()
{
}
///////////////////////////////////////////////////////////////////////////////
int ZRequestStream::ReadRequest()
{
	return ZSessionStream::ReadStream();
}
int ZRequestStream::SendRequest(const char* sRequest,int nRequest)
{
	return ZSessionStream::SendStream(sRequest,nRequest);
}
int ZRequestStream::CleanRequest()
{

	return ZSessionStream::CleanStream();
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
