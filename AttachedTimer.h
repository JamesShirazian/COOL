#ifndef AttachedTimer_h
#define AttachedTimer_h

#include <LPC23xx.H>    



void TimerT1isr (void) __irq ;

class AttachedTimer
{
public:
	AttachedTimer();
    AttachedTimer(float newInterval,int newNumberOfEventOccurrence,bool autoStart,void(*function)(void));
	void setIntervalTo(float time);
	void setFunctionTo(void(*function)(void));
	void setNumberOfOccuranceTo(int noOfOccurance);
	void start(void);
	void stop(void);


private:
	int timerID;
	
};


#endif

