#ifndef SDCard_h
#define SDCard_h

#include <LPC23xx.H> 
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <RTL.h>
#include <string>

class SDCard
{
public:
	SDCard(const char *myname);
	void write(std::string string);
	void append(std::string string);
	void remove(const char *fileName);
	void format(void);
private:
   	FILE *filePointer;
	const char *tt;
};

#endif
