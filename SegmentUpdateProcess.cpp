#include "SegmentUpdateProcess.h"
#include "SegmentUpdateTimer.h"
#include "SegmentDriver.h"

UI_8 CSegmentUpdateProcess::m_ucCount;

VOID CSegmentUpdateProcess::vInitialize()
{
	m_ucCount = 0;
}

VOID CSegmentUpdateProcess::vMain()
{
	if (CSegmentUpdateTimer::isCheckTime() == false) {
		return;
	}

	CSegmentDriver::vUpdateSegment((CSegmentDriver::E_DIG_NUM)m_ucCount);
	m_ucCount++;
	if (m_ucCount >= CSegmentDriver::E_DIG_NUM_MAX) {
		m_ucCount = 0;
	}
}
