#ifndef _MAIN_TIMER_H_
#define _MAIN_TIMER_H_

#include <Metro.h>
#include "MySystype.h"

class CMainTimer {
  public:
	static VOID vInitialize();
	static VOID vMain();
	
  private:
	static Metro m_Metro1ms;
	static Metro m_Metro100ms;
	
	static VOID vInterval1msProc();
	static VOID vInterval100msProc();
};

#endif // _MAIN_TIMER_H_
