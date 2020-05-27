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
  printColored_WCharN(2481,79,VGA_COLOR_RED);
  printNewLine();
  printColored_WCharN(2483,79,VGA_COLOR_LIGHT_GREEN);
  printN_NewLine(4);
  X_INDEX += 27;
  printColoredString("Sistema Operativo Gaorg OS", VGA_COLOR_YELLOW);
  printN_NewLine(6);
  X_INDEX += 22;
  printColoredString("Kernel echo en c (Hybrid 16/32 bits)", VGA_COLOR_WHITE);
  printN_NewLine(6);
  X_INDEX += 30;
  printColoredString("Pulsa la tecla de 'Q'", VGA_COLOR_BROWN);
  printN_NewLine(6);
  printColored_WCharN(2483,79, VGA_COLOR_LIGHT_GREEN);
  printNewLine();
  printColored_WCharN(2481,79, VGA_COLOR_RED);
  PasarEn(16);
  ClearVGA(&TERMINAL_BUFFER);
}

void PruebaEscribir() 
{
printNewLine();
escribir();
}

void KERNEL_MAIN()
{
  InitTerminal();
  Intro();
  
  PruebaEscribir();

} 

