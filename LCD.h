#ifndef LCD_H
#define LCD_H

#include <LPC23xx.H>                    

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <string>
#include "math.h"
#define PIN_E                 0x80000000
#define PIN_RW                0x20000000
#define PIN_RS                0x10000000
#define PINS_CTRL             0xB0000000
#define PINS_DATA             0x0F000000

#ifdef  MCB2300_V1
  #undef  PIN_E
  #define PIN_E               0xC0000000
  #undef  PINS_CTRL
  #define PINS_CTRL           0xF0000000
#endif

/* pin E  setting to 0 or 1                                                   */
#define LCD_E(x)              ((x) ? (IOSET1 = PIN_E)  : (IOCLR1 = PIN_E) );

/* pin RW setting to 0 or 1                                                   */
#define LCD_RW(x)             ((x) ? (IOSET1 = PIN_RW) : (IOCLR1 = PIN_RW));

/* pin RS setting to 0 or 1                                                   */
#define LCD_RS(x)             ((x) ? (IOSET1 = PIN_RS) : (IOCLR1 = PIN_RS));

/* Reading DATA pins                                                          */
#define LCD_DATA_IN           ((IOPIN1 >> 24) & 0xF)

/* Writing value to DATA pins                                                 */
#define LCD_DATA_OUT(x)       IOCLR1 = PINS_DATA; IOSET1 = (x & 0xF) << 24;

/* Setting all pins to output mode                                            */
#define LCD_ALL_DIR_OUT       IODIR1  |=  PINS_CTRL | PINS_DATA;

/* Setting DATA pins to input mode                                            */
#define LCD_DATA_DIR_IN       IODIR1 &= ~PINS_DATA;

/* Setting DATA pins to output mode                                           */
#define LCD_DATA_DIR_OUT      IODIR1 |=  PINS_DATA;

/******************************************************************************/
#define DELAY_2N     0

/* 8 user defined characters to be loaded into CGRAM (used for bargraph)      */
const uint8_t UserFont[8][8] = {
  { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
  { 0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10 },
  { 0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18 },
  { 0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C },
  { 0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E },
  { 0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F },
  { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
  { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }
};
/** @defgroup group4 LCD
 *  LCD
 *  @{
 */
/**
 *  @ingroup group1
 */
/*! \brief class LCDDisplay: is a class in charge of LCD which is connected to ARM 7 processor.
  \ingroup common
 */              
class LCD
{
public:
	LCD();
	LCD(uint8_t newCol,uint8_t newRow);
    void write(char *text,uint8_t row,uint8_t col);
	void write(std::string text,uint8_t newCol,uint8_t newRow);
	void write(int value,int maxNumberOfDigit,uint8_t col,uint8_t row);
	void write(float value,int decimalPoint,uint8_t col,uint8_t row);
	void clear(void);
	
private:
	void lcd_write_4bit (uint8_t c);
	void lcd_write_cmd (uint8_t c);
	void lcd_clear   (void);
	void set_cursor  (uint8_t column, uint8_t line);
	uint8_t wait_while_busy (void);
    unsigned char lcd_read_status (void);
   	void lcd_write_data (uint8_t c);
	void getFloatingText(int );
    void delay (int cnt);

	uint8_t row,col;
  	
};

#endif
