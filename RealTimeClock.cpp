#include "RealTimeClock.h"

char currentTime[8];
char currentDate[10];
void(*rtcFunction)(void);
void RTCisr (void) __irq ;


/**
* Default constructor<br>
* Real time clock set to:<br><br>
* -Year = 0 <br>
* -Month = 0<br>
* -Day = 0	<br>
* -Hour = 0  <br>
* -Minute = 0<br>
* -Sec = 0	<br>
* and its clock is on stop state.
*/
RealTimeClock::RealTimeClock()
{	
  /*--- Initialize registers ---*/    
  RTC_PREINT = PREINT_RTC;
  RTC_PREFRAC = PREFRAC_RTC;

  RTC_SEC = 0;
  RTC_MIN = 0;
  RTC_HOUR = 0;
  RTC_DOM = 0;
  RTC_DOW = 0;
  RTC_DOY = 0;
  RTC_MONTH = 0;
  RTC_YEAR = 0;  
  RealTimeClock::stop();
}
/**
* Second constructor<br>
* Real time clock set to:<br>
* -Year = 0 <br>
* -Month = 0<br>
* -Day = 0	<br>
* -Hour = 0  <br>
* -Minute = 0<br>
* -Sec = 0	<br>
* @param: bool autoStart <br>
* - True : Real Time clock start by default<br>
* -	False: Real Time Clock stop by default <br>	 <br>

*/
RealTimeClock::RealTimeClock(bool autoStart)
{
  RTC_PREINT = PREINT_RTC;
  RTC_PREFRAC = PREFRAC_RTC;

  RTC_SEC = 0;
  RTC_MIN = 0;
  RTC_HOUR = 0;
  RTC_DOM = 0;
  RTC_DOW = 0;
  RTC_DOY = 0;
  RTC_MONTH = 0;
  RTC_YEAR = 0;  
  if(autoStart)
  {  
  	RealTimeClock::start();
  }
  else if(!autoStart)
  {
  	RealTimeClock::stop();
  }
}

/**
* Fifth constructor<br>
* Real Time Clock set its value to the respective values of this constructor:<br><br>
* @param: int  year:   set the year of real time clock<br>
* @param: int  month:  set the month of real time clock<br>
* @param: int  day:    set the day of real time clock<br>
* @param: int  hour:   set the hour of real time clock<br>
* @param: int  minute: set the minute of real time clock<br>
* @param: int  second: set the second of real time clock<br>
* @param: bool autoStart: <br>
* - True : Real Time clock start by default<br>
* -	False: Real Time Clock stop by default
*/

RealTimeClock::RealTimeClock(int year,int month,int day,int hour,int minute,int second,bool autoStart)
{	
  /*--- Initialize registers ---*/    
  RTC_PREINT = PREINT_RTC;
  RTC_PREFRAC = PREFRAC_RTC;

  RTC_SEC = second;
  RTC_MIN = minute;
  RTC_HOUR = hour;
  RTC_DOM = 0;
  RTC_DOW = 0;
  RTC_DOY = day;
  RTC_MONTH = month;
  RTC_YEAR = year;
  if(autoStart)
  {  
  	RealTimeClock::start();
  }
  else if(!autoStart)
  {
  	RealTimeClock::stop();
  }
}

/**
* Return Time from real time clock, it is output is an pointer to the array of charachter:<br><br>
* @param: char delimiter:  display delimiter between houre and minutes and second <br> <br>
* <br><p><B>Example:</B></p><BR>
* In this example, the time value is going to write on SerialPort and LCD at same time:<br>
* LCD myLCD;<br>
* SerialPort SP;<br>
* RealTimeClock myRTC(2011,6,15,12,33,23,true);<br>
* SP.open();<br>
* SP.write(myRTC.getTime(':'),true);<br>
* myLCD(myRTC.getTime(':'),0,0);<br>
* 
*/
char* RealTimeClock::getTime(char delimiter)
{


	if(RealTimeClock::getHour()<10)
	{
		currentTime[0]='0';
		currentTime[1]=RealTimeClock::convertIntegerToChar(RealTimeClock::getHour());
	}
	else if(RealTimeClock::getHour()>=10 && RealTimeClock::getHour()<20)
	{
		currentTime[0]='1';
		currentTime[1]=RealTimeClock::convertIntegerToChar(RealTimeClock::getHour()-10);
	}
	else if(RealTimeClock::getHour()>=20 && RealTimeClock::getHour()<24)
	{
		currentTime[0]='2';
		currentTime[1]=RealTimeClock::convertIntegerToChar(RealTimeClock::getHour()-20);
	}


	currentTime[2]=delimiter;

	if(RealTimeClock::getMinute()<10)
	{
		currentTime[3]='0';
		currentTime[4]=RealTimeClock::convertIntegerToChar(RealTimeClock::getMinute());
	}
	else if(RealTimeClock::getMinute()>=10 && RealTimeClock::getMinute()<20)
	{
		currentTime[3]='1';
		currentTime[4]=RealTimeClock::convertIntegerToChar(RealTimeClock::getMinute()-10);
	}
	else if(RealTimeClock::getMinute()>=20 && RealTimeClock::getMinute()<30)
	{
		currentTime[3]='2';
		currentTime[4]=RealTimeClock::convertIntegerToChar(RealTimeClock::getMinute()-20);
	}
	else if(RealTimeClock::getMinute()>=30 && RealTimeClock::getMinute()<40)
	{
		currentTime[3]='3';
		currentTime[4]=RealTimeClock::convertIntegerToChar(RealTimeClock::getMinute()-30);
	}
	else if(RealTimeClock::getMinute()>=40 && RealTimeClock::getMinute()<50)
	{
		currentTime[3]='4';
		currentTime[4]=RealTimeClock::convertIntegerToChar(RealTimeClock::getMinute()-40);
	}
	else if(RealTimeClock::getMinute()>=50 && RealTimeClock::getMinute()<60)
	{
		currentTime[3]='5';
		currentTime[4]=RealTimeClock::convertIntegerToChar(RealTimeClock::getMinute()-50);
	}


	currentTime[5]=delimiter;
	
	if(RealTimeClock::getSecond()<10)
	{
		currentTime[6]='0';
		currentTime[7]=RealTimeClock::convertIntegerToChar(RealTimeClock::getSecond());
	}
	if(RealTimeClock::getSecond()>=10 && RealTimeClock::getSecond()<20)
	{
		currentTime[6]='1';
		currentTime[7]=RealTimeClock::convertIntegerToChar(RealTimeClock::getSecond()-10);
	}
	if(RealTimeClock::getSecond()>=20 && RealTimeClock::getSecond()<30)
	{
		currentTime[6]='2';
		currentTime[7]=RealTimeClock::convertIntegerToChar(RealTimeClock::getSecond()-20);
	}
	if(RealTimeClock::getSecond()>=30 && RealTimeClock::getSecond()<40)
	{
		currentTime[6]='3';
		currentTime[7]=RealTimeClock::convertIntegerToChar(RealTimeClock::getSecond()-30);
	}
	if(RealTimeClock::getSecond()>=40 && RealTimeClock::getSecond()<50)
	{
		currentTime[6]='4';
		currentTime[7]=RealTimeClock::convertIntegerToChar(RealTimeClock::getSecond()-40);
	}
	if(RealTimeClock::getSecond()>=50 && RealTimeClock::getSecond()<60)
	{
		currentTime[6]='5';
		currentTime[7]=RealTimeClock::convertIntegerToChar(RealTimeClock::getSecond()-50);
	}
	
	return currentTime;
}

/**
* Return Date from real time clock, it is output is an pointer to the array of charachter:<br><br>
* @param: char delimiter:  display delimiter between year and month and day <br> <br>
** <br><p><B>Example:</B></p><BR>
* In this example, the date value is going to write on SerialPort and LCD at same time:<br>
* LCD myLCD;<br>
* SerialPort SP;<br>
* RealTimeClock myRTC(2011,6,15,12,33,23,true);<br>
* SP.open();<br>
* SP.write(myRTC.getDate('/'),true);<br>
* myLCD(myRTC.getTime('/'),0,0);<br>
* 
*/

char* RealTimeClock::getDate(char delimiter)
{
	int digit3,digit2,digit1;
	if(getYear()<3000 && getYear()>=2000 )
	{
		digit3=((getYear()/100)-20)*100;
		digit2=(getYear()-(2000+digit3))/10;
		digit1=	(getYear()-(2000+digit3))-(digit2*10);
		currentDate[0]='2';
	    currentDate[1]=RealTimeClock::convertIntegerToChar((getYear()/100)-20);
	    currentDate[2]=RealTimeClock::convertIntegerToChar(digit2);
		currentDate[3]=RealTimeClock::convertIntegerToChar(digit1);
	}
	else if(getYear()<2000)
	{
	    digit3=((getYear()/100)-10);
	    digit2= ((getYear())-(1000+(digit3*100)))/10;
		digit1=	((getYear())-(1000+(digit3*100)))-(digit2*10);
		currentDate[0]='1';
		currentDate[1]=RealTimeClock::convertIntegerToChar(digit3);
	    currentDate[2]=RealTimeClock::convertIntegerToChar(digit2);
		currentDate[3]=RealTimeClock::convertIntegerToChar(digit1);
	}

	currentDate[4]=delimiter;

   	if(RealTimeClock::getMonth()<10)
	{
		currentDate[5]='0';
		currentDate[6]=RealTimeClock::convertIntegerToChar(RealTimeClock::getMonth());
	}
	else if(RealTimeClock::getMonth()>=10 && RealTimeClock::getMonth()<13)
	{
		currentDate[5]='1';
		currentDate[6]=RealTimeClock::convertIntegerToChar(RealTimeClock::getMonth()-10);
	}

	currentDate[7]=delimiter;
	
   	if(RealTimeClock::getDay()<10)
	{
		currentDate[8]='0';
		currentDate[9]=RealTimeClock::convertIntegerToChar(RealTimeClock::getDay());
	}
	else if(RealTimeClock::getDay()>=10 && RealTimeClock::getDay()<20)
	{
		currentDate[8]='1';
		currentDate[9]=RealTimeClock::convertIntegerToChar(RealTimeClock::getDay()-10);
	}
	else if(RealTimeClock::getDay()>=20 && RealTimeClock::getDay()<30)
	{
		currentDate[8]='2';
		currentDate[9]=RealTimeClock::convertIntegerToChar(RealTimeClock::getDay()-20);
	}
	else if(RealTimeClock::getDay()>=30 && RealTimeClock::getDay()<32)
	{
		currentDate[8]='3';
		currentDate[9]=RealTimeClock::convertIntegerToChar(RealTimeClock::getDay()-30);
	}

	return currentDate;
}



/**
* Set time to Real time clock:<br><br>
* @param: int hour: set hour <br>
* @param: int minute: set minute <br>
* @param: int second: set second <br>

* <br><p><B>Example:</B></p><BR>
* LCD myLCD;
* RealTimeClock myRTC(true,do1);<br>
* myRTC.setTime(22,35,10);		<br>
* myLCD(myRTC.getTime(':'),0,0);<br>
* 
*/
void RealTimeClock::setTime(int hour,int minute,int second)
{
  RTC_SEC = second;
  RTC_MIN = minute;
  RTC_HOUR = hour;
}
/**
* Set date to Real time clock:<br><br>
* @param: int year: set year support till 2099<br>
* @param: int month: set month from 1 to 12 <br>
* @param: int day: set day from 0 to 31 <br>

* <br><p><B>Example:</B></p><BR>
* LCD myLCD;
* RealTimeClock myRTC(true,do1);<br>
* myRTC.setDate(2011,6,18);		<br>
* myLCD(myRTC.getDate('-'),0,0);<br>
* 
*/
void RealTimeClock::setDate(int year,int month,int day)
{
  RTC_DOY = day;
  RTC_MONTH = month;
  RTC_YEAR = year;
}
/**
* start the real time clock:<br><br>
* <br><p><B>Example:</B></p><BR>
* RealTimeClock myRTC<br>
* myRTC.start();<br> 
*/
void RealTimeClock::start(void)
{
  RTC_CCR |= CCR_CLKEN;
  RTC_ILR = ILR_RTCCIF;
  rtcStatus=true;
}
/**
* stop the real time clock:<br><br>
* <br><p><B>Example:</B></p><BR>
* RealTimeClock myRTC<br>
* myRTC.stop();<br> 
*/
void RealTimeClock::stop(void)
{
    RTC_CCR &= ~CCR_CLKEN;
	rtcStatus=false;
}
/**
* re-start the real time clock:<br><br>
* <br><p><B>Example:</B></p><BR>
* RealTimeClock myRTC<br>
* myRTC.reset();<br> 
*/
void RealTimeClock::reset(void)
{
     RTC_CCR |= CCR_CTCRST;
}
/**
* Return the value of year from real time clock<br><br>
* @return: int Year: value of year <br>
* <br><p><B>Example:</B></p><BR>
* RealTimeClock myRTC<br>
* myRTC.getYear();<br> 
*/
int RealTimeClock::getYear()
{
	return RTC_YEAR;
}
/**
* Return the value of month from real time clock<br><br>
* @return: int Year: value of month <br>
* <br><p><B>Example:</B></p><BR>
* RealTimeClock myRTC<br>
* myRTC.getMonth();<br> 
*/
int RealTimeClock::getMonth()
{
	return RTC_MONTH;
}
/**
* Return the value of day from real time clock<br><br>
* @return: int Year: value of day <br>
* <br><p><B>Example:</B></p><BR>
* RealTimeClock myRTC<br>
* myRTC.getDay();<br> 
*/
int RealTimeClock::getDay()
{
	return RTC_DOY;
}
/**
* Return the value of minute from real time clock<br><br>
* @return: int Year: value of minute <br>
* <br><p><B>Example:</B></p><BR>
* RealTimeClock myRTC<br>
* myRTC.getMinute();<br> 
*/
int RealTimeClock::getMinute()
{
	return RTC_MIN;
}
/**
* Return the value of second from real time clock<br><br>
* @return: int Year: value of second <br>
* <br><p><B>Example:</B></p><BR>
* RealTimeClock myRTC<br>
* myRTC.getSecond();<br> 
*/
int RealTimeClock::getSecond()
{
	return RTC_SEC;
}
/**
* Return the value of hour from real time clock<br><br>
* @return: int Year: value of hour<br>
* <br><p><B>Example:</B></p><BR>
* RealTimeClock myRTC<br>
* myRTC.getHour();<br> 
*/
int RealTimeClock::getHour()
{
	return RTC_HOUR;
}
/*--------------------------------Private: do not touch below this line--------------------*/

char RealTimeClock::convertIntegerToChar(int value)
{
	char convertedInteger='0';
	if(value==0){convertedInteger='0';}
    else if(value==1){convertedInteger='1';}
    else if(value==2){convertedInteger='2';}
    else if(value==3){convertedInteger='3';}
    else if(value==4){convertedInteger='4';}
    else if(value==5){convertedInteger='5';}
    else if(value==6){convertedInteger='6';}
    else if(value==7){convertedInteger='7';}
    else if(value==8){convertedInteger='8';}
    else if(value==9){convertedInteger='9';}
	return convertedInteger	;
		
}
