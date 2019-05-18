#include "SDCard.h"

SDCard::SDCard(const char *fileName):tt(fileName)
{
   finit ();
}


void SDCard::write(std::string stringOfData)
{
	int charCounter=0;
	char lastChar;
	filePointer = fopen(tt,"w");
	for(charCounter=0;charCounter<=stringOfData.size();charCounter++)
	{
		lastChar=stringOfData[charCounter];
    	fputc(lastChar,filePointer);			
	}
	fclose(filePointer);
	
}
void SDCard::append(std::string stringOfData)
{
	int charCounter=0;
	char lastChar;
	filePointer = fopen(tt,"a");
	for(charCounter=0;charCounter<=stringOfData.size();charCounter++)
	{
		lastChar=stringOfData[charCounter];
    	fputc(lastChar,filePointer);			
	}
	fclose(filePointer);
	
}
void SDCard::remove(const char *fileName)
{
   fdelete(fileName);
}
void SDCard::format(void)
{
	fformat ("M:");	
}
