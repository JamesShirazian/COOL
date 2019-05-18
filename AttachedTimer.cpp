#include "AttachedTimer.h"

static void(*attachedFunction[129])(void);
static float timerInterval[129];
static float timerTargetInterval[129];
static bool activeTimer[129];
static bool timerIsEnable[129];
static int numberOfEventOccurrence[129];
static int timerCounter=-1;


AttachedTimer::AttachedTimer()
{

   timerCounter++;
   timerID=timerCounter;
   activeTimer[timerCounter]=true;
   timerIsEnable[timerCounter]=false;

     /* Initialise Timer 0, match register and start timer */
    T1MR0         = 1199;                     /* 6000000-1 at 12.0 MHz = 0.5s */
    T1MCR         = 3;                           /* Reset T0TC & set interrupt on MR0  */
    T1TC          = 0;                           /* Reset counter */
    T1TCR         = 1;                           /* Timer0 Enable               */
	//Initialise and enable Timer 0 interrupt for vectored IRQ
    VICIntSelect 	&= ~(1<<5);     			   //Set to '0' for IRQ
    VICVectAddr5  = (unsigned long)TimerT1isr;   	   // Set Interrupt Vector Address
    VICVectPriority5  = 0;                         // Set priority level to 9
    VICIntEnable	|= (1<<5);	                   //Enable the interrupt channel in the VIC	

}

AttachedTimer::AttachedTimer(float newInterval,int newNumberOfEventOccurrence,bool autoStart,void(*function)(void))
{

   timerCounter++;
   timerID=timerCounter;
   attachedFunction[timerCounter]=function;
   timerInterval[timerCounter]=newInterval;
   timerTargetInterval[timerCounter]=newInterval;
   activeTimer[timerCounter]=true;
   numberOfEventOccurrence[timerCounter]=newNumberOfEventOccurrence;
   timerIsEnable[timerCounter]=autoStart;

     /* Initialise Timer 0, match register and start timer */
    T1MR0         = 1199;                     /* 6000000-1 at 12.0 MHz = 0.5s */
    T1MCR         = 3;                           /* Reset T0TC & set interrupt on MR0  */
    T1TC          = 0;                           /* Reset counter */
    T1TCR         = 1;                           /* Timer0 Enable               */
	//Initialise and enable Timer 0 interrupt for vectored IRQ
    VICIntSelect 	&= ~(1<<5);     			   //Set to '0' for IRQ
    VICVectAddr5  = (unsigned long)TimerT1isr;   	   // Set Interrupt Vector Address
    VICVectPriority5  = 0;                         // Set priority level to 9
    VICIntEnable	|= (1<<5);	                   //Enable the interrupt channel in the VIC	

}

void AttachedTimer::start(void)
{
   timerIsEnable[timerID]=true;
}

void AttachedTimer::stop(void)
{
	timerIsEnable[timerID]=false;
}

void AttachedTimer::setIntervalTo(float time)
{
	timerInterval[timerID]=time;
    timerTargetInterval[timerID]=time;
}
void AttachedTimer::setFunctionTo(void(*function)(void))
{
	attachedFunction[timerID]=function;
}
void AttachedTimer::setNumberOfOccuranceTo(int noOfOccurance)
{
	numberOfEventOccurrence[timerID]=noOfOccurance;
}
void TimerT1isr (void) __irq 
{
	int timerC=0;
	
   	for(timerC=0;timerC<=timerCounter;timerC++)
	{
		if(timerInterval[timerC]<=0 && activeTimer[timerC]==true)
		{
		  attachedFunction[timerC]();
		  timerInterval[timerC]=timerTargetInterval[timerC];
		  numberOfEventOccurrence[timerC]--;
				if(numberOfEventOccurrence[timerC]==0)
				{
					activeTimer[timerC]=false;	 //disable timer if the number of its occurance reach to 0
				}
		}
		else 	if(timerInterval[timerC]>0 && activeTimer[timerC]==true)
		{
			if(timerIsEnable[timerC]==true)
			{
			  timerInterval[timerC]-=0.0001;		
			}
		}
	}
   T1IR 		|= 0x00000001;			//Clear match 0 interrupt
   VICVectAddr  &= (0<<5) ;			//Dummy write to signal end of interrupt

}
