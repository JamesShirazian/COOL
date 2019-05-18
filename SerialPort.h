#ifndef SerialPort_h
#define SerialPort_h
#include <LPC23xx.H> 
#include <stdio.h>
#include <string>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <stddef.h>

#define UART1                            /* Use UART 0 for printf             */

typedef std::vector<char>       charVector;

/** @defgroup group8 SerialPort - (UART0, UART1)
 *  SerialPort - (UART0, UART1) 
 *  @{
 */
/*! \brief class SerialPort: is a class in charge of  serial port which is connected to ARM 7 processor. 
*	- UART 0
*	- UART 1
  \ingroup common
 */   

class SerialPort
{
public:
	SerialPort(void);
    SerialPort(uint8_t serialPortNo);
	void open(void);
	void close(void);
	char readCharachter(void);
	std::string readLine(char endPoint,bool displayCharachterOnScreenWhileUserIsPressingKeys);
	void write(charVector charValue,bool newLine);
	void write(char *charValue,bool newLine);
	void write(std::string stringValue,bool newLine);
	void write(int integerValue,bool newLine);
	void write(float floatValue,int decimalPoint,bool newLine);

private:
	void newLineOperator(bool newLine);
	void writeChar(char ch);
	char readChar();
	char charIntegerValue[10];
	char charFloatValue[10];
	int charachterCounter;
	int serialPortNo;
};

#endif
