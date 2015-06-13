#ifndef _SEGMENT_UPDATE_PROCESS_H_
#define _SEGMENT_UPDATE_PROCESS_H_

#include "MySystype.h"

class CSegmentUpdateProcess {
  public:
	static VOID vInitialize();
	static VOID vMain();
	
  private:
	static UI_8 m_ucCount;
};

#endif // _SEGMENT_UPDATE_PROCESS_H_
