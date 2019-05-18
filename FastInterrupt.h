#ifndef FastInterrupt_h
#define Interrupt_h

#include <LPC23xx.H>    
#include "PortPin.h"
void fastInterruptHandler (void) __irq ;
/** @defgroup group11 Fast Interrupt
 *  Fast Interrupt 
 *  @{
 */
/*! \brief class FastInterrupt: is a class in charge of FastInterrupt in ARM 7 processor it handels EXTINT0, EXTINT1, EXTINT2, EXTINT3.
  \ingroup common
  \sa Interrupt
 */     
class FastInterrupt
{
public:
	FastInterrupt(void);
	FastInterrupt(PortPin pin,void(*function)(void));
	void setFunctionToInterrupt(void(*assginedfunction)(void));


private:
   int fastInterruptPin;
};
#endif

