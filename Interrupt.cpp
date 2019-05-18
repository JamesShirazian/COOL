#include "Interrupt.h"
void(*interruptFunction)(void);
void(*adcFunction)(void);

void RTC0isr (void) __irq ;
void interruptHandler (void) __irq ;
void adcHandler (void) __irq ;
void (*rtcInterruptFunction)(void);

int pinNumber=0;
LCD fg;
/**
* Default constructor: activate EXTINT0 by default and set its priority to 0 <br>
* <br><p><B>Example:</B></p><br>
*  
*  Interrupt myInterrupt;			<br>
*/
Interrupt::Interrupt()
{
		interruptType=1;
		PINSEL4 		|= (1<<20);	    //Enable the EXTINT0 interrupt
	    EXTMODE         |= (1<<0);      //Enable edge sensitive interrupt
	    EXTPOLAR        &= ~(1<<0);     //Falling Edge sensitive
	    VICIntSelect 	&= ~(1<<14);    //Enable a EXTINT0 Vic Channel as Vectored IRQ (clear bit)
	    VICVectAddr14  = (unsigned long)interruptHandler;   // Set Interrupt Vector
	    VICVectPriority14  = 0;                         // Set priority level to 9
	    VICIntEnable	|= (1<<14);	                    //Enable the interrupt channel in the VIC
}

 /**
* Second constructor: <br>
* @param PortPin  pin: this pin have to set as an "INPUT" and it must be one of below pins, since ARM7 handel interrupt for below pins:	<br>
*		- Port2 -> Pin10
*		- Port2 -> Pin11
*		- Port2 -> Pin12
*		- Port2 -> Pin13
* @param int priority: this value represent the priority of interrupt for that specific pin from 0 to 31.<br>
* @param void(*function)(void): function which has to execute once the interrupt has occure. <br>
* <br><p><B>Example:</B></p><br>
*  PortPin myPin(2,10,"INPUT");<br>
*  Interrupt myInterrupt(myPin,12,do1);			<br>
*/

Interrupt::Interrupt(PortPin pinClass,int priority,void(*function)(void))
{
	interruptPin=pinClass.getPinNumber();
	pinNumber=pinClass.getPinNumber();
	interruptPriority=priority;
	interruptType=1;
	if(interruptPin==10)
	{
		PINSEL4 		|= (1<<20);	    					//Enable the EXTINT0 interrupt
	    VICIntSelect 	&= ~(1<<14);    					//Enable a EXTINT0 Vic Channel as Vectored IRQ (clear bit)
	    VICVectAddr14  = (unsigned long)interruptHandler;   // Set Interrupt Vector
	    VICVectPriority14  = interruptPriority;             // Set priority level
	    VICIntEnable	|= (1<<14);	                        //Enable the interrupt channel in the VIC
	}
	else if(interruptPin==11)
	{
		PINSEL4 		|= (1<<22);	    					//Enable the EXTINT1 interrupt
	    VICIntSelect 	&= ~(1<<15);    					//Enable a EXTINT1 Vic Channel as Vectored IRQ (clear bit)
	    VICVectAddr15  = (unsigned long)interruptHandler;   // Set Interrupt Vector
	    VICVectPriority15  = interruptPriority;             // Set priority level 
	    VICIntEnable	|= (1<<15);	                        //Enable the interrupt channel in the VIC
	}
	else if(interruptPin==12)
	{
		PINSEL4 		|= (1<<24);	    					//Enable the EXTINT2 interrupt
	    VICIntSelect 	&= ~(1<<16);    					//Enable a EXTINT2 Vic Channel as Vectored IRQ (clear bit)
	    VICVectAddr16  = (unsigned long)interruptHandler;   // Set Interrupt Vector
	    VICVectPriority16  = interruptPriority;             // Set priority level
	    VICIntEnable	|= (1<<16);	                        //Enable the interrupt channel in the VIC
	}
	else if(interruptPin==13)
	{
		PINSEL4 		|= (1<<26);	                        //Enable the EXTINT3 interrupt
	    VICIntSelect 	&= ~(1<<17);    					//Enable a EXTINT3 Vic Channel as Vectored IRQ (clear bit)
	    VICVectAddr17  = (unsigned long)interruptHandler;   // Set Interrupt Vector
	    VICVectPriority17  = interruptPriority;             // Set priority level 
	    VICIntEnable	|= (1<<17);	                        //Enable the interrupt channel in the VIC
	}
	EXTMODE         |= (1<<0);      //Enable edge sensitive interrupt
	EXTPOLAR        &= ~(1<<0);     //Falling Edge sensitive
	interruptFunction=function;
}
void interruptHandler (void) __irq  
{
	interruptFunction();
    EXTINT  = 0x00000001;	    //Clear the peripheral interrupt flag
    if(pinNumber==10)
	{
    	VICVectAddr   &= (0<<14); ;       
	}
	if(pinNumber==11)
	{
    	VICVectAddr   &= (0<<15); ;       
	}
	if(pinNumber==12)
	{
    	VICVectAddr   &= (0<<16); ;       
	}
	if(pinNumber==13)
	{
    	VICVectAddr   &= (0<<17); ;       
	}
	   
}
 /**
* Third constructor: <br>
* @param RealTimeClock rtc: RealTimeClock object interrupt apply to.
* @param void(*function)(void): function which has to execute once the interrupt has occure. <br>
* <br><p><B>Example:</B></p><br>
*
*  RealTimeClock myRTC(2011,1,12,23,12,34,true);<br>
*  Interrupt myInterrupt(myRTC,do1);			<br>
*/

Interrupt::Interrupt(RealTimeClock rtcClass,void(*function)(void))
{

	interruptType=2;
	RTC_CCR=0x00000001;
	rtcInterruptFunction=function;
   	VICVectAddr13 = (unsigned)RTC0isr;
	VICVectCntl13 |= 1<<13;
	VICIntEnable  |= 1<<13;
	RTC_CIIR = 0x00000001;	// Enable seconds counter interrupt 

}

void RTC0isr (void) __irq 
{
	if(RTC_ILR & 0x00000001)
	{
		rtcInterruptFunction();
		RTC_ILR = 0x00000001;
		
   	}
		 EXTINT  = 0x00000001;	    //Clear the peripheral interrupt flag
		VICVectAddr  &= (0<<13)  ;			//Dummy write to signal end of interrupt
		


}



Interrupt::Interrupt(ADC adcClass,int interruptPriority,void(*function)(void))
{
    VICIntSelect 	&= ~(1<<18);    					//Enable a EXTINT3 Vic Channel as Vectored IRQ (clear bit)
    VICVectAddr18  = (unsigned long)adcHandler;   // Set Interrupt Vector
    VICVectPriority18  = interruptPriority;             // Set priority level 
	VICVectCntl18 |= 1<<18;
	VICIntEnable  |= 1<<18;
	AD0INTEN=0x101;
	//---------------
	PINSEL1 |= 0x00004000;
	//Set the ADC Vector
    AD0CR = ( 0x01 << 0 ) | 	/* SEL=1,select channel 0~7 on ADC0 */
		( ( Fpclk / ADC_CLK - 1 ) << 8 ) |  /* CLKDIV = Fpclk / 1000000 - 1 */ 
		( 0 << 16 ) | 		/* BURST = 0, no BURST, software controlled */
		( 0 << 17 ) |  		/* CLKS = 0, 11 clocks/10 bits */
		( 1 << 21 ) |  		/* PDN = 1, normal operation */
		( 0 << 22 ) |  		/* TEST1:0 = 00 */
		( 1 << 24 ) |  		/* START = 0 A/D conversion stops */
		( 0 << 27 );		/* EDGE = 0 (CAP/MAT singal falling,trigger A/D conversion) */
	//-------------------
	adcFunction=function;
}

void adcHandler (void) __irq  
{
	adcFunction();
	//AD0INTEN=0x101;
	AD0INTEN=0x00000001;
    VICVectAddr  &= (0<<18);;            // Acknowledge Interrupt  


}
/**
* Set new function to interrupt  case<br>
* @param void(*newFunction)(void): function which execute once interrupt occure for:<br>
*					- EXTINT0(Port 2 -> Pin ->10)
*					- EXTINT0(Port 2 -> Pin ->11)
*					- EXTINT0(Port 2 -> Pin ->12)
*					- EXTINT0(Port 2 -> Pin ->13)
*					- RealTimeClock
*
* <br><p><B>Example 1:</B></p><br><br>
*
* PortPin pin10(2,10,"INPUT");	   <br>
* Interrupt myInt(pin10,4,do1);	<br>
* myRTC.setInterruptFunctionTo(do2);<br> 
*
* <br><p><B>Example 2:</B></p><br><br>
*
* RealTimeClock myRTC(true,do1)<br>
* myRTC.setInterruptFunctionTo(do1);<br> 
*/
void Interrupt::setInterruptFunctionTo(void(*newFunction)(void))
{
  if(interruptType==1)
  {
     interruptFunction=newFunction;
  }
  else if(interruptType==2)
  {
   	  rtcInterruptFunction=newFunction;
  }
  

}
 /**
* Set new priority to intrrupt which has already defined..<br>
* @param int newPriority: this value represent the priority of interrupt for that specific pin from 0 to 31.<br>
* <br><p><B>Example:</B></p><br>
*  PortPin myPin(2,10,"INPUT");<br>
*  Interrupt myInterrupt(myPin,12,do1);			<br>
*  myInterrupt.setFunctionToInterrupt(do2);<br>
*  myInterrupt.setInterruptPriorityTo(16);<br>
*/
void Interrupt::setInterruptPriorityTo(int newPriority)
{
	interruptPriority=newPriority;
	if(interruptPin==10)
	{
	  VICVectPriority14  = interruptPriority;  
	}
	else if(interruptPin==11)
	{
	  VICVectPriority15  = interruptPriority;  
	}
	else if(interruptPin==12)
	{
	  VICVectPriority16  = interruptPriority;  
	}
	else if(interruptPin==13)
	{
	  VICVectPriority17  = interruptPriority;
	}
}
 /**
* Set new priority to intrrupt which has already defined..<br>
* @return  int Priority: return the priority of interrupt.<br>
* <br><p><B>Example:</B></p><br>
*  PortPin myPin(2,10,"INPUT");<br>
*  Interrupt myInterrupt(myPin,12,do1);			<br>
*  myInterrupt.setFunctionToInterrupt(do2);<br>
* if(myInterrupt.getInterruptPriority()==12)  <br>
* {	   <br>
*  myInterrupt.setInterruptPriorityTo(16);<br>
* }						   <br>
*/
int Interrupt::getInterruptPriority(void)
{
	return interruptPriority;
}	



