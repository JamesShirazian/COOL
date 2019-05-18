#ifndef Timer_h
#define Timer_h

#include <LPC23xx.H>    


void TimerT3isr (void) __irq ;


class Timer
{
public:
	Timer();
	Timer(float time);
	Timer(float time,bool autoStart);
	void setTimerIntervalTo(float time);
	void start(void);
	void stop(void);
	void reset(void);
	bool isItOver(void);

private:
	int timerID;
	void turnOnTimer3(void);
};


#endif

