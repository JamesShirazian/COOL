#include "ADC.h"


/**
* <b>ADC() constructor.</b>
* @param  uint8_t newChannelNumber: ADC channel number from 0 to 7
*/
ADC::ADC()
{
   	/* Enable CLOCK into ADC controller */
	PCONP |= (1 << 12);
	PINSEL1 |= 0x00004000;
	//Set the ADC Vector
    AD0CR = ( 0x01 << 0 ) | 				/* SEL=1,select channel 0~7 on ADC0 */
		( ( Fpclk / ADC_CLK - 1 ) << 8 ) |  /* CLKDIV = Fpclk / 1000000 - 1 */ 
		( 0 << 16 ) | 						/* BURST = 0, no BURST, software controlled */
		( 0 << 17 ) |  						/* CLKS = 0, 11 clocks/10 bits */
		( 1 << 21 ) |  						/* PDN = 1, normal operation */
		( 0 << 22 ) |  						/* TEST1:0 = 00 */
		( 0 << 24 ) |  						/* START = 1 ,Stop = 0*/
		( 0 << 27 );						/* EDGE = 0 (CAP/MAT singal falling,trigger A/D conversion) */ 

}
/**
* <b>ADC() constructor.</b>
* @param  uint8_t newChannelNumber: ADC channel number from 0 to 7
*/
ADC::ADC(uint8_t newChannelNumber):channelNumber(newChannelNumber)
{
   	/* Enable CLOCK into ADC controller */
	PCONP |= (1 << 12);
	
	if(channelNumber==0){PINSEL1 |= 0x00004000;}
	else if(channelNumber==1){PINSEL1 |= 0x00010000;}
	else if(channelNumber==2){PINSEL1 |= 0x00080000;}
	else if(channelNumber==3){PINSEL1 |= 0x00100000;}
	else if(channelNumber==4){PINSEL3 |= 0x30000000;}
	else if(channelNumber==5){PINSEL3 |= 0xC0000000;}
	else if(channelNumber==6){PINSEL0 |= 0x03000000;}
	else if(channelNumber==7){PINSEL0 |= 0xC0000000;}

	//Set the ADC Vector
    AD0CR = ( 0x01 << 0 ) | 				/* SEL=1,select channel 0~7 on ADC0 */
		( ( Fpclk / ADC_CLK - 1 ) << 8 ) |  /* CLKDIV = Fpclk / 1000000 - 1 */ 
		( 0 << 16 ) | 						/* BURST = 0, no BURST, software controlled */
		( 0 << 17 ) |  						/* CLKS = 0, 11 clocks/10 bits */
		( 1 << 21 ) |  						/* PDN = 1, normal operation */
		( 0 << 22 ) |  						/* TEST1:0 = 00 */
		( 0 << 24 ) |  						/* START = 1 ,Stop = 0*/
		( 0 << 27 );						/* EDGE = 0 (CAP/MAT singal falling,trigger A/D conversion) */ 
}
/**
* read the value of respective ADC.<br>
* @return int ADCValue: return the ADC value of the respective ADC channel.<br>
* <br><p><B>Example:</B></p><BR> 
*  ADC myADC(0);	 <br>  		
*  int ADCValueOfChannel0=myADC.getADCValue();	<br>	
*/
int ADC::getADCValue(void)
{

    int regVal, ADC_Data;
    /* channel number is 0 through 7 */
    if ( channelNumber >= ADC_NUM )
    {
	    channelNumber = 0;		/* reset channel number to 0 */
    }
    AD0CR &= 0xFFFFFF00;
    AD0CR |= (1 << 24) | (1 << channelNumber);		/* start A/D convert */

    while ( 1 )			/* wait until end of A/D convert */
    {
	    regVal = *(volatile unsigned long *)(AD0_BASE_ADDR + ADC_OFFSET + ADC_INDEX * channelNumber);
		/* read result of A/D conversion */
	    if ( regVal & ADC_DONE )
	    {
		    break;
	    }
		
    }			
    AD0CR &= 0xF8FFFFFF;		/* stop ADC now */    
    if ( regVal & ADC_OVERRUN )	/* save data when it's not overrun, otherwise, return zero */
    {
	    return ( 0 );
    }
    ADC_Data = ( regVal >> 6 ) & 0x3FF;
    return ( ADC_Data );	/* return A/D conversion value */

}

/**
* stop ADC conversion.<br>
* <br><p><B>Example:</B></p><br>
*  
*  ADC myADC(0);	 <br>  		
*  int ADCValueOfChannel0=myADC.getADCValue();	<br>	
*   myADC.stopADCConversion();
*/
void ADC::stopADCConversion()
{
 	AD0CR = ( 0 << 24 );
	PCONP &= (0 << 12);
}
/**
* start ADC conversion, once ADC object created in the memory it start convertion automaticaly, this method use when conversion stoped by "stopADCConversion" 
* other wise there is no need of useing just to save power it is efficent to stop the conversion when it is not neccessery.<br>
* <br><p><B>Example:</B></p><br>
*  
*  ADC myADC(0);	 <br>  
*  myADC.startADCConversion();<br>		
*  int ADCValueOfChannel0=myADC.getADCValue();	<br>	
*  myADC.stopADCConversion();
*/
void ADC::startADCConversion()
{
    /* Enable CLOCK into ADC controller */
	PCONP |= (1 << 12);

	if(channelNumber==0){PINSEL1 |= 0x00004000;}
	else if(channelNumber==1){PINSEL1 |= 0x00010000;}
	else if(channelNumber==2){PINSEL1 |= 0x00080000;}
	else if(channelNumber==3){PINSEL1 |= 0x00100000;}
	else if(channelNumber==4){PINSEL3 |= 0x30000000;}
	else if(channelNumber==5){PINSEL3 |= 0xC0000000;}
	else if(channelNumber==6){PINSEL0 |= 0x03000000;}
	else if(channelNumber==7){PINSEL0 |= 0xC0000000;}

	//Set the ADC Vector
    AD0CR = ( 0x01 << 0 ) | 	/* SEL=1,select channel 0~7 on ADC0 */
		( ( Fpclk / ADC_CLK - 1 ) << 8 ) |  /* CLKDIV = Fpclk / 1000000 - 1 */ 
		( 0 << 16 ) | 		/* BURST = 0, no BURST, software controlled */
		( 0 << 17 ) |  		/* CLKS = 0, 11 clocks/10 bits */
		( 1 << 21 ) |  		/* PDN = 1, normal operation */
		( 0 << 22 ) |  		/* TEST1:0 = 00 */
		( 1 << 24 ) |  		/* START = 0 A/D conversion stops */
		( 0 << 27 );		/* EDGE = 0 (CAP/MAT singal falling,trigger A/D conversion) */

}
