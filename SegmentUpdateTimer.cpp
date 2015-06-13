#include "SegmentUpdateTimer.h"

#define TIME_MAX     (5) // 5ms

UI_8 CSegmentUpdateTimer::m_ucTime;
BOOL CSegmentUpdateTimer::m_isTimeout;

VOID CSegmentUpdateTimer::vInitialize()
{
	m_ucTime = 0;
	m_isTimeout = false;
}

VOID CSegmentUpdateTimer::vIncTime()
{
	if (m_ucTime < (TIME_MAX - 1)) {
		m_ucTime++;
	} else {
		m_isTimeout = true;
	}
}

BOOL CSegmentUpdateTimer::isCheckTime()
{
	BOOL isRet = m_isTimeout;
	if (isRet == true) {
		vInitialize();
	}

	return isRet;
}
