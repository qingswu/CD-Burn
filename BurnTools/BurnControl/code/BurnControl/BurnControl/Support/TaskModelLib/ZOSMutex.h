///////////////////////////////////////////////////////////////////////////////
/******************************************************************************
	Project		ZMediaServer
	ZOSMutex	Header File
	Create		20100603		ZHAOTT
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
#ifndef	_ZOSMUTEX_H_
#define	_ZOSMUTEX_H_
///////////////////////////////////////////////////////////////////////////////
#include "ZOS.h"
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class	ZOSCond;
class	ZOSMutex;
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class ZOSMutex : public ZObject
{
///////////////////////////////////////////////////////////////////////////////
public:
	ZOSMutex(const char* sName);
	~ZOSMutex();
///////////////////////////////////////////////////////////////////////////////
public:
	inline void	Lock();
	inline void	Unlock();
	inline BOOL TryLock();
///////////////////////////////////////////////////////////////////////////////
protected:
#if	defined(__PTHREADS_MUTEXES__)||defined(_WIN32_)
	void	RecursiveLock();
	void	RecursiveUnlock();
	BOOL	RecursiveTryLock();
#endif	//defined(__PTHREADS_MUTEXES__)||defined(_WIN32_)
///////////////////////////////////////////////////////////////////////////////
private:
#if	defined(_WIN32_)
	CRITICAL_SECTION	m_pMutex;
	DWORD				m_pHolder;
	UINT				m_pHolderCount;
#else
#if	defined(__PTHREADS_MUTEXES__)
	pthread_mutex_t	m_pMutex;
#if	defined(_MINGW_)
	void*			m_pHolder;
#else
	pthread_t		m_pHolder;
#endif	//_MINGW_
	UINT			m_pHolderCount;
#else
	mymutex_t		m_pMutex;
#endif	//(__PTHREADS_MUTEXES__)
#endif	//(_WIN32_)
///////////////////////////////////////////////////////////////////////////////
	friend class	ZOSCond;
///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
class ZOSMutexLocker
{
///////////////////////////////////////////////////////////////////////////////
public:
	ZOSMutexLocker(ZOSMutex *pMutex):m_pMutex(pMutex)
					{ if(m_pMutex != 0) m_pMutex->Lock(); }
	~ZOSMutexLocker()
					{ if(m_pMutex != 0) m_pMutex->Unlock(); }
///////////////////////////////////////////////////////////////////////////////
public:
	void Lock()		{ if(m_pMutex != 0) m_pMutex->Lock(); }
	void Unlock()	{ if(m_pMutex != 0) m_pMutex->Unlock(); }
	BOOL TryLock()	{ if(m_pMutex != 0) return m_pMutex->TryLock(); return FALSE;}
///////////////////////////////////////////////////////////////////////////////
private:
	ZOSMutex*	m_pMutex;
///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
inline void ZOSMutex::Lock()
{
#if	defined(__PTHREADS_MUTEXES__)||defined(_WIN32_)
	this->RecursiveLock();
#else
	mymutex_lock(m_pMutex);
#endif	//defined(__PTHREADS_MUTEXES__)||defined(_WIN32_)
};
inline void ZOSMutex::Unlock()
{
#if	defined(__PTHREADS_MUTEXES__)||defined(_WIN32_)
	this->RecursiveUnlock();
#else
	mymutex_unlock(m_pMutex);
#endif	//defined(__PTHREADS_MUTEXES__)||defined(_WIN32_)
};
inline BOOL ZOSMutex::TryLock()
{
#if	defined(__PTHREADS_MUTEXES__)||defined(_WIN32_)
	return this->RecursiveTryLock();
#else
	return (BOOL)mymutex_try_lock(m_pMutex);
#endif	//defined(__PTHREADS_MUTEXES__)||defined(_WIN32_)
};
///////////////////////////////////////////////////////////////////////////////
#endif	//_ZOSMUTEX_H_
///////////////////////////////////////////////////////////////////////////////
