#include "SegmentDataTimer.h"

#define TIME_MAX       (2)

UI_8 CSegmentDataTimer::m_ucTime;
BOOL CSegmentDataTimer::m_isTimeout;

VOID CSegmentDataTimer::vInitialize()
{
	m_ucTime = 0;
	m_isTimeout = false;
}

VOID CSegmentDataTimer::vIncTime()
{
	if (m_ucTime < (TIME_MAX - 1)) {
		m_ucTime++;
	} else {
		m_isTimeout = true;
	}
}

BOOL CSegmentDataTimer::isCheckTime()
{
	BOOL isRet = m_isTimeout;
	if (isRet == true) {
		vInitialize();
	}

	return isRet;
}

