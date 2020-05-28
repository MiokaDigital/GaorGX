/*
   Creador: Gabriel Gomez
  
    This file is part of GAORG OS.

    GAORG OS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    GAORG OSis distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef _KERNEL_H_
#define _KERNEL_H_

#define VGA_ADDRESS 0xB8000
//Se definen los types de UINT8 Y UINT16
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
#define NULL 0



UINT8 IN_B(UINT16 port)
{
  UINT8 ret;
  asm volatile("inb %1, %0" :"=a"(ret) :"Nd"(port) );
  return ret;
}
UINT8 OUT_B(UINT16 port, UINT8 value)
{
	asm volatile("outb %1, %0" : : "dN"(port), "a"(value));
        return 0;
}

int DIGIT_ASCII_CODES[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

//Tamano del buffer
#define BUFSIZE 2200

//=====================================================

UINT16* TERMINAL_BUFFER;
//16 Colores de VGA
enum vga_color {
    VGA_COLOR_BLACK,
    VGA_COLOR_BLUE,
    VGA_COLOR_GREEN,
    VGA_COLOR_CYAN,
    VGA_COLOR_RED,
    VGA_COLOR_MAGENTA,
    VGA_COLOR_BROWN,
    VGA_COLOR_LIGHT_GREY,
    VGA_COLOR_DARK_GREY,   /*Para cambiar el fondo: A partir de dark_grey cambia a modo parpadeo, y vuelve a los colores de arriba. Ej: LIGHT_RED contando a partir de DARK_GREY seria el numero 4, por lo que en pantalla se veria el color RED (4) parpadeando*/
    VGA_COLOR_LIGHT_BLUE,
    VGA_COLOR_LIGHT_GREEN,
    VGA_COLOR_LIGHT_CYAN,
    VGA_COLOR_LIGHT_RED,
    VGA_COLOR_LIGHT_MAGENTA,
    VGA_COLOR_YELLOW,
    VGA_COLOR_WHITE,
};


//Eje Y
UINT32 Y_INDEX = 1;
//Eje X
UINT32 X_INDEX;
UINT16 MEM_SIZE = 0;

//Declaro el color del fondo y el de los caracteres
UINT8 c_fondo = VGA_COLOR_WHITE, c_superior = VGA_COLOR_BLACK;

/*
16 Bits en elementos de buffer para video (AX)
--===================================--

8 Bits en AL :
  8 bits : Caracter (En ASCII)
---------------------------------------
8 Bits en AH : 
  higher 4 Bits - Color de fondo
  lower 4 Bits - Color superior

*/


static UINT16 VGA_DefaultEntry(unsigned char ch) {
  UINT16 ax = 0;
  UINT8 ah = 0, al = 0;

  ah = c_fondo;
  ah <<= 4;
  ah |= c_superior;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

static UINT16 VGA_ColoredEntry(unsigned char ch, UINT8 colorF, UINT8 colorS) {
  UINT16 ax = 0;
  UINT8 ah = 0, al = 0;

  ah = colorF;
  ah <<= 4;
  ah |= colorS;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

void disable_cursor( ) 
{ 
	OUT_B( 0x3D4 ,  0x0A ) ; 
	OUT_B( 0x3D5 ,  0x20 ) ; 
}
void disable_blink( )
{
        IN_B(0x03DA);
        OUT_B(0x03C0, 0x30);
        IN_B(0x3C1);
        OUT_B(0x3C0, 0xF7);
}


//=====================================================

void ClearVGA(UINT16 **buffer)
{
  for(int i=0;i<BUFSIZE;i++){
    (*buffer)[i] = VGA_DefaultEntry('\0');  //Agrega un caracter vacio en cada espacio
  }
  Y_INDEX = 1; //Regresa los ejes a 0
  X_INDEX = 0;
}


void InitTerminal()
{
  TERMINAL_BUFFER = (UINT16*) VGA_ADDRESS; //Declara el buffer de "terminal" para la posicion de vga
  ClearVGA(&TERMINAL_BUFFER); //Se borra la pantalla
}
//=====================================================

#endif
