#ifndef _SEGMENT_DRIVER_H_
#define _SEGMENT_DRIVER_H_

#include "MySystype.h"

#define DATA_TABLE_SIZE    (10)
#define PORT_TABLE_SIZE    (10)

class CSegmentDriver {
  public:
	typedef enum {
		E_DIG_NUM_0 = 0,
		E_DIG_NUM_1,
		E_DIG_NUM_2,

		E_DIG_NUM_MAX
	} E_DIG_NUM;


	static VOID vInitialize();
	static VOID vUpdateSegment(E_DIG_NUM eDigNum);
	static VOID vSetSegmentData(E_DIG_NUM eDigNum,UI_8 ucData);
	
  private:
	static const UI_8 m_ucDataTable[DATA_TABLE_SIZE];
	static UI_8 m_ucData[E_DIG_NUM_MAX];
	static const INT m_iPortTable[PORT_TABLE_SIZE];
	
	static VOID vChangeData(E_DIG_NUM eDigNum);
};

#endif // _SEGMENT_DRIVER_H_
