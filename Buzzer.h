#ifndef Buzzer_h
#define Buzzer_h
#include "DAC.h"
#include "AttachedTimer.h"
#include "Timer.h"
class Buzzer
{
public:
	Buzzer(float freq,int volume);
	void buzz(float duration);
	void on(void);
	void off(void);
	void setVolumeTo(int newValumeValue);

private:

};


#endif
