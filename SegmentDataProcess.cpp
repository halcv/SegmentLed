#include "SegmentDataProcess.h"
#include "SegmentDataTimer.h"

#define COUNT_MAX     (1000)

UI_8 CSegmentDataProcess::m_ucData[CSegmentDriver::E_DIG_NUM_MAX] = {
	0,0,0
};

UI_16 CSegmentDataProcess::m_unCount;

VOID CSegmentDataProcess::vInitialize()
{
	m_unCount = 0;
}

VOID CSegmentDataProcess::vMain()
{
	if (CSegmentDataTimer::isCheckTime() == false) {
		return;
	}

	vCreateData();
	
	for (INT i = 0;i < CSegmentDriver::E_DIG_NUM_MAX;i++) {
		CSegmentDriver::vSetSegmentData((CSegmentDriver::E_DIG_NUM)i,m_ucData[i]);
	}
}

VOID CSegmentDataProcess::vCreateData()
{
	m_ucData[2] = m_unCount / 100;
	m_ucData[1] = (m_unCount - (m_ucData[2] * 100)) / 10;
	m_ucData[0] = m_unCount - (m_ucData[2] * 100) - (m_ucData[1] * 10);

	m_unCount++;
	if (m_unCount >= COUNT_MAX) {
		m_unCount = 0;
	}
}
