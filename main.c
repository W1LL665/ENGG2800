/** 
 * --------------------------------------------------------------------------------------------+ 
 * @name        Main example st7735 LCD driver
 * --------------------------------------------------------------------------------------------+ 
 *              Copyright (C) 2020 Marian Hrinko.
 *              Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       13.10.2020
 * @update      21.06.2021
 * @file        main.c
 * @version     2.0
 * @tested      AVR Atmega328
 *
 * @depend      st7735.h
 * --------------------------------------------------------------------------------------------+
 * @descr       Version 1.0 -> applicable for 1 display
 *              Version 2.0 -> applicable for more than 1 display
 */
#include "lib/st7735.h"

/**
 * 
 * @desc Draws a smiley face
 *
 * @param   struct st7735 *
 * @param   uint8_t x position
 * @param   uint8_t y position
 * @param   uint16_t color
 *
 * @return  void
 *
 */
void ST7735_DrawSmiley (struct st7735 * lcd, uint8_t x, uint8_t y, uint16_t color) {
	//ST7735_DrawPixel(lcd, x, y, color); THIS IS THE CENTRE
	// Draw Left Eye
	ST7735_DrawRectangle(lcd, x-5, x-3, y-5, y-3, color);
	// Draw Right Eye
	ST7735_DrawRectangle(lcd, x+5, x+3, y-5, y-3, color);
	// Draw mouth
	ST7735_DrawRectangle(lcd, x-7, x-6, y+3, y+5, color);
	ST7735_DrawRectangle(lcd, x-5, x-4, y+4, y+6, color);
	ST7735_DrawRectangle(lcd, x-3, x+3, y+5, y+7, color);
	ST7735_DrawRectangle(lcd, x+4, x+5, y+4, y+6, color);
	ST7735_DrawRectangle(lcd, x+6, x+7, y+3, y+5, color);
}


/**
 * 
 * @desc Draws a sad face
 *
 * @param   struct st7735 *
 * @param   uint8_t x position
 * @param   uint8_t y position
 * @param   uint16_t color
 *
 * @return  void
 *
 */
void ST7735_DrawSad (struct st7735 * lcd, uint8_t x, uint8_t y, uint16_t color) {
	//ST7735_DrawPixel(lcd, x, y, color); THIS IS THE CENTRE
	// Draw Left Eye
	ST7735_DrawRectangle(lcd, x-5, x-3, y-5, y-3, color);
	// Draw Right Eye
	ST7735_DrawRectangle(lcd, x+5, x+3, y-5, y-3, color);
	// Draw mouth
	ST7735_DrawRectangle(lcd, x-7, x-6, y+5, y+7, color);
	ST7735_DrawRectangle(lcd, x-5, x-4, y+4, y+6, color);
	ST7735_DrawRectangle(lcd, x-3, x+3, y+3, y+5, color);
	ST7735_DrawRectangle(lcd, x+4, x+5, y+4, y+6, color);
	ST7735_DrawRectangle(lcd, x+6, x+7, y+5, y+7, color);
}


/**
 * @desc    Main function
 *
 * @param   Void
 *
 * @return  Void
 */
int main (void)
{
	  //for (int i=0; i<20000; i++) {
		//  PORTC |= (1<<5);
	  //}
	  //for (int i=0; i<20000; i++) {
	//	  PORTC &= ~(1<<5);
	  //}
  // start
  uint8_t start = 0;
  // end
  uint8_t end = MAX_X - start;

  // LCD 1 - init struct
  // ----------------------------------------------------------
  // Chip Select
  struct signal cs = { .ddr = &DDRB, .port = &PORTB, .pin = 2 };
  // Back Light
  struct signal bl = { .ddr = &DDRB, .port = &PORTB, .pin = 1 };
  // Data / Command
  struct signal dc = { .ddr = &DDRB, .port = &PORTB, .pin = 0 };
  // Reset
  struct signal rs = { .ddr = &DDRD, .port = &PORTD, .pin = 7 };
  // LCD struct
  struct st7735 lcd1 = { .cs = &cs, .bl = &bl, .dc = &dc, .rs = &rs };

  // LCD 1
  // ----------------------------------------------------------
  // init lcd 1
  ST7735_Init (&lcd1);
  // clear screen
  ST7735_ClearScreen (&lcd1, BLACK);
  // set position X, Y
  int response = ST7735_SetPosition (start, 35); // y was 10 
  if (response = ST7735_ERROR) {
	  PORTC |= (1<<5);
  }
  // draw string
  ST7735_DrawString (&lcd1, "Hello World", WHITE, X2); // was x2

  //ST7735_DrawRectangle (&lcd1, start, end, 90, 100, RED);
  // draw Loading
  //for (uint8_t i = start; i < end; i++) {
    // draw rectangle
    //ST7735_DrawRectangle (&lcd1, start, i, 30, 40, RED); // was red
  //}
  ST7735_DrawSmiley (&lcd1, 130, 40, WHITE);
  ST7735_DrawSad(&lcd1, 100, 40, WHITE);

  return 0;
}
