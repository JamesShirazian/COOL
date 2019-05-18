#include "StopWatch.h"


static float stopWatchTime[127];
static bool timerIsEnable[127];
static int stopWatchTimerCounter=-1;

StopWatch::StopWatch()
{
   StopWatch::turnOnTimer2();
   stopWatchTimerCounter++;
   timerID=stopWatchTimerCounter;

     /* Initialise Timer 0, match register and start timer */
    T2MR0         = 1199;                     /* 6000000-1 at 12.0 MHz = 0.5s */
    T2MCR         = 3;                           /* Reset T0TC & set interrupt on MR0  */
    T2TC          = 0;                           /* Reset counter */
    T2TCR         = 1;                           /* Timer0 Enable               */
	//Initialise and enable Timer 0 interrupt for vectored IRQ
    VICIntSelect 	&= ~(1<<26);     			   //Set to '0' for IRQ
    VICVectAddr26  = (unsigned long)StopWatchT2isr;   	   // Set Interrupt Vector Address
    VICVectPriority26  = 0;                         // Set priority level to 9
    VICIntEnable	|= (1<<26);	                   //Enable the interrupt channel in the VIC	

}

void StopWatch::start(void)
{
   timerIsEnable[timerID]=true;
}

void StopWatch::stop(void)
{
	timerIsEnable[timerID]=false;
}

float StopWatch::getDuration(void)
{
	return 	stopWatchTime[timerID];
}
void StopWatch::turnOnTimer2(void)
{
   	PCONP|=0x00400000;	 				//activate timer 2
}
void StopWatchT2isr (void) __irq 
{
	int timerC=0;
   	for(timerC=0;timerC<=stopWatchTimerCounter;timerC++)
	{
		if(timerIsEnable[timerC]==true)
		{
		  stopWatchTime[timerC]+=0.0001;
		}
	}
   T2IR 		|= 0x00000001;			//Clear match 0 interrupt
   VICVectAddr &= (0<<26);		//Dummy write to signal end of interrupt

}
