#include "PortPin.h"

/**
* Default constructor: Initialize a PIN of any five availabel Port.<br>
* @param  uint8_t newPortID: Port number		  <br>
* @param  int newPinID: Pin number				  <br>
* @param  std::string IO: set the IO status of pin	  <br>
*							- INPUT : set the pin as an input
*							- OUTPUT : set the pin as an output
* <br><p><B>Example:</B></p><br>
*  
*  PortPin pin10(2,10,"INPUT");			<br>
*  PortPin pin0(2,0,"OUTPUT");					<br>
*/
PortPin::PortPin(uint8_t newPortID,int newPinID,std::string IO):pinID(newPinID),portID(newPortID)
{
	PortPin::setPinConfiguration(newPortID,newPinID,"OFF",PortPin::StringToUpper(IO));
}
/**
* Second constructor: Initialize a PIN of any five availabel Port.<br>
* @param  uint8_t newPortID: Port number		  <br>
* @param  int newPinID: Pin number				  <br>
* @param  std::string IO: set the IO status of pin	  <br>
*							- INPUT : set the pin as an input
*							- OUTPUT : set the pin as an output
* @param  std::string initState: set the initialize	value of pin  <br>
*							- ON : set pin to '1'
*							- OFF: set pin to '0'
* <br><p><B>Example:</B></p><br>
*  
*  PortPin pin10(2,10,"INPUT");			<br>
*  PortPin pin0(2,0,"OUTPUT","ON");					<br>
*  PortPin pin1(2,1,"OUTPUT","OFF");					<br>
*/
PortPin::PortPin(uint8_t newPortID,int newPinID,std::string IO,std::string initState):pinID(newPinID),portID(newPortID)
{
   	PortPin::setPinConfiguration(newPortID,newPinID,PortPin::StringToUpper(initState),PortPin::StringToUpper(IO));
}	
/**
* Set the pin value to 1.<br>
* <br><p><B>Example:</B></p><br>
*  
*  PortPin pin10(2,10,"INPUT");			<br>
*  PortPin pin0(2,0,"OUTPUT","ON");					<br>
*  PortPin pin1(2,1,"OUTPUT","OFF");					<br>
*  pin1.on(); <br>
*/
void PortPin::on(void)
{
	if(portID==0)
	{
	    if(pinID==0){FIO0MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO0MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO0MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO0MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO0MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO0MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO0MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO0MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO0MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO0MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO0MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO0MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO0MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO0MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO0MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO0MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO0MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO0MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO0MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO0MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO0MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO0MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO0MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO0MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO0MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO0MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO0MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO0MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO0MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO0MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO0MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO0MASK= 0x7FFFFFFF;}
		FIO0PIN  |= 0xFFFFFFFF;
		FIO0MASK= 0x00000000;
	}
	else if(portID==1)
	{
	    if(pinID==0){FIO1MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO1MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO1MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO1MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO1MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO1MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO1MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO1MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO1MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO1MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO1MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO1MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO1MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO1MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO1MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO1MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO1MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO1MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO1MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO1MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO1MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO1MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO1MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO1MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO1MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO1MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO1MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO1MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO1MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO1MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO1MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO1MASK= 0x7FFFFFFF;}
		FIO1PIN  |= 0xFFFFFFFF;
		FIO1MASK= 0x00000000;
	}
	else if(portID==2)
	{
	    if(pinID==0){FIO2MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO2MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO2MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO2MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO2MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO2MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO2MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO2MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO2MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO2MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO2MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO2MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO2MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO2MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO2MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO2MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO2MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO2MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO2MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO2MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO2MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO2MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO2MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO2MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO2MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO2MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO2MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO2MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO2MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO2MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO2MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO2MASK= 0x7FFFFFFF;}
		FIO2PIN  |= 0xFFFFFFFF;
		FIO2MASK= 0x00000000;
	}
	else if(portID==3)
	{
	    if(pinID==0){FIO3MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO3MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO3MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO3MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO3MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO3MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO3MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO3MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO3MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO3MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO3MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO3MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO3MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO3MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO3MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO3MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO3MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO3MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO3MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO3MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO3MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO3MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO3MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO3MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO3MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO3MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO3MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO3MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO3MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO3MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO3MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO3MASK= 0x7FFFFFFF;}
		FIO3PIN  |= 0xFFFFFFFF;
		FIO3MASK= 0x00000000;
	}
	else if(portID==4)
	{
	    if(pinID==0){FIO4MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO4MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO4MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO4MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO4MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO4MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO4MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO4MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO4MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO4MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO4MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO4MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO4MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO4MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO4MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO4MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO4MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO4MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO4MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO4MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO4MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO4MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO4MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO4MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO4MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO4MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO4MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO4MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO4MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO4MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO4MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO4MASK= 0x7FFFFFFF;}
		FIO4PIN  |= 0xFFFFFFFF;
		FIO4MASK= 0x00000000;
	}

}
/**
* Set the pin value to 0.<br>
* <br><p><B>Example:</B></p><br>
*  
*  PortPin pin10(2,10,"INPUT");			<br>
*  PortPin pin0(2,0,"OUTPUT","ON");					<br>
*  PortPin pin1(2,1,"OUTPUT","OFF");					<br>
*  pino.off(); <br>
*/
void PortPin::off(void)
{
	  if(portID==0)
	  {
	    if(pinID==0){FIO0MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO0MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO0MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO0MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO0MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO0MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO0MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO0MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO0MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO0MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO0MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO0MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO0MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO0MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO0MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO0MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO0MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO0MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO0MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO0MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO0MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO0MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO0MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO0MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO0MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO0MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO0MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO0MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO0MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO0MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO0MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO0MASK= 0x7FFFFFFF;}
		FIO0PIN  &= 0x00000000;
		FIO0MASK= 0x00000000;
  	  }
      else if(portID==1)
	  {
	    if(pinID==0){FIO1MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO1MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO1MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO1MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO1MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO1MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO1MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO1MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO1MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO1MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO1MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO1MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO1MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO1MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO1MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO1MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO1MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO1MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO1MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO1MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO1MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO1MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO1MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO1MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO1MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO1MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO1MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO1MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO1MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO1MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO1MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO1MASK= 0x7FFFFFFF;}
		FIO1PIN  &= 0x00000000;
		FIO1MASK= 0x00000000;
	}
	  else if(portID==2)
	  {
	    if(pinID==0){FIO2MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO2MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO2MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO2MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO2MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO2MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO2MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO2MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO2MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO2MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO2MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO2MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO2MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO2MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO2MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO2MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO2MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO2MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO2MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO2MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO2MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO2MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO2MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO2MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO2MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO2MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO2MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO2MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO2MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO2MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO2MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO2MASK= 0x7FFFFFFF;}
		FIO2PIN  &= 0x00000000;
		FIO2MASK= 0x00000000;
	}
	  else if(portID==3)
	  {
	    if(pinID==0){FIO3MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO3MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO3MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO3MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO3MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO3MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO3MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO3MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO3MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO3MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO3MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO3MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO3MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO3MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO3MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO3MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO3MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO3MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO3MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO3MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO3MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO3MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO3MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO3MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO3MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO3MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO3MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO3MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO3MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO3MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO3MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO3MASK= 0x7FFFFFFF;}
		FIO3PIN  &= 0x00000000;
		FIO3MASK= 0x00000000;
	}
	  else if(portID==4)
	  {
	    if(pinID==0){FIO4MASK= 0xFFFFFFFE;}
		else if(pinID==1){FIO4MASK=  0xFFFFFFFD;}
		else if(pinID==2){FIO4MASK=  0xFFFFFFFB;}
		else if(pinID==3){FIO4MASK=  0xFFFFFFF7;}
		else if(pinID==4){FIO4MASK=  0xFFFFFFEF;}
		else if(pinID==5){FIO4MASK=  0xFFFFFFDF;}
		else if(pinID==6){FIO4MASK=  0xFFFFFFBF;}
		else if(pinID==7){FIO4MASK=  0xFFFFFF7F;}
		else if(pinID==8){FIO4MASK=  0xFFFFFEFF;}
		else if(pinID==9){FIO4MASK=  0xFFFFFDFF;}
		else if(pinID==10){FIO4MASK= 0xFFFFFBFF;}
		else if(pinID==11){FIO4MASK= 0xFFFFF7FF;}
		else if(pinID==12){FIO4MASK= 0xFFFFEFFF;}
		else if(pinID==13){FIO4MASK= 0xFFFFDFFF;}
		else if(pinID==14){FIO4MASK= 0xFFFFBFFF;}
		else if(pinID==15){FIO4MASK= 0xFFFF7FFF;}
		else if(pinID==16){FIO4MASK= 0xFFFEFFFF;}
		else if(pinID==17){FIO4MASK= 0xFFFDFFFF;}
		else if(pinID==18){FIO4MASK= 0xFFFBFFFF;}
		else if(pinID==19){FIO4MASK= 0xFFF7FFFF;}
		else if(pinID==20){FIO4MASK= 0xFFEFFFFF;}
	    else if(pinID==21){FIO4MASK= 0xFFDFFFFF;}
	    else if(pinID==22){FIO4MASK= 0xFFBFFFFF;}
	    else if(pinID==23){FIO4MASK= 0xFF7FFFFF;}
	    else if(pinID==24){FIO4MASK= 0xFEFFFFFF;}
	    else if(pinID==25){FIO4MASK= 0xFDFFFFFF;}
	    else if(pinID==26){FIO4MASK= 0xFBFFFFFF;}
	    else if(pinID==27){FIO4MASK= 0xF7FFFFFF;}
	    else if(pinID==28){FIO4MASK= 0xEFFFFFFF;}
	    else if(pinID==29){FIO4MASK= 0xDFFFFFFF;}
	    else if(pinID==30){FIO4MASK= 0xBFFFFFFF;}
	    else if(pinID==31){FIO4MASK= 0x7FFFFFFF;}
		FIO4PIN  &= 0x00000000;
		FIO4MASK= 0x00000000;
	}
}
/**
* return the value of pin.<br>
* @param bool bitStatus: 
*						- True:  bit value is '1'
*						- False: bit value is '0'
* <br><p><B>Example:</B></p><br>
*  
*  PortPin pin10(2,10,"INPUT");			<br>
*  PortPin pin0(2,0,"OUTPUT","ON");					<br>
*  PortPin pin1(2,1,"OUTPUT","OFF");					<br>
*  if(pin10.getPinValue() )<BR>
*	{		<BR>
*	   pin1.on(); <BR>
*	}	   <BR>
*/
bool PortPin::getPinValue()
{
	bool bitStatus=false;
	if(portID==0)
	{
	 	if((FIO0PIN & (1<<pinID)) == 0 )
		{
			bitStatus=true;
		}
		else
		{
			bitStatus=false;
		}
	}
	else if(portID==1)
	{
	 	if((FIO1PIN & (1<<pinID)) == 0 )
		{
			bitStatus=true;
		}
		else
		{
			bitStatus=false;
		}
	}
	else if(portID==2)
	{
	 	if((FIO2PIN & (1<<pinID)) == 0 )
		{
			bitStatus=true;
		}
		else
		{
			bitStatus=false;
		}
	}
	else if(portID==3)
	{
	 	if((FIO3PIN & (1<<pinID)) == 0 )
		{
			bitStatus=true;
		}
		else
		{
			bitStatus=false;
		}
	}
	else if(portID==4)
	{
	 	if((FIO4PIN & (1<<pinID)) == 0 )
		{
			bitStatus=true;
		}
		else
		{
			bitStatus=false;
		}
	}
	return bitStatus;		
}
int PortPin::getPinNumber(void)
{
	return pinID;
}

/*------------------------------------------------------Private do not touch below this line-----------------------------*/
void PortPin::setPinConfiguration(uint8_t newPortID,int newPinID,std::string initState,std::string IO)
{
	if(portID==0)
	{
		if(pinID==0 && IO=="OUTPUT"){FIO0DIR  |= 0x00000001;}
		else if(pinID==1 && IO=="OUTPUT"){FIO0DIR  |= 0x00000002;}
		else if(pinID==2 && IO=="OUTPUT"){FIO0DIR  |= 0x00000004;}
		else if(pinID==3 && IO=="OUTPUT"){FIO0DIR  |= 0x00000008;}
		else if(pinID==4 && IO=="OUTPUT"){FIO0DIR  |= 0x00000010;}
		else if(pinID==5 && IO=="OUTPUT"){FIO0DIR  |= 0x00000020;}
		else if(pinID==6 && IO=="OUTPUT"){FIO0DIR  |= 0x00000040;}
		else if(pinID==7 && IO=="OUTPUT"){FIO0DIR  |= 0x00000080;}
		else if(pinID==8 && IO=="OUTPUT"){FIO0DIR  |= 0x00000100;}
		else if(pinID==9 && IO=="OUTPUT"){FIO0DIR  |= 0x00000200;}
		else if(pinID==10 && IO=="OUTPUT"){FIO0DIR  |= 0x00000400;}
		else if(pinID==11 && IO=="OUTPUT"){FIO0DIR  |= 0x00000800;}
		else if(pinID==12 && IO=="OUTPUT"){FIO0DIR  |= 0x00001000;}
		else if(pinID==13 && IO=="OUTPUT"){FIO0DIR  |= 0x00002000;}
		else if(pinID==14 && IO=="OUTPUT"){FIO0DIR  |= 0x00004000;}
		else if(pinID==15 && IO=="OUTPUT"){FIO0DIR  |= 0x00008000;}
		else if(pinID==16 && IO=="OUTPUT"){FIO0DIR  |= 0x00010000;}
		else if(pinID==17 && IO=="OUTPUT"){FIO0DIR  |= 0x00020000;}
		else if(pinID==18 && IO=="OUTPUT"){FIO0DIR  |= 0x00040000;}
		else if(pinID==19 && IO=="OUTPUT"){FIO0DIR  |= 0x00080000;}	
		else if(pinID==20 && IO=="OUTPUT"){FIO0DIR  |= 0x00100000;}
		else if(pinID==21 && IO=="OUTPUT"){FIO0DIR  |= 0x00200000;}
		else if(pinID==22 && IO=="OUTPUT"){FIO0DIR  |= 0x00400000;}
		else if(pinID==23 && IO=="OUTPUT"){FIO0DIR  |= 0x00800000;}
		else if(pinID==24 && IO=="OUTPUT"){FIO0DIR  |= 0x01000000;}
		else if(pinID==25 && IO=="OUTPUT"){FIO0DIR  |= 0x02000001;}
		else if(pinID==26 && IO=="OUTPUT"){FIO0DIR  |= 0x04000001;}
		else if(pinID==27 && IO=="OUTPUT"){FIO0DIR  |= 0x08000001;}
		else if(pinID==28 && IO=="OUTPUT"){FIO0DIR  |= 0x10000001;}
		else if(pinID==29 && IO=="OUTPUT"){FIO0DIR  |= 0x20000001;}
		else if(pinID==30 && IO=="OUTPUT"){FIO0DIR  |= 0x40000001;}
		else if(pinID==31 && IO=="OUTPUT"){FIO0DIR  |= 0x80000001;}																
	}
	if(portID==1)
	{
		if(pinID==0 && IO=="OUTPUT"){FIO1DIR  |= 0x00000001;}
		else if(pinID==1 && IO=="OUTPUT"){FIO1DIR  |= 0x00000002;}
		else if(pinID==2 && IO=="OUTPUT"){FIO1DIR  |= 0x00000004;}
		else if(pinID==3 && IO=="OUTPUT"){FIO1DIR  |= 0x00000008;}
		else if(pinID==4 && IO=="OUTPUT"){FIO1DIR  |= 0x00000010;}
		else if(pinID==5 && IO=="OUTPUT"){FIO1DIR  |= 0x00000020;}
		else if(pinID==6 && IO=="OUTPUT"){FIO1DIR  |= 0x00000040;}
		else if(pinID==7 && IO=="OUTPUT"){FIO1DIR  |= 0x00000080;}
		else if(pinID==8 && IO=="OUTPUT"){FIO1DIR  |= 0x00000100;}
		else if(pinID==9 && IO=="OUTPUT"){FIO1DIR  |= 0x00000200;}
		else if(pinID==10 && IO=="OUTPUT"){FIO1DIR  |= 0x00000400;}
		else if(pinID==11 && IO=="OUTPUT"){FIO1DIR  |= 0x00000800;}
		else if(pinID==12 && IO=="OUTPUT"){FIO1DIR  |= 0x00001000;}
		else if(pinID==13 && IO=="OUTPUT"){FIO1DIR  |= 0x00002000;}
		else if(pinID==14 && IO=="OUTPUT"){FIO1DIR  |= 0x00004000;}
		else if(pinID==15 && IO=="OUTPUT"){FIO1DIR  |= 0x00008000;}
		else if(pinID==16 && IO=="OUTPUT"){FIO1DIR  |= 0x00010000;}
		else if(pinID==17 && IO=="OUTPUT"){FIO1DIR  |= 0x00020000;}
		else if(pinID==18 && IO=="OUTPUT"){FIO1DIR  |= 0x00040000;}
		else if(pinID==19 && IO=="OUTPUT"){FIO1DIR  |= 0x00080000;}	
		else if(pinID==20 && IO=="OUTPUT"){FIO1DIR  |= 0x00100000;}
		else if(pinID==21 && IO=="OUTPUT"){FIO1DIR  |= 0x00200000;}
		else if(pinID==22 && IO=="OUTPUT"){FIO1DIR  |= 0x00400000;}
		else if(pinID==23 && IO=="OUTPUT"){FIO1DIR  |= 0x00800000;}
		else if(pinID==24 && IO=="OUTPUT"){FIO1DIR  |= 0x01000000;}
		else if(pinID==25 && IO=="OUTPUT"){FIO1DIR  |= 0x02000001;}
		else if(pinID==26 && IO=="OUTPUT"){FIO1DIR  |= 0x04000001;}
		else if(pinID==27 && IO=="OUTPUT"){FIO1DIR  |= 0x08000001;}
		else if(pinID==28 && IO=="OUTPUT"){FIO1DIR  |= 0x10000001;}
		else if(pinID==29 && IO=="OUTPUT"){FIO1DIR  |= 0x20000001;}
		else if(pinID==30 && IO=="OUTPUT"){FIO1DIR  |= 0x40000001;}
		else if(pinID==31 && IO=="OUTPUT"){FIO1DIR  |= 0x80000001;}																
	}
	if(portID==2)
	{
		if(pinID==0 && IO=="OUTPUT"){FIO2DIR  |= 0x00000001;}
		else if(pinID==1 && IO=="OUTPUT"){FIO2DIR  |= 0x00000002;}
		else if(pinID==2 && IO=="OUTPUT"){FIO2DIR  |= 0x00000004;}
		else if(pinID==3 && IO=="OUTPUT"){FIO2DIR  |= 0x00000008;}
		else if(pinID==4 && IO=="OUTPUT"){FIO2DIR  |= 0x00000010;}
		else if(pinID==5 && IO=="OUTPUT"){FIO2DIR  |= 0x00000020;}
		else if(pinID==6 && IO=="OUTPUT"){FIO2DIR  |= 0x00000040;}
		else if(pinID==7 && IO=="OUTPUT"){FIO2DIR  |= 0x00000080;}
		else if(pinID==8 && IO=="OUTPUT"){FIO2DIR  |= 0x00000100;}
		else if(pinID==9 && IO=="OUTPUT"){FIO2DIR  |= 0x00000200;}
		else if(pinID==10 && IO=="OUTPUT"){FIO2DIR  |= 0x00000400;}
		else if(pinID==11 && IO=="OUTPUT"){FIO2DIR  |= 0x00000800;}
		else if(pinID==12 && IO=="OUTPUT"){FIO2DIR  |= 0x00001000;}
		else if(pinID==13 && IO=="OUTPUT"){FIO2DIR  |= 0x00002000;}
		else if(pinID==14 && IO=="OUTPUT"){FIO2DIR  |= 0x00004000;}
		else if(pinID==15 && IO=="OUTPUT"){FIO2DIR  |= 0x00008000;}
		else if(pinID==16 && IO=="OUTPUT"){FIO2DIR  |= 0x00010000;}
		else if(pinID==17 && IO=="OUTPUT"){FIO2DIR  |= 0x00020000;}
		else if(pinID==18 && IO=="OUTPUT"){FIO2DIR  |= 0x00040000;}
		else if(pinID==19 && IO=="OUTPUT"){FIO2DIR  |= 0x00080000;}	
		else if(pinID==20 && IO=="OUTPUT"){FIO2DIR  |= 0x00100000;}
		else if(pinID==21 && IO=="OUTPUT"){FIO2DIR  |= 0x00200000;}
		else if(pinID==22 && IO=="OUTPUT"){FIO2DIR  |= 0x00400000;}
		else if(pinID==23 && IO=="OUTPUT"){FIO2DIR  |= 0x00800000;}
		else if(pinID==24 && IO=="OUTPUT"){FIO2DIR  |= 0x01000000;}
		else if(pinID==25 && IO=="OUTPUT"){FIO2DIR  |= 0x02000001;}
		else if(pinID==26 && IO=="OUTPUT"){FIO2DIR  |= 0x04000001;}
		else if(pinID==27 && IO=="OUTPUT"){FIO2DIR  |= 0x08000001;}
		else if(pinID==28 && IO=="OUTPUT"){FIO2DIR  |= 0x10000001;}
		else if(pinID==29 && IO=="OUTPUT"){FIO2DIR  |= 0x20000001;}
		else if(pinID==30 && IO=="OUTPUT"){FIO2DIR  |= 0x40000001;}
		else if(pinID==31 && IO=="OUTPUT"){FIO2DIR  |= 0x80000001;}																
	}
	else if(portID==3)
	{
		if(pinID==0 && IO=="OUTPUT"){FIO3DIR  |= 0x00000001;}
		else if(pinID==1 && IO=="OUTPUT"){FIO3DIR  |= 0x00000002;}
		else if(pinID==2 && IO=="OUTPUT"){FIO3DIR  |= 0x00000004;}
		else if(pinID==3 && IO=="OUTPUT"){FIO3DIR  |= 0x00000008;}
		else if(pinID==4 && IO=="OUTPUT"){FIO3DIR  |= 0x00000010;}
		else if(pinID==5 && IO=="OUTPUT"){FIO3DIR  |= 0x00000020;}
		else if(pinID==6 && IO=="OUTPUT"){FIO3DIR  |= 0x00000040;}
		else if(pinID==7 && IO=="OUTPUT"){FIO3DIR  |= 0x00000080;}
		else if(pinID==8 && IO=="OUTPUT"){FIO3DIR  |= 0x00000100;}
		else if(pinID==9 && IO=="OUTPUT"){FIO3DIR  |= 0x00000200;}
		else if(pinID==10 && IO=="OUTPUT"){FIO3DIR  |= 0x00000400;}
		else if(pinID==11 && IO=="OUTPUT"){FIO3DIR  |= 0x00000800;}
		else if(pinID==12 && IO=="OUTPUT"){FIO3DIR  |= 0x00001000;}
		else if(pinID==13 && IO=="OUTPUT"){FIO3DIR  |= 0x00002000;}
		else if(pinID==14 && IO=="OUTPUT"){FIO3DIR  |= 0x00004000;}
		else if(pinID==15 && IO=="OUTPUT"){FIO3DIR  |= 0x00008000;}
		else if(pinID==16 && IO=="OUTPUT"){FIO3DIR  |= 0x00010000;}
		else if(pinID==17 && IO=="OUTPUT"){FIO3DIR  |= 0x00020000;}
		else if(pinID==18 && IO=="OUTPUT"){FIO3DIR  |= 0x00040000;}
		else if(pinID==19 && IO=="OUTPUT"){FIO3DIR  |= 0x00080000;}	
		else if(pinID==20 && IO=="OUTPUT"){FIO3DIR  |= 0x00100000;}
		else if(pinID==21 && IO=="OUTPUT"){FIO3DIR  |= 0x00200000;}
		else if(pinID==22 && IO=="OUTPUT"){FIO3DIR  |= 0x00400000;}
		else if(pinID==23 && IO=="OUTPUT"){FIO3DIR  |= 0x00800000;}
		else if(pinID==24 && IO=="OUTPUT"){FIO3DIR  |= 0x01000000;}
		else if(pinID==25 && IO=="OUTPUT"){FIO3DIR  |= 0x02000001;}
		else if(pinID==26 && IO=="OUTPUT"){FIO3DIR  |= 0x04000001;}
		else if(pinID==27 && IO=="OUTPUT"){FIO3DIR  |= 0x08000001;}
		else if(pinID==28 && IO=="OUTPUT"){FIO3DIR  |= 0x10000001;}
		else if(pinID==29 && IO=="OUTPUT"){FIO3DIR  |= 0x20000001;}
		else if(pinID==30 && IO=="OUTPUT"){FIO3DIR  |= 0x40000001;}
		else if(pinID==31 && IO=="OUTPUT"){FIO3DIR  |= 0x80000001;}	
	}
	else if(portID==4)
	{
		if(pinID==0 && IO=="OUTPUT"){FIO4DIR        |= 0x00000001;}
		else if(pinID==1 && IO=="OUTPUT"){FIO4DIR   |= 0x00000002;}
		else if(pinID==2 && IO=="OUTPUT"){FIO4DIR   |= 0x00000004;}
		else if(pinID==3 && IO=="OUTPUT"){FIO4DIR   |= 0x00000008;}
		else if(pinID==4 && IO=="OUTPUT"){FIO4DIR   |= 0x00000010;}
		else if(pinID==5 && IO=="OUTPUT"){FIO4DIR   |= 0x00000020;}
		else if(pinID==6 && IO=="OUTPUT"){FIO4DIR   |= 0x00000040;}
		else if(pinID==7 && IO=="OUTPUT"){FIO4DIR   |= 0x00000080;}
		else if(pinID==8 && IO=="OUTPUT"){FIO4DIR   |= 0x00000100;}
		else if(pinID==9 && IO=="OUTPUT"){FIO4DIR   |= 0x00000200;}
		else if(pinID==10 && IO=="OUTPUT"){FIO4DIR  |= 0x00000400;}
		else if(pinID==11 && IO=="OUTPUT"){FIO4DIR  |= 0x00000800;}
		else if(pinID==12 && IO=="OUTPUT"){FIO4DIR  |= 0x00001000;}
		else if(pinID==13 && IO=="OUTPUT"){FIO4DIR  |= 0x00002000;}
		else if(pinID==14 && IO=="OUTPUT"){FIO4DIR  |= 0x00004000;}
		else if(pinID==15 && IO=="OUTPUT"){FIO4DIR  |= 0x00008000;}
		else if(pinID==16 && IO=="OUTPUT"){FIO4DIR  |= 0x00010000;}
		else if(pinID==17 && IO=="OUTPUT"){FIO4DIR  |= 0x00020000;}
		else if(pinID==18 && IO=="OUTPUT"){FIO4DIR  |= 0x00040000;}
		else if(pinID==19 && IO=="OUTPUT"){FIO4DIR  |= 0x00080000;}	
		else if(pinID==20 && IO=="OUTPUT"){FIO4DIR  |= 0x00100000;}
		else if(pinID==21 && IO=="OUTPUT"){FIO4DIR  |= 0x00200000;}
		else if(pinID==22 && IO=="OUTPUT"){FIO4DIR  |= 0x00400000;}
		else if(pinID==23 && IO=="OUTPUT"){FIO4DIR  |= 0x00800000;}
		else if(pinID==24 && IO=="OUTPUT"){FIO4DIR  |= 0x01000000;}
		else if(pinID==25 && IO=="OUTPUT"){FIO4DIR  |= 0x02000001;}
		else if(pinID==26 && IO=="OUTPUT"){FIO4DIR  |= 0x04000001;}
		else if(pinID==27 && IO=="OUTPUT"){FIO4DIR  |= 0x08000001;}
		else if(pinID==28 && IO=="OUTPUT"){FIO4DIR  |= 0x10000001;}
		else if(pinID==29 && IO=="OUTPUT"){FIO4DIR  |= 0x20000001;}
		else if(pinID==30 && IO=="OUTPUT"){FIO4DIR  |= 0x40000001;}
		else if(pinID==31 && IO=="OUTPUT"){FIO4DIR  |= 0x80000001;}	
	}	

	if(initState=="ON")
	{
		PortPin::on();	
	}
	else if(initState=="OFF")
	{
		PortPin::off();	
	}

}
std::string PortPin::StringToUpper(std::string myString)
{
  const int length = myString.length();
  for(int i=0; i!=length ; ++i)
  {
    myString[i] = std::toupper(myString[i]);
  }
  return myString;
}
