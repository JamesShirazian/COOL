#include "LCD.h"
int c=0;
/**
* Default constructor: Initialize LCD , by default it aasume that LCD is 16x2 <br>
*/
LCD::LCD()
{
  col=16;
  row=1;
  int userFontCounter;
  uint8_t const *pointerToUSerFont;

  /* Set all pins for LCD as outputs                                          */
  LCD_ALL_DIR_OUT
  LCD_RS(0)
  lcd_write_4bit (0x3);                 /* Select 4-bit interface             */
  lcd_write_4bit (0x3);
  lcd_write_4bit (0x3);
  lcd_write_4bit (0x2);
  lcd_write_cmd (0x28);                 /* 2 lines, 5x8 character matrix      */
  lcd_write_cmd (0x0C);                 /* Display ctrl:Disp=ON,Curs/Blnk=OFF */
  lcd_write_cmd (0x06);                 /* Entry mode: Move right, no shift   */

  /* Load user-specific characters into CGRAM                                 */
  lcd_write_cmd(0x40);                  /* Set CGRAM address counter to 0     */
  pointerToUSerFont = &UserFont[0][0];
  for (userFontCounter = 0; userFontCounter < sizeof(UserFont); userFontCounter++, pointerToUSerFont++)
    lcd_write_data (*pointerToUSerFont);

  lcd_write_cmd(0x80);                  /* Set DDRAM address counter to 0     */
}
/**
* Second constructor: Initialize LCD by user specfication: <br>
* @param  uint8_t newCol: set number of LCD columns
* @param  uint8_t newRow: set number of LCD rows
*/

LCD::LCD(uint8_t newCol,uint8_t newRow)
{
  int font;
  uint8_t const *pointerToUserFont;
  col=newCol;
  row=newRow;
  /* Set all pins for LCD as outputs                                          */
  LCD_ALL_DIR_OUT
  LCD_RS(0)
  lcd_write_4bit (0x3);                 /* Select 4-bit interface             */
  lcd_write_4bit (0x3);
  lcd_write_4bit (0x3);
  lcd_write_4bit (0x2);
  lcd_write_cmd (0x28);                 /* 2 lines, 5x8 character matrix      */
  lcd_write_cmd (0x0C);                 /* Display ctrl:Disp=ON,Curs/Blnk=OFF */
  lcd_write_cmd (0x06);                 /* Entry mode: Move right, no shift   */

  /* Load user-specific characters into CGRAM                                 */
  lcd_write_cmd(0x40);                  /* Set CGRAM address counter to 0     */
  pointerToUserFont = &UserFont[0][0];
  for (font = 0; font < sizeof(UserFont); font++, pointerToUserFont++)
    lcd_write_data (*pointerToUserFont);

  lcd_write_cmd(0x80);                  /* Set DDRAM address counter to 0     */
}
/**
* Display array of characher:<br>
* @param  char *text: array of charachter which will display on LCD
* @param  uint8_t newCol: set the text columns  position 
* @param  uint8_t newRow: set the text rows position  <br>
* <br><p><B>Example:</B></p><br>
*  
*  LCD LCD;			<br>
*  LCD.display("Hello",0,0)						<br>
*/
void LCD::write(char *text,uint8_t newCol,uint8_t newRow)
{  
    set_cursor(newCol,newRow)	;
	while (*text)  
	{
		lcd_write_data (*text++);
    }
}
/**
* Display string:<br>
* @param  std::string: string that display on LCD
* @param  uint8_t newCol: set the text columns  position 
* @param  uint8_t newRow: set the text rows position   <br>
* <br><p><B>Example:</B></p><br>
*  
*  LCD LCD;			<br>
*  std::string myName="Afshin James Shirazian"; <br>
*  LCD.display(myName,0,0)						<br>
*/
void LCD::write(std::string text,uint8_t newCol,uint8_t newRow)
{  
    set_cursor(newCol,newRow)	;
	while (c<=text.length())  
	{
		lcd_write_data (text[c]);
		c++;
    }
}


/**
* Display integer:<br>
* @param  int value: integer which will display on LCD
* @param  int maxNumberOfDigit: maximum number of digit which developer expect from "value"
* @param  uint8_t newCol: set the text columns  position 
* @param  uint8_t newRow: set the text rows position  <br>
* <br><p><B>Example:</B></p><br>
*  
*  LCD LCD;			<br>
*  LCD.display(234,3,0,0)						<br>
*/
void LCD::write(int value,int maxNumberOfDigit,uint8_t col,uint8_t row)
{  
	int digitCounter=0,maxValue=0;
	maxValue=((int)(pow((double)10,(double)maxNumberOfDigit)))-1;
	set_cursor(col,row)	;
	char valueInteger[10];
	sprintf(valueInteger,"%d",value);
	for(digitCounter=0;digitCounter<maxNumberOfDigit;digitCounter++)
	{
		write(" ",col+digitCounter,row);
	} 
	if(((int)((pow((double)10,(double)(maxNumberOfDigit)))-1))>=value)
	{
		write(valueInteger,col,row);
	}
	else
	{
		sprintf(valueInteger,"%d",maxValue);
	    write(valueInteger,col,row);
	}

	    
}
/**
* Display float:<br>
* @param  float value: integer which will display on LCD
* @param  int decimalPoint: number of decimal point of "value" , from 0 to 9
* @param  uint8_t newCol: set the text columns  position 
* @param  uint8_t newRow: set the text rows position   <br>
* <br><p><B>Example:</B></p><br>
*  
*  LCD LCD;			<br>
*  LCD.display(23.34,2,0,0)						<br>  
*/

void LCD::write(float value,int decimalPoint,uint8_t col,uint8_t row)
{  
	set_cursor(col,row)	;
	char valueFloat[10];
	if(decimalPoint==0){sprintf(valueFloat,"%.0f",value);}
	else if(decimalPoint==1){sprintf(valueFloat,"%.1ff",value);}
	else if(decimalPoint==2){sprintf(valueFloat,"%.2f",value);}
	else if(decimalPoint==3){sprintf(valueFloat,"%.3f",value);}
	else if(decimalPoint==4){sprintf(valueFloat,"%.4f",value);}
	else if(decimalPoint==5){sprintf(valueFloat,"%.5f",value);}
	else if(decimalPoint==6){sprintf(valueFloat,"%.6f",value);} 
	else if(decimalPoint==7){sprintf(valueFloat,"%.7f",value);} 
	else if(decimalPoint==8){sprintf(valueFloat,"%.8f",value);} 
	else if(decimalPoint==9){sprintf(valueFloat,"%.9f",value);}
	else {sprintf(valueFloat,"%.0f",value);} 
	write(valueFloat,col,row);
}
/**
* Clear LCD<br>
* <br><p><B>Example:</B></p><br>
*  
*  LCD LCD;			<br>
*  LCD.clear()   <br>
*  LCD.display(234,3,0,0)						<br>
*/
void LCD::clear()
{
    lcd_write_cmd(0x01);
	set_cursor (0, 0); 
//  int currentCol,currentRow;
//  for(currentCol=0;currentCol<=col;currentCol++)
//	{
//     for(currentRow=0;currentRow<=row;currentRow++)
//	 	{
//  			display(" ",currentCol,currentRow);
//		}
//	}  
}

/*-------------------------------------Private Section (Do not touch below this line)--------------------------*/

/**
@Brief
  Set cursor: Private API set the cursor of charachter position
*/
void LCD::set_cursor (uint8_t col, uint8_t row)
{
  uint8_t address;
  address = (row * 40) + col;
  address = 0x80 + (address & 0x7F);
  lcd_write_cmd(address);               /* Set DDRAM address counter to 0     */
}


/**
@Brief
  wait_while_busy: cause 5000 cycle of dealy which is required by LCD do apply commands
*/
uint8_t LCD::wait_while_busy (void)
{  
	unsigned char status=0;
	int a=0;

  do  {
    status = lcd_read_status();
  }  while (status & 0x80);            // Wait for busy flag               
   
	for(a=0;a<5000;a++);;
  return (status);
}

unsigned char LCD::lcd_read_status (void)
{
  unsigned char status;

  LCD_DATA_DIR_IN
  LCD_RS(0)
  LCD_RW(1)
  delay(10);
  LCD_E(1)
  delay(10);
  status  = LCD_DATA_IN << 4;
  LCD_E(0)
  delay(10);
  LCD_E(1)
  delay(10);
  status |= LCD_DATA_IN;
  LCD_E(0)
  LCD_DATA_DIR_OUT
  return (status);
}
void LCD::delay (int cnt)
{
  cnt <<= DELAY_2N;

  while (cnt--);
}	 
/**
@Brief
  lcd_write_4bit: Write 4 bit command to the LCD
*/
void LCD::lcd_write_4bit (uint8_t c)
{
  LCD_RW(0)
  LCD_E(1)
  LCD_DATA_OUT(c&0x0F)
  LCD_E(0)
}


/**
@Brief
  lcd_write_cmd: Write command to LCD
*/
void LCD::lcd_write_cmd (uint8_t c)
{
  wait_while_busy(); 
  LCD_RS(0)
  lcd_write_4bit (c>>4);
  lcd_write_4bit (c);
}

/**
@Brief
  lcd_write_cmd: Write data to LCD
*/
void LCD::lcd_write_data (uint8_t c)
{
  wait_while_busy();
  LCD_RS(1)
  lcd_write_4bit (c>>4);
  lcd_write_4bit (c);
}




/******************************************************************************/

