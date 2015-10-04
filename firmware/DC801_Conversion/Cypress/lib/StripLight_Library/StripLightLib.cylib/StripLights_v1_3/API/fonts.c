/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

#include "cytypes.h"
#include "stdlib.h"
#include "cyfitter.h"
#include "`$INSTANCE_NAME`.h"
#include "`$INSTANCE_NAME`_fonts.h"

uint8 const * `$INSTANCE_NAME`_fontPtr;
int32 `$INSTANCE_NAME`_fontX;
int32 `$INSTANCE_NAME`_fontY;
int32 `$INSTANCE_NAME`_fontOffset;


// standard ascii 5x7 font
// defines ascii characters 0x20-0x7F (32-127)
const uint8 `$INSTANCE_NAME`_Font5x7[] = {
	0x00, 0x00, 0x00, 0x00, 0x00,// (space)
	0x00, 0x00, 0x5F, 0x00, 0x00,// !
	0x00, 0x07, 0x00, 0x07, 0x00,// "
	0x14, 0x7F, 0x14, 0x7F, 0x14,// #
	0x24, 0x2A, 0x7F, 0x2A, 0x12,// $
	0x23, 0x13, 0x08, 0x64, 0x62,// %
	0x36, 0x49, 0x55, 0x22, 0x50,// &
	0x00, 0x05, 0x03, 0x00, 0x00,// '
	0x00, 0x1C, 0x22, 0x41, 0x00,// (
	0x00, 0x41, 0x22, 0x1C, 0x00,// )
	0x08, 0x2A, 0x1C, 0x2A, 0x08,// *
	0x08, 0x08, 0x3E, 0x08, 0x08,// +
	0x00, 0x50, 0x30, 0x00, 0x00,// ,
	0x08, 0x08, 0x08, 0x08, 0x08,// -
	0x00, 0x60, 0x60, 0x00, 0x00,// .
	0x20, 0x10, 0x08, 0x04, 0x02,// /
	0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
	0x00, 0x42, 0x7F, 0x40, 0x00,// 1
	0x42, 0x61, 0x51, 0x49, 0x46,// 2
	0x21, 0x41, 0x45, 0x4B, 0x31,// 3
	0x18, 0x14, 0x12, 0x7F, 0x10,// 4
	0x27, 0x45, 0x45, 0x45, 0x39,// 5
	0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
	0x01, 0x71, 0x09, 0x05, 0x03,// 7
	0x36, 0x49, 0x49, 0x49, 0x36,// 8
	0x06, 0x49, 0x49, 0x29, 0x1E,// 9
	0x00, 0x36, 0x36, 0x00, 0x00,// :
	0x00, 0x56, 0x36, 0x00, 0x00,// ;
	0x00, 0x08, 0x14, 0x22, 0x41,// <
	0x14, 0x14, 0x14, 0x14, 0x14,// =
	0x41, 0x22, 0x14, 0x08, 0x00,// >
	0x02, 0x01, 0x51, 0x09, 0x06,// ?
	0x32, 0x49, 0x79, 0x41, 0x3E,// @
	0x7E, 0x11, 0x11, 0x11, 0x7E,// A
	0x7F, 0x49, 0x49, 0x49, 0x36,// B
	0x3E, 0x41, 0x41, 0x41, 0x22,// C
	0x7F, 0x41, 0x41, 0x22, 0x1C,// D
	0x7F, 0x49, 0x49, 0x49, 0x41,// E
	0x7F, 0x09, 0x09, 0x01, 0x01,// F
	0x3E, 0x41, 0x41, 0x51, 0x32,// G
	0x7F, 0x08, 0x08, 0x08, 0x7F,// H
	0x00, 0x41, 0x7F, 0x41, 0x00,// I
	0x20, 0x40, 0x41, 0x3F, 0x01,// J
	0x7F, 0x08, 0x14, 0x22, 0x41,// K
	0x7F, 0x40, 0x40, 0x40, 0x40,// L
	0x7F, 0x02, 0x04, 0x02, 0x7F,// M
	0x7F, 0x04, 0x08, 0x10, 0x7F,// N
	0x3E, 0x41, 0x41, 0x41, 0x3E,// O
	0x7F, 0x09, 0x09, 0x09, 0x06,// P
	0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
	0x7F, 0x09, 0x19, 0x29, 0x46,// R
	0x46, 0x49, 0x49, 0x49, 0x31,// S
	0x01, 0x01, 0x7F, 0x01, 0x01,// T
	0x3F, 0x40, 0x40, 0x40, 0x3F,// U
	0x1F, 0x20, 0x40, 0x20, 0x1F,// V
	0x7F, 0x20, 0x18, 0x20, 0x7F,// W
	0x63, 0x14, 0x08, 0x14, 0x63,// X
	0x03, 0x04, 0x78, 0x04, 0x03,// Y
	0x61, 0x51, 0x49, 0x45, 0x43,// Z
	0x00, 0x00, 0x7F, 0x41, 0x41,// [
	0x02, 0x04, 0x08, 0x10, 0x20,// "\"
	0x41, 0x41, 0x7F, 0x00, 0x00,// ]
	0x04, 0x02, 0x01, 0x02, 0x04,// ^
	0x40, 0x40, 0x40, 0x40, 0x40,// _
	0x00, 0x01, 0x02, 0x04, 0x00,// `
	0x20, 0x54, 0x54, 0x54, 0x78,// a
	0x7F, 0x48, 0x44, 0x44, 0x38,// b
	0x38, 0x44, 0x44, 0x44, 0x20,// c
	0x38, 0x44, 0x44, 0x48, 0x7F,// d
	0x38, 0x54, 0x54, 0x54, 0x18,// e
	0x08, 0x7E, 0x09, 0x01, 0x02,// f
	0x08, 0x14, 0x54, 0x54, 0x3C,// g
	0x7F, 0x08, 0x04, 0x04, 0x78,// h
	0x00, 0x44, 0x7D, 0x40, 0x00,// i
	0x20, 0x40, 0x44, 0x3D, 0x00,// j
	0x00, 0x7F, 0x10, 0x28, 0x44,// k
	0x00, 0x41, 0x7F, 0x40, 0x00,// l
	0x7C, 0x04, 0x18, 0x04, 0x78,// m
	0x7C, 0x08, 0x04, 0x04, 0x78,// n
	0x38, 0x44, 0x44, 0x44, 0x38,// o
	0x7C, 0x14, 0x14, 0x14, 0x08,// p
	0x08, 0x14, 0x14, 0x18, 0x7C,// q
	0x7C, 0x08, 0x04, 0x04, 0x08,// r
	0x48, 0x54, 0x54, 0x54, 0x20,// s
	0x04, 0x3F, 0x44, 0x40, 0x20,// t
	0x3C, 0x40, 0x40, 0x20, 0x7C,// u
	0x1C, 0x20, 0x40, 0x20, 0x1C,// v
	0x3C, 0x40, 0x30, 0x40, 0x3C,// w
	0x44, 0x28, 0x10, 0x28, 0x44,// x
	0x0C, 0x50, 0x50, 0x50, 0x3C,// y
	0x44, 0x64, 0x54, 0x4C, 0x44,// z
	0x00, 0x08, 0x36, 0x41, 0x00,// {
	0x00, 0x00, 0x7F, 0x00, 0x00,// |
	0x00, 0x41, 0x36, 0x08, 0x00,// }
	0x08, 0x08, 0x2A, 0x1C, 0x08,// ->
	0x08, 0x1C, 0x2A, 0x08, 0x08 // <-
};


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_SetFont
********************************************************************************
* Summary:
*   Set the specific font.  (Only one font supported at this time.)
*
* Parameters:  
*  uint32 font: Font to be selected 
*
* Return: 
*  void
*
*******************************************************************************/
void `$INSTANCE_NAME`_SetFont( uint32 font)
{
    switch(font)
    {
       case `$INSTANCE_NAME`_FONT_5X7:
           `$INSTANCE_NAME`_fontPtr = `$INSTANCE_NAME`_Font5x7;
           `$INSTANCE_NAME`_fontX = `$INSTANCE_NAME`_Font5x7_XSIZE;
           `$INSTANCE_NAME`_fontY = `$INSTANCE_NAME`_Font5x7_YSIZE;
           `$INSTANCE_NAME`_fontOffset = `$INSTANCE_NAME`_Font5x7_OFFSET;
           break;
           
       default:
           `$INSTANCE_NAME`_fontPtr = `$INSTANCE_NAME`_Font5x7;
           `$INSTANCE_NAME`_fontX = `$INSTANCE_NAME`_Font5x7_XSIZE;
           `$INSTANCE_NAME`_fontY = `$INSTANCE_NAME`_Font5x7_YSIZE;
           `$INSTANCE_NAME`_fontOffset = `$INSTANCE_NAME`_Font5x7_OFFSET;
           break;
    }
}


/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_PrintString
********************************************************************************
* Summary:
*   Print string at the given location.
*
* Parameters:  
*  uint32 xpos: X location at which to start string.
*  uint32 ypos: Upper Y location to place string.
*  char * theString:  The string to print.
*  uint32 fg: The forground fount color.
*  uint32 bg: Background color
*
* Return: 
*  void
*
*******************************************************************************/
void `$INSTANCE_NAME`_PrintString(int32 xpos, int32 ypos, char * theString, uint32 fg, uint32 bg)
{
    uint32 strPos = 0;
    uint32 y, yStop;
    #if(`$INSTANCE_NAME`_MEMORY_TYPE == `$INSTANCE_NAME`_MEMORY_RGB)
       extern uint32  `$INSTANCE_NAME`_ledArray[`$INSTANCE_NAME`_ROWS][`$INSTANCE_NAME`_COLUMNS];
    #else  /* Else use lookup table */
       extern uint8  `$INSTANCE_NAME`_ledArray[`$INSTANCE_NAME`_ROWS][`$INSTANCE_NAME`_COLUMNS];
    #endif
    
    yStop = ypos + `$INSTANCE_NAME`_fontY;
    if(yStop > `$INSTANCE_NAME`_ROWS) yStop = `$INSTANCE_NAME`_ROWS;
    
    while(theString[strPos] != 0)
    {
        if(fg == `$INSTANCE_NAME`_COLORWHEEL_FONT)
        {
            `$INSTANCE_NAME`_PutChar(xpos, ypos, theString[strPos], `$INSTANCE_NAME`_ColorInc(1), bg);
        }
        else
        {
            `$INSTANCE_NAME`_PutChar(xpos, ypos, theString[strPos], fg, bg);
        }
        strPos++;
        xpos += `$INSTANCE_NAME`_fontX;
        if(theString[strPos] != 0)
        {
            for(y = ypos; y < yStop; y++ )
            {
                if((y >= 0) && (y < `$INSTANCE_NAME`_ROWS)&& (xpos >= 0) && (xpos < `$INSTANCE_NAME`_COLUMNS) )
                   `$INSTANCE_NAME`_ledArray[y][xpos] = bg;
            }
        }
        xpos++;
    }
    `$INSTANCE_NAME`_DrawLine(xpos-1, ypos, xpos-1, ypos+`$INSTANCE_NAME`_fontY, bg);
}

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_PutChar
********************************************************************************
* Summary:
*   Print character at the given location.
*
* Parameters:  
*  uint32 xpos: X location at which to start string.
*  uint32 ypos: Upper Y location to place string.
*  char theChar:  The character to print.
*  uint32 fg: The forground fount color.
*  uint32 bg: Background color
*
* Return: 
*  void
*
*******************************************************************************/
void `$INSTANCE_NAME`_PutChar(int32 xpos, int32 ypos, uint8 theChar, uint32 fg, uint32 bg)
{
   int32 x,y, fp;
   uint8 mask;
   int32 yStop, xStop;
    #if(`$INSTANCE_NAME`_MEMORY_TYPE == `$INSTANCE_NAME`_MEMORY_RGB)
       extern uint32  `$INSTANCE_NAME`_ledArray[`$INSTANCE_NAME`_ROWS][`$INSTANCE_NAME`_COLUMNS];
    #else  /* Else use lookup table */
       extern uint8  `$INSTANCE_NAME`_ledArray[`$INSTANCE_NAME`_ROWS][`$INSTANCE_NAME`_COLUMNS];;
    #endif
   
   fp = (theChar - `$INSTANCE_NAME`_fontOffset) * `$INSTANCE_NAME`_fontX;
   
   xStop = xpos + `$INSTANCE_NAME`_fontX;
   if(xStop > `$INSTANCE_NAME`_COLUMNS) xStop = `$INSTANCE_NAME`_COLUMNS;
   
   yStop = ypos + `$INSTANCE_NAME`_fontY;
   if(yStop > `$INSTANCE_NAME`_ROWS) yStop = `$INSTANCE_NAME`_ROWS;
   
   for( x = xpos; x < xStop; x++)
   {
       mask = 0x01;
       for(y = ypos; y < yStop; y++)
       {
          if((y >= 0) && (x >= 0))
          {
              if(mask & `$INSTANCE_NAME`_fontPtr[fp])
              {
                   `$INSTANCE_NAME`_ledArray[y][x] = fg;   
              }
              else
              {
                  `$INSTANCE_NAME`_ledArray[y][x] = bg;
              }
          }
          mask = mask << 1;
       }
       fp++;
   }
}





/* [] END OF FILE */
