#ifndef StopWatch_h
#define StopWatch_h

#include <LPC23xx.H>    


void StopWatchT2isr (void) __irq ;


class StopWatch
{
public:
	StopWatch();
	void start(void);
	void stop(void);
	void reset(void);
	float getDuration(void);

private:
	int timerID;
	void turnOnTimer2(void);
};


#endif

