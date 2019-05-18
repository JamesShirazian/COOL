#include "FastInterrupt.h"

void(*fastInterruptFunction)(void);

void fastInterruptHandler (void) __irq; 
/**
* Default constructor: activate EXTINT0 by default and set its priority to 0 which can be alter by "setFunctionToInterrupt"<br>
* <B><br>Example:<br><B><br>
*  
*  FastInterrupt myInterrupt;			<br>
*  myInterrupt.setFunctionToInterrupt(do1);	<br>
*/
FastInterrupt::FastInterrupt()
{
	PINSEL4 		|= (1<<20);	    //Enable the EXTINT0 interrupt
    EXTMODE         |= (1<<0);      //Enable edge sensitive interrupt
    EXTPOLAR        &= ~(1<<0);      //Falling Edge sensitive
    VICIntSelect 	|= (1<<14);	    //Enable a EXTINT0 Vic Channel as FIQ
    VICIntEnable	|= (1<<14);	    //Enable the interrupt channel in the VIC
}
/**
* Second constructor: <br>
* @param PortPin  pin: this pin have to set as an "INPUT" and it must be one of below pins:	<br>
*		- Port2 -> Pin10
*		- Port2 -> Pin11
*		- Port2 -> Pin12
*		- Port2 -> Pin13
* @param void(*function)(void): function which has to execute once the fast interrupt has occur. <br>
* <B><br>Example:<br><B><br>
*  PortPin myPin(2,10,"INPUT");<br>
*  FastInterrupt myInterrupt(myPin,do1);			<br>
*/
FastInterrupt::FastInterrupt(PortPin pin,void(*function)(void))
{
	fastInterruptPin=pin.getPinNumber();

	if(fastInterruptPin==10)
	{
		PINSEL4 		|= (1<<20);	    //Enable the EXTINT0 interrupt
	    VICIntSelect 	|= (1<<14);	    //Enable a EXTINT0 Vic Channel as FIQ
	    VICIntEnable	|= (1<<14);	    //Enable the interrupt channel in the VIC
	}
	else if(fastInterruptPin==11)
	{
		PINSEL4 		|= (1<<22);	    //Enable the EXTINT0 interrupt
	    VICIntSelect 	|= (1<<15);	    //Enable a EXTINT0 Vic Channel as FIQ
	    VICIntEnable	|= (1<<15);	    //Enable the interrupt channel in the VIC
	}
	else if(fastInterruptPin==12)
	{
		PINSEL4 		|= (1<<24);	    //Enable the EXTINT0 interrupt
	    VICIntSelect 	|= (1<<16);	    //Enable a EXTINT0 Vic Channel as FIQ
	    VICIntEnable	|= (1<<16);	    //Enable the interrupt channel in the VIC
	}
	else if(fastInterruptPin==13)
	{
		PINSEL4 		|= (1<<26);	    //Enable the EXTINT0 interrupt
	    VICIntSelect 	|= (1<<17);	    //Enable a EXTINT0 Vic Channel as FIQ
	    VICIntEnable	|= (1<<17);	    //Enable the interrupt channel in the VIC
	}
	EXTMODE         |= (1<<0);      //Enable edge sensitive interrupt
	EXTPOLAR        &= ~(1<<0);     //Falling Edge sensitive
	fastInterruptFunction=function;
}
 /**
* Set new function to fast intrrupt which has already define after impelementing this method the defined interrupt execute the new function once fast interrupt has occur.<br>
* @param void(*function)(void) : function which has to execute once the interrupt has occure.
* <B><br>Example:<br><B><br>
*  PortPin myPin(2,10,"INPUT");<br>
*  FastInterrupt myInterrupt(myPin,do1);			<br>
*  myInterrupt.setFunctionToInterrupt(do2);<br>
*/
void FastInterrupt::setFunctionToInterrupt(void(*assginedfunction)(void))
{
	fastInterruptFunction=assginedfunction;	
}

void fastInterruptHandler (void) __irq  
{
	fastInterruptFunction();
    EXTINT  = 0x00000001;	    //Clear the peripheral interrupt flag
}
