#ifndef ADC_H
#define ADC_H

#include <LPC23xx.H>                    

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include "AttachedTimer.h"

#define ADC_OFFSET		0x10
#define ADC_INDEX		4

#define ADC_DONE		0x80000000
#define ADC_OVERRUN		0x40000000
#define ADC_ADINT		0x00010000

#define ADC_NUM			8		/* for LPC23xx */
#define ADC_CLK			1000000		/* set to 1Mhz */

#define Fpclk           12000000 /*set to 12MHz */
#define ADC_Clk
/** @defgroup group5 Analoug to Digital Convertor (ADC)
 *  Analoug to Digital Convertor (ADC)
 *  @{
 */
/*! \brief class ADC: is a class in charge of ADC channels(0 to 7) of ARM 7 processor.
  \ingroup common
  \sa DAC
 */  
class ADC
{
public:
	ADC();
	ADC(uint8_t newChannelNumber);
	int getADCValue(void);
	void stopADCConversion(void);
	void startADCConversion(void);
private:
	uint8_t channelNumber;
};

#endif
