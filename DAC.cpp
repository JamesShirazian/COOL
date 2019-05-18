 #include "DAC.h"
 /**
* Default constructor<br>
* <b>DAC() constructor use to activate Digital to Analoug Convertor.</b>
*/

 DAC::DAC(void)
 {
 	PINSEL1 |=  0x00200000;
 }
 /**
* Set DAC value.<br>
* @param  int value: DAC value.	<br>
* <br><p><B>Example:</B></p><br>
*  
*  DAC myDAC();	 <br>  		
*  myDAC.setDACValue(1023);	<br>				   		
*/
 void  DAC::setDACValue(int value)
 { 
     DACR = (value << 6);
 } 
