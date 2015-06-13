#ifndef _SEGMENT_UPDATE_TIMER_H_
#define _SEGMENT_UPDATE_TIMER_H_

#include "MySystype.h"

class CSegmentUpdateTimer {
  public:
	static VOID vInitialize();
	static VOID vIncTime();
	static BOOL isCheckTime();
	
  private:
	static UI_8 m_ucTime;
	static BOOL m_isTimeout;
};

#endif //_SEGMENT_UPDATE_TIMER_H_
