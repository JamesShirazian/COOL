#include "Buzzer.h"
void  setHigh(void);
void  setLow(void);
void dOn(void);
void dOff(void);
DAC buzzerDAC;


bool enable;
int buzzerVolume=0;
AttachedTimer *ATsetHigh;
AttachedTimer *ATsetLow;
AttachedTimer *buzzWithDuration;
Buzzer::Buzzer(float freq,int volume)
{

	ATsetHigh = new AttachedTimer(1/freq,0,true,setHigh);
    ATsetLow = new  AttachedTimer(1/freq,0,false,setLow);
	buzzerVolume=volume;
	enable=false;
}									  
void Buzzer::setVolumeTo(int newValumeValue)
{
	buzzerVolume=newValumeValue;
}
void Buzzer::buzz(float duration)
{
	enable=true;
	buzzWithDuration=new AttachedTimer(duration,1,true,dOff);
}

void Buzzer::on(void)
{
  enable=true;
}
void Buzzer::off(void)
{
  enable=false;
}

/*-----------------private: do not touch below this line-------------------------------*/

void  setHigh(void)
{
   if(enable)
   {
	  buzzerDAC.setDACValue(10.23*buzzerVolume);
	  ATsetHigh->stop();
	  ATsetLow->start();
    }
}

void  setLow(void)
{
	if(enable)
	{
	  buzzerDAC.setDACValue(0);
	  ATsetHigh->start();
	  ATsetLow->stop();
	}

}
void dOff(void)
{
  enable=false;
  buzzWithDuration->stop();
  delete buzzWithDuration;
}
