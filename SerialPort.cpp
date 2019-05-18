#include "SerialPort.h"


/**
* Default constructor: Initialize serial port (UART0 by default).<br>
*/
SerialPort::SerialPort(void):serialPortNo(0)
{
    PINSEL0 |= 0x00000050;               /* Enable TxD0 and RxD0              */
}
/**
* Second constructor: Initialize serial port by user specfication: <br>
* @param  uint8_t newSerialPortNo: Serial port number 
*								- '0' : UART0
*								- '1' : UART1
*/

SerialPort::SerialPort(uint8_t newSerialPortNo):serialPortNo(newSerialPortNo)
{
  if(serialPortNo==0)
  {
    PINSEL0 |= 0x00000050;               /* Enable TxD0 and RxD0              */
  }
  else if(serialPortNo==1)
  {
    PINSEL0 |= 0x40000000;               /* Enable TxD1                       */
    PINSEL1 |= 0x00000001;               /* Enable RxD1                       */
  }
}
/**
* Open serial port for communication.<br>
* <br><p><B>Example:</B></p><br>
*  
*  SerialPort SP(0);			<br>
*  SP.open();
*/

void SerialPort::open(void)
{
  if(serialPortNo==0)
   {
   U0FDR    = 0;                          /* Fractional divider not used       */
   U0LCR    = 0x83;                       /* 8 bits, no Parity, 1 Stop bit     */
   U0DLL    = 78;                         /* 9600 Baud Rate @ 12.0 MHZ PCLK    */
   U0DLM    = 0;                          /* High divisor latch = 0            */
   U0LCR    = 0x03;                       /* DLAB = 0                          */
   }
   else if(serialPortNo==1)
   {
   U1FDR    = 0;                          /* Fractional divider not used       */
   U1LCR    = 0x83;                       /* 8 bits, no Parity, 1 Stop bit     */
   U1DLL    = 78;                         /* 9600 Baud Rate @ 12.0 MHZ PCLK    */
   U1DLM    = 0;                          /* High divisor latch = 0            */
   U1LCR    = 0x03;                       /* DLAB = 0                          */
   }
 }
/**
* Close serial port and terminate communication.<br>
* <br><p><B>Example:</B></p><br>
*  
*  SerialPort SP(0);			<br>
*  SP.open();
*/

void SerialPort::close(void)
{
   if(serialPortNo==0)
   {
	   U0FDR    = 0;                          /* Fractional divider not used       */
	   U0LCR    = 0x0;                       /* 8 bits, no Parity, 1 Stop bit     */
	   U0DLL    = 0x0;                         /* 9600 Baud Rate @ 12.0 MHZ PCLK    */
	   U0DLM    = 0;                          /* High divisor latch = 0            */
	   U0LCR    = 0x0;                       /* DLAB = 0                          */
   }
   else if(serialPortNo==1)
   {
	   U1FDR    = 0;                          /* Fractional divider not used       */
	   U1LCR    = 0x0;                       /* 8 bits, no Parity, 1 Stop bit     */
	   U1DLL    = 0x0;                         /* 9600 Baud Rate @ 12.0 MHZ PCLK    */
	   U1DLM    = 0;                          /* High divisor latch = 0            */
	   U1LCR    = 0x0;                       /* DLAB = 0                          */
   }
}
/**
* Read data from serial port.<br>
* <br><p><B>Example:</B></p><br>
*  
*  SerialPort SP(0);			<br>
*  SP.open();
*/

char SerialPort::readCharachter()
{
   int readChar=0;
   if(serialPortNo==0)
   {
    while (!(U0LSR & 0x01));
     readChar=U0RBR;
   }
   else	if(serialPortNo==1)
   {
    while (!(U1LSR & 0x01));
     readChar=U1RBR;
   }
   return readChar;
}
/**
* Read line from serial port and release its data once the last charachter is equal to ebdPoint charachter.<br>
* @param char endPoint: charachter which release the line of charachter from UART to ARM7 processor.<br>
* @param bool displayCharachterOnScreenWhileUserIsPressingKeys: display charachter which user is pressing till the end point charachter preesed
*								- true : display on Terminal
								- false: does not display on Terminal
* <br><p><B>Example:</B></p><br>
*
*  std::string myData;  	 <br>
*  SerialPort SP(0);			<br>
*  SP.open();
*  myData=SP.readLine('.',true); //Once '.' press myData is equalt to string of entered data		 <br>
*/
std::string SerialPort::readLine(char endPoint,bool displayCharachterOnScreenWhileUserIsPressingKeys)
{
  char lastChar;
  std::string line;
  int charCounter=0;
  do
  {
  	    lastChar=SerialPort::readCharachter();   //Read char from UART
		if(displayCharachterOnScreenWhileUserIsPressingKeys)
		{
  	    	writeChar(lastChar);           //Display char on the Terminal
		}
		line.push_back(lastChar);
		charCounter++;
  }
  while(lastChar!=endPoint);
  line.erase(charCounter);//remove space
  line.erase(charCounter-1);//remove end point charachter
  return line;
}
/**
* Write array of charachter to serial port.<br>
* @param   char *charValue: array of charachter which send to serial port
* @param   bool newLine:
*						- True : go to new line (\\n\\r)
*						- False : keep the curser where it is.
* <br><p><B>Example:</B></p><br>
*  
*  SerialPort SP(0);			<br>
*  SP.open();					 <br>
*  SP.write("Hi James",true);<br>
*/

void SerialPort::write(char *charValue,bool newLine)
{
  std::string data=charValue;
  int charCounter=0;
  for(charCounter=0;charCounter<=data.length();charCounter++)
  {
  	writeChar(data[charCounter]);
  }	
  newLineOperator(newLine);
}
 /**
* Write string to serial port.<br>
* @param   std::string stringValue: string which send to serial port
* @param   bool newLine:
*						- True : go to new line (\\n\\r)
*						- False : keep the curser where it is.
* <br><p><B>Example:</B></p><br>
* 
*  std::string myText="Hi Afshin!"; <br>
*  SerialPort SP(0);			<br>
*  SP.open();					 <br>
*  SP.write(myText,true);<br>
*/
void SerialPort::write(std::string stringValue,bool newLine)
{
   int charCounter=0;
	  for(charCounter=0;charCounter<=stringValue.length();charCounter++)
	  {
	  	writeChar(stringValue[charCounter]);
	  }
   newLineOperator(newLine);
}
	
 /**
* Write integer to serial port.<br>
* @param   int integerValue: integer which send to serial port
* @param   bool newLine:
*						- True : go to new line (\\n\\r)
*						- False : keep the curser where it is.
* <br><p><B>Example:</B></p><br>
* 
*  SerialPort SP(0);			<br>
*  SP.open();					 <br>
*  SP.write(25,true);<br>
*/	
void SerialPort::write(int integerValue,bool newLine)
{
	sprintf(charIntegerValue,"%d",integerValue);
	char *pointerToConvertedInteger= charIntegerValue;
	printf(pointerToConvertedInteger);
    newLineOperator(newLine);

}
 /**
* Write integer to serial port.<br>
* @param   float floatValue: float which send to serial port
* @param   bool newLine:
*						- True : go to new line (\\n\\r)
*						- False : keep the curser where it is.
* <br><p><B>Example:</B></p><br>
* 
*  float weight=54.765;			<br>
*  SerialPort SP(0);			<br>
*  SP.open();					 <br>
*  SP.write(weight,true);<br>
*/	
void SerialPort::write(float floatValue,int decimalPoint,bool newLine)
{
	if(decimalPoint==0){sprintf(charFloatValue,"%.0f",floatValue);}
	else if(decimalPoint==1){sprintf(charFloatValue,"%.1f",floatValue);}
	else if(decimalPoint==2){sprintf(charFloatValue,"%.2f",floatValue);}
	else if(decimalPoint==3){sprintf(charFloatValue,"%.3f",floatValue);}
	else if(decimalPoint==4){sprintf(charFloatValue,"%.4f",floatValue);}
	else if(decimalPoint==5){sprintf(charFloatValue,"%.5f",floatValue);}
	else if(decimalPoint==6){sprintf(charFloatValue,"%.6f",floatValue);}
	else if(decimalPoint==7){sprintf(charFloatValue,"%.7f",floatValue);}
	else if(decimalPoint==8){sprintf(charFloatValue,"%.8f",floatValue);}
	else if(decimalPoint==9){sprintf(charFloatValue,"%.9f",floatValue);}
	else {sprintf(charFloatValue,"%.0f",floatValue);}
	char *pointerToConvertedFloat= charFloatValue;
	printf(pointerToConvertedFloat);
	newLineOperator(newLine);
}  
/*-------------------------------------------Private function do not touch below this line---------------------*/
void SerialPort::writeChar(char ch)
{
   if(serialPortNo==0)
   {
	   if (ch == '\n')
	   {
	    while (!(U0LSR & 0x20));
	    U0THR = '\r';
	   }        
	   while (!(U0LSR & 0x20));
	   U0THR = ch;
	}
	else if(serialPortNo==1)
	{
	   if (ch == '\n')
	   {
	    while (!(U1LSR & 0x20));
	    U1THR = '\r';
	   }        
	   while (!(U1LSR & 0x20));
	   U1THR = ch;
	}
}      
void SerialPort::newLineOperator(bool newLine)
{
  if(newLine==true)
  {
  	printf("\n\r");
  }
}
