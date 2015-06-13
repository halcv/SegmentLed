#include <Metro.h>
#include "MySystype.h"
#include "MainTimer.h"
#include "SegmentUpdateProcess.h"
#include "SegmentDriver.h"
#include "SegmentDataProcess.h"

static VOID vMain_Initialize();

VOID setup()
{
	vMain_Initialize();
}

VOID loop()
{
	CMainTimer::vMain();
	CSegmentDataProcess::vMain();
	CSegmentUpdateProcess::vMain();
}

static VOID vMain_Initialize()
{
	CSegmentDriver::vInitialize();
	CSegmentUpdateProcess::vInitialize();
	CSegmentDataProcess::vInitialize();
	CMainTimer::vInitialize();
}
