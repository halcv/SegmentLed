#ifndef _SEGMENT_DATA_PROCESS_H_
#define _SEGMENT_DATA_PROCESS_H_

#include "MySystype.h"
#include "SegmentDriver.h"

class CSegmentDataProcess {
  public:
	static VOID vInitialize();
	static VOID vMain();
	
  private:
	static UI_8 m_ucData[CSegmentDriver::E_DIG_NUM_MAX];
	static UI_16 m_unCount;

	static VOID vCreateData();
};

#endif // _SEGMENT_DATA_PROCESS_H_
