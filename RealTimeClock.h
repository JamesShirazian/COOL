#ifndef RTC_h
#define RTC_h

#include "LPC23xx.H"                        /* LPC23xx/24xx definitions */
#include "type.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string>
#include "LCD.h"

#define PREINT_RTC	0x000001C8  /* Prescaler value, integer portion, PCLK = 15Mhz */
#define PREFRAC_RTC	0x000061C0  /* Prescaler value, fraction portion,  PCLK = 15Mhz */
#define ILR_RTCCIF	0x01
#define ILR_RTCALF	0x02
#define CCR_CLKEN	0x01
#define CCR_CTCRST	0x02
#define CCR_CLKSRC	0x10
/** @defgroup group9 Real Time Clock 
 *  Real Time Clock 
 *  @{
 */
/*! \brief class RealTimeClock: is a class in charge of Real Time clock which  is connected to ARM 7 processor. 
  \ingroup common
  /sa Interrupt
 */  

class RealTimeClock
{
public:
	RealTimeClock();
	RealTimeClock(bool autoStart);
	RealTimeClock(int year,int month,int day,int hour,int minute,int second,bool autoStart);
	void setTime(int hour,int min,int sec);
	void setDate(int year,int month,int day);
	void start(void);
	void stop(void);
	void reset(void);


	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();
	int getSecond();

	char* getTime(char delimiter);
	char* getDate(char delimiter);

private:
	char convertIntegerToChar(int value);
	bool rtcStatus;
};


#endif
