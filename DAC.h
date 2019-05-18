#ifndef DAC_H
#define DAC_H

#include <LPC23xx.H>                    
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
/** @defgroup group6 Digital to Analoug Convertor (DAC)
 *  Digital to Analoug Convertor (DAC)
 *  @{
 */
/*! \brief class DAC: is a class in charge of DAC of ARM 7 processor.
  \ingroup common
  \sa ADC
 */  
class DAC
{
public:
	DAC(void);
	void setDACValue(int value);
private:

};

#endif
