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

#define NULL 0


int DIGIT_ASCII_CODES[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};


unsigned int X_INDEX;
//Tamano del buffer
#define BUFSIZE 2200


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
    VGA_COLOR_DARK_GREY,
    VGA_COLOR_LIGHT_BLUE,
    VGA_COLOR_LIGHT_GREEN,
    VGA_COLOR_LIGHT_CYAN,
    VGA_COLOR_LIGHT_RED,
    VGA_COLOR_LIGHT_MAGENTA,
    VGA_COLOR_YELLOW,
    VGA_COLOR_WHITE,
};

//Eje Y
unsigned int Y_INDEX = 1;
UINT16 MEM_SIZE = 0;


static UINT16 VGA_DefaultEntry(unsigned char to_print) {
	return (UINT16) to_print | (UINT16)VGA_COLOR_WHITE << 8; //Se devuelve el char en pantalla con color blanco
}

static UINT16 VGA_ColoredEntry(unsigned char to_print, UINT8 color) {
	return (UINT16) to_print | (UINT16)color << 8; //Se devuelve el char en pantalla con el color vga que se entregue
}


void ClearVGA(UINT16 **buffer)
{
  for(int i=0;i<BUFSIZE;i++){
    (*buffer)[i] = '\0';  //Agrega un caracter vacio en cada espacio
  }
  Y_INDEX = 1; //Regresa los ejes a 1 y 0
  X_INDEX = 0;
}


void InitTerminal()
{
  TERMINAL_BUFFER = (UINT16*) VGA_ADDRESS; //Declara el buffer de "terminal" en la direccion del vga, esto permite imprimir los caracteres
  ClearVGA(&TERMINAL_BUFFER); //Se borra la pantalla
}


UINT8 IN_B(UINT16 port)
{
  UINT8 ret;
  asm volatile("inb %1, %0" :"=a"(ret) :"Nd"(port) );
  return ret;
}


#endif
