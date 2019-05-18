#include "Interrupt.h"
#include "LCD.h"
#include "RealTimeClock.h"
#include "AttachedTimer.h"
#include "ADC.h"
#include "Timer.h"
#include "StopWatch.h"

#include <RTL.h>

void do1(void);
void do2(void);
void do3(void);
LCD LCD;
ADC myADC(0);
int a;
float b=0;


int main(void)
{
	LCD.clear();
	AttachedTimer AT0(1,0,true,do2);
	Interrupt myIrr0(myADC,1,do1);
	myADC.startADCConversion();
  	

	StopWatch SW;
	SW.start();
	LCD.write("A",0,1);
	LCD.write("A",0,1);
	LCD.write("A",0,1);
	LCD.write("A",0,1);
	LCD.write("A",0,1);
	LCD.write("A",0,1);
	LCD.write("A",0,1);
	LCD.write("A",0,1);
	LCD.write("A",0,1);
	LCD.write("A",0,1);
	SW.stop();
	LCD.write(SW.getDuration(),4,1,1);


	return 0;
}

void do1(void)
{
	b+=0.1;
	LCD.write(b,0,10,0);
	LCD.write("ADC value:",0,0);
	//LCD.write(myADC.getADCValue(),4,10,0);
}

void do2(void)
{
	a++;
	LCD.write(a,4,0,1);
}
