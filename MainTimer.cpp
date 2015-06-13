#include "MainTimer.h"
#include "SegmentUpdateTimer.h"
#include "SegmentDataTimer.h"

#define METRO_INTERVAL_1MS      (1)
#define METRO_INTERVAL_100MS  (100)

Metro CMainTimer::m_Metro1ms = Metro(METRO_INTERVAL_1MS);
Metro CMainTimer::m_Metro100ms = Metro(METRO_INTERVAL_100MS);

VOID CMainTimer::vInitialize()
{
	CSegmentUpdateTimer::vInitialize();
	CSegmentDataTimer::vInitialize();
}

VOID CMainTimer::vMain()
{
	if (m_Metro1ms.check() == true) {
		vInterval1msProc();
	}

	if (m_Metro100ms.check() == true) {
		vInterval100msProc();
	}
}

VOID CMainTimer::vInterval1msProc()
{
	CSegmentUpdateTimer::vIncTime();
}

VOID CMainTimer::vInterval100msProc()
{
	CSegmentDataTimer::vIncTime();
}
