#ifndef PortPin_H
#define PortPin_H
#include <LPC23xx.H>                    
#include <stdint.h>
#include <string>
#include <cctype>
/** @defgroup group7 Port(GPIO) - Individual pin of ports 
 *  Port(GPIO) - Individual pin of ports 
 *  @{
 */
 /*! \brief class RealTimeClock: is a class in charge of GPIO (Port 0,1,2,3,4) which  is connected to ARM 7 processor. 
  \ingroup common
  /sa Interrupt
 */  
class PortPin
{
public:
   PortPin(uint8_t newPortID,int pinID,std::string IO); 
   PortPin(uint8_t newPortID,int newPinID,std::string IO,std::string initState);
   void on(void);
   void off(void);
   bool getPinValue(void);
   int getPinNumber(void);
private:
   void setPinConfiguration(uint8_t newPortID,int newPinID,std::string initState,std::string IO);
   std::string StringToUpper(std::string myString);
   int pinID;
   uint8_t portID;
};

#endif
