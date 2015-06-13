#include "SegmentDriver.h"
#include "Board.h"

const UI_8 CSegmentDriver::m_ucDataTable[DATA_TABLE_SIZE] = {
	0xEE,0x22,0xC7,0x67,0x2B,0x6D,0xED,0x2E,0xEF,0x6F
};

const INT CSegmentDriver::m_iPortTable[PORT_TABLE_SIZE] = {
	BIT_0_OUT_PORT,BIT_1_OUT_PORT,BIT_2_OUT_PORT,BIT_3_OUT_PORT,
	BIT_4_OUT_PORT,BIT_5_OUT_PORT,BIT_6_OUT_PORT,BIT_7_OUT_PORT
};

UI_8 CSegmentDriver::m_ucData[CSegmentDriver::E_DIG_NUM_MAX] = {
	0,0,0
};

VOID CSegmentDriver::vInitialize()
{
	for (INT i = 0;i < PORT_TABLE_SIZE;i++) {
		pinMode(m_iPortTable[i],OUTPUT);
	}

	pinMode(DIG_0_OUT_PORT,OUTPUT);
	pinMode(DIG_1_OUT_PORT,OUTPUT);
	pinMode(DIG_2_OUT_PORT,OUTPUT);
}

VOID CSegmentDriver::vUpdateSegment(E_DIG_NUM eDigNum)
{
	switch (eDigNum) {
	case E_DIG_NUM_0:
		digitalWrite(DIG_1_OUT_PORT,LOW);
		digitalWrite(DIG_2_OUT_PORT,LOW);
		digitalWrite(DIG_0_OUT_PORT,HIGH);
		vChangeData(eDigNum);
		break;
	case E_DIG_NUM_1:
		digitalWrite(DIG_0_OUT_PORT,LOW);
		digitalWrite(DIG_2_OUT_PORT,LOW);
		digitalWrite(DIG_1_OUT_PORT,HIGH);
		vChangeData(eDigNum);
		break;
	case E_DIG_NUM_2:
		digitalWrite(DIG_0_OUT_PORT,LOW);
		digitalWrite(DIG_1_OUT_PORT,LOW);
		digitalWrite(DIG_2_OUT_PORT,HIGH);
		vChangeData(eDigNum);
		break;
	default:
		break;
	}
}

VOID CSegmentDriver::vChangeData(E_DIG_NUM eDigNum)
{
	for (INT i = 0;i < PORT_TABLE_SIZE;i++) {
		digitalWrite(m_iPortTable[i],((m_ucDataTable[m_ucData[eDigNum]] >> i) & 0x01));
	}
}

VOID CSegmentDriver::vSetSegmentData(E_DIG_NUM eDigNum,UI_8 ucData)
{
	m_ucData[eDigNum] = ucData;
}
