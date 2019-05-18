#ifndef Key_h
#define Key_h
#include <LPC23xx.H> 



/** @defgroup group12 Keys
 *  Keys
 *  @{
 */
/*! \brief class Key: is a class provide methods which use to present keyboard keys. 
  \ingroup common
 */   

class Key
{
public:
	Key(void);
	int  const  ENTER;
	int  const  DELETE;	
	int  const  BACKSPACE;
	int  const  SPACE;
	int  const  ESCAPE;
	int  const  F1;
	int  const  F2;
	int  const  F3;
	int  const  F4;
	int  const  F5;
	int  const  F6;
	int  const  F7;
	int  const  F8;
	int  const  F9;
	int  const  F10;
	int  const  F11;
	int  const  F12;

private:

};

#endif
