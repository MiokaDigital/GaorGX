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
#include "librerias/funcionesp.h"
#include "librerias/teclado.h"
#include "librerias/pantalla.h"

void Intro() //Max de pantalla = 80
{
  printColored_WCharN(2481,79,VGA_COLOR_BLUE, VGA_COLOR_LIGHT_RED);
  printNewLine();
  printColored_WCharN(2483,79,VGA_COLOR_BLUE, VGA_COLOR_LIGHT_GREEN);
  printN_NewLine(4);
  X_INDEX += 27;
  printColoredString("Sistema Operativo Gaorg OS",VGA_COLOR_BLUE, VGA_COLOR_WHITE);
  printN_NewLine(6);
  X_INDEX += 22;
  printColoredString("Kernel echo en c (Hybrid 16/32 bits)",VGA_COLOR_LIGHT_GREY, VGA_COLOR_DARK_GREY);
  printN_NewLine(6);
  X_INDEX += 30;
  printColoredString("Pulsa la tecla ENTER",VGA_COLOR_WHITE, VGA_COLOR_RED);
  printN_NewLine(6);
  printColored_WCharN(2483,79,VGA_COLOR_BLUE, VGA_COLOR_LIGHT_GREEN);
  printNewLine();
  printColored_WCharN(2481,79,VGA_COLOR_BLUE, VGA_COLOR_LIGHT_RED);
  PasarEn(28);
  ClearVGA(&TERMINAL_BUFFER);
}


void PruebaEscribir() 
{
printColoredString("Prueba de video -:- by Gabriel Gomez", VGA_COLOR_WHITE, VGA_COLOR_LIGHT_GREEN);
escribir();
}

void KERNEL_MAIN()
{
  disable_cursor();
  InitTerminal();
  Intro();
  disable_blink();
  PruebaEscribir();

} 

