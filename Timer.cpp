#include "Timer.h"
#include "LCD.h"
LCD gg;
static float timerTime[127];
static int timerCounter=-1;
static bool timerIsOver[127];
static bool isTimerEnable[127];

static float targetTimerTime[127];


Timer::Timer()
{
   Timer::turnOnTimer3();
   timerCounter++;
   timerID=timerCounter;
   isTimerEnable[timerCounter]=true;

     /* Initialise Timer 0, match register and start timer */
    T3MR0         = 1199999;                     /* 6000000-1 at 12.0 MHz = 0.5s */
    T3MCR         = 3;                           /* Reset T0TC & set interrupt on MR0  */
    T3TC          = 0;                           /* Reset counter */
    T3TCR         = 1;                           /* Timer0 Enable               */
	//Initialise and enable Timer 0 interrupt for vectored IRQ
    VICIntSelect 	&= ~(1<<27);     			   //Set to '0' for IRQ
    VICVectAddr27  = (unsigned long)TimerT3isr;   	   // Set Interrupt Vector Address
    VICVectPriority27  = 0;                         // Set priority level to 9
    VICIntEnable	|= (1<<27);	                   //Enable the interrupt channel in the VIC	

}
Timer::Timer(float time)
{
   Timer::turnOnTimer3();
   timerCounter++;
   timerID=timerCounter;
   targetTimerTime[timerCounter]=time;
   timerTime[timerCounter]=time;
   isTimerEnable[timerCounter]=true;

     /* Initialise Timer 0, match register and start timer */
    T3MR0         = 1199999;                     /* 6000000-1 at 12.0 MHz = 0.5s */
    T3MCR         = 3;                           /* Reset T0TC & set interrupt on MR0  */
    T3TC          = 0;                           /* Reset counter */
    T3TCR         = 1;                           /* Timer0 Enable               */
	//Initialise and enable Timer 0 interrupt for vectored IRQ
    VICIntSelect 	&= ~(1<<27);     			   //Set to '0' for IRQ
    VICVectAddr27  = (unsigned long)TimerT3isr;   	   // Set Interrupt Vector Address
    VICVectPriority27  = 0;                         // Set priority level to 9
    VICIntEnable	|= (1<<27);	                   //Enable the interrupt channel in the VIC	

}

Timer::Timer(float time,bool autoStart)
{
   Timer::turnOnTimer3();
   timerCounter++;
   timerID=timerCounter;
   targetTimerTime[timerCounter]=time;
   timerTime[timerCounter]=time;
   isTimerEnable[timerCounter]=autoStart;

     /* Initialise Timer 0, match register and start timer */
    T3MR0         = 1199999;                     /* 6000000-1 at 12.0 MHz = 0.5s */
    T3MCR         = 3;                           /* Reset T0TC & set interrupt on MR0  */
    T3TC          = 0;                           /* Reset counter */
    T3TCR         = 1;                           /* Timer0 Enable               */
	//Initialise and enable Timer 0 interrupt for vectored IRQ
    VICIntSelect 	&= ~(1<<27);     			   //Set to '0' for IRQ
    VICVectAddr27  = (unsigned long)TimerT3isr;   	   // Set Interrupt Vector Address
    VICVectPriority27  = 0;                         // Set priority level to 9
    VICIntEnable	|= (1<<27);	                   //Enable the interrupt channel in the VIC	

}

void Timer::start(void)
{
	isTimerEnable[timerID]=true;
}

void Timer::stop(void)
{
   isTimerEnable[timerID]=false;
}
void Timer::reset(void)
{
   timerTime[timerID]=targetTimerTime[timerID];
}

void Timer::setTimerIntervalTo(float time)
{
	targetTimerTime[timerID]=time;
	timerTime[timerID]=time;

}


bool Timer::isItOver(void)
{
	return timerIsOver[timerID];
}

void Timer::turnOnTimer3(void)
{
   	PCONP|=0x00800000;	 				//activate timer 3
}


void TimerT3isr (void) __irq 
{
	int timerC=0;

   	for(timerC=0;timerC<=timerCounter;timerC++)
	{
	     
		  if(timerTime[timerC]<=0)
		  {
			  timerIsOver[timerC]=true;
			  timerTime[timerC]=targetTimerTime[timerC];
		  }
		  else
		  {
			  if(isTimerEnable[timerC]==true)
			  {
				  timerTime[timerC]-=0.1;
			  }
			  timerIsOver[timerC]=false;

		  }
	}
   T3IR 		|= 0x00000001;			//Clear match 0 interrupt
   VICVectAddr &= (0<<27);			//Dummy write to signal end of interrupt

}
