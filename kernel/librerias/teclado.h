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
#include "funcionesp.h"
#include "pantalla.h"
char PasarEn(int busco) {
  char ch = 0;
  do{
    if(IN_B(0x60) == busco) { //Si el valor es igual al que buscamos
      ch = IN_B(0x60);   //Se copia en ch y se devuelve el valor
      if(ch > 0)
        return ch;
    }
  }while(1);
}

//Keymap estadounidense con los valores por defecto del teclado
unsigned char keymap[128]=
{
	0,27,'1','2','3','4','5','6','7','8','9','0','-','=', '\b',
	'\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',
	0, /* Ctrl */
	'a','s','d','f','g','h','j','k','l',';',
	'\'','`',0, /* Left Shift */
	'\\','z','x','c','v','b','n','m',',','.','/', 0,/* Right shift */
	'*', 0, /* Alt */
	' ',
	0, /* Caps lock*/
	0,0,0,0,0,0,0,0,0,0, /* F1-F10 keys */
	0, /* Num lock */
	0, /* Scroll lock */
	0, /* Home key */
	0, /* Up arrow */
	0, /* Page up */
	'-',
	0, /* Left arrow */
	0,
	0, /* Right arrow */
	'+',
	0, /* End key */
	0, /* Down arrow */
	0, /* Page down */
	0, /* Insert key */
	0, /* Delete key */
	0,0,0,
	0, 0, /* F11-F12 Keys */
	0
};

char escanear(unsigned char ch){

if(IN_B(0X60) != ch){
ch = IN_B(0x60);  //Si el valor es el distinto al que ya tiene, se copia
ch = keymap[ch]; //Despues se pasa por el keymap, para saber que letra es
return ch; //Y se devuelve la letra
}return 0;}

char escribir() {
unsigned char letra = 0;
unsigned char respaldo = 0;
  do{
    if(IN_B(0x60) != respaldo) { //Si el valor es distinto al anterior
      letra = IN_B(0x60); //Se copia el valor en letra para pasarlo despues
      respaldo = letra;  //Se respalda el valor actual, para el proximo loop
      

      if(letra != 0 && letra < 128){ //Si el valor es distinto a 0 y menor a 128(maximo del keymap)
      letra = keymap[letra];//Se pasa por el keymap


      if(letra == '\n') { //Si la tecla es enter, imprime una linea
      printNewLine();
      }
      else if(letra == '\b'){ //Si es tecla de retroceso, se regresa y imprime caracteres vacios
      X_INDEX--;
      printChar('\0');
      X_INDEX--;
      }
      else if(letra != 0){ //Si es otro valor (distinto a 0, ya que son las teclas de funciones, se imprime la letra
      printChar(letra); 
      }


    }  
    }
}while(1);
}
