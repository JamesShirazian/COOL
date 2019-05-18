#ifndef Interrupt_h
#define Interrupt_h


#define PREINT_RTC	0x000001C8  /* Prescaler value, integer portion, PCLK = 15Mhz */
#define PREFRAC_RTC	0x000061C0  /* Prescaler value, fraction portion,  PCLK = 15Mhz */


#include <LPC23xx.H>    
#include "PortPin.h"
#include "RealTimeClock.h"
#include "ADC.h"
#include "LCD.h"
/** @defgroup group10 Interrupt
 *  Interrupt 
 *  @{
 */
/*! \brief class Interrupt: is a class in charge of Interrupt in ARM 7 processor, this class provide interrupt for EXTINT0, EXTINT1, EXTINT2, EXTINT3 , Real Time Clock.
  \ingroup common
  \sa FastInterrupt
 */     
class Interrupt
{
public:
	Interrupt(void);
	Interrupt(PortPin pin,int priority,void(*function)(void));
	Interrupt(RealTimeClock rtc,void(*function)(void));
	Interrupt(ADC adcClass,int interruptPriority,void(*function)(void));
	void kill(void);
	void setInterruptFunctionTo(void(*newFunction)(void));
	void setInterruptPriorityTo(int newPriority);
	int getInterruptPriority(void);

private:
   int interruptPriority,interruptPin;
   int interruptType;
};
#endif

