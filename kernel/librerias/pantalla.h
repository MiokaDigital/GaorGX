#ifndef _SCREEN_H_
#define _SCREEN_H_
#include "funcionesp.h"
int strlen(const char* str)
{
  int length = 0;
  while(str[length])
    length++;
  return length;
}

void strcat(char *str_1, char *str_2)
{
  int index_1 = strlen(str_1);
  int index_2 = 0;
  while(str_2[index_2]){
    str_1[index_1] = str_2[index_2];
    index_1++;
    index_2++;
  }
  str_1[index_1] = '\0';
}


void memcpy(char *str_dest, char *str_src)
{
  int index = 0;
  while(str_src[index]){
    str_dest[index] = str_src[index];
    index++;
  }
  str_dest[index] = '\0';
}


int digitCount(int num)
{
  int count = 0;
  if(num == 0)
    return 1;
  while(num > 0){
    count++;
    num = num/10;
  }
  return count;
}


void itoa(int num, char *number)
{
  int digit_count = digitCount(num);
  int index = digit_count - 1;
  char x;
  if(num == 0 && digit_count == 1){
    number[0] = '0';
    number[1] = '\0';
  }else{
    while(num != 0){
      x = num % 10;
      number[index] = x + '0';
      index--;
      num = num / 10;
    }
    number[digit_count] = '\0';
  }
}



void printCharN(char ch, int n)
{
  int i = 0;
  while(i <= n){
    TERMINAL_BUFFER[X_INDEX] = VGA_DefaultEntry(ch);
    i++;
    X_INDEX++;
  }
}


void borrarlineaU(int y){
Y_INDEX = y;
X_INDEX = X_INDEX - 79;
printCharN(' ',79);
X_INDEX = 0;
Y_INDEX--;
}

void printNewLine()
{
  if(Y_INDEX >= 25){
    borrarlineaU(Y_INDEX);
  }
  X_INDEX = 80*Y_INDEX;
  Y_INDEX++;
}


void printN_NewLine(int n)
{
  for(int i=0;i<n;i++)
    printNewLine();
}

void printChar(char ch)
{
    TERMINAL_BUFFER[X_INDEX] = VGA_DefaultEntry(ch);
    if(X_INDEX >= Y_INDEX*80) {
    printNewLine(); 
    }
    X_INDEX++;
}



void printString(char *str)
{
  int index = 0;
  while(str[index]){
    TERMINAL_BUFFER[X_INDEX] = VGA_DefaultEntry(str[index]);
    index++;
    X_INDEX++;
    if(X_INDEX >= 80) {
    printNewLine(); 
    }
  }
}

void printInt(int num)
{
  char str_num[digitCount(num)+1];
  itoa(num, str_num);
  printString(str_num);
}

void printColoredString(char *str, UINT8 colorF, UINT8 colorS)
{
  int index = 0;
  while(str[index]){
    TERMINAL_BUFFER[X_INDEX] = VGA_ColoredEntry(str[index], colorF, colorS);
    index++;
    X_INDEX++;
  }
}


void printColoredCharN(char ch, int n, UINT8 colorF, UINT8 colorS)
{
  int i = 0;
  while(i <= n){
    TERMINAL_BUFFER[X_INDEX] = VGA_ColoredEntry(ch, colorF, colorS);
    i++;
    X_INDEX++;
  }
}


void printColored_WCharN(UINT16 ch, int n, UINT8 colorF, UINT8 colorS)
{
  int i = 0;
  while(i <= n){
    TERMINAL_BUFFER[X_INDEX] = VGA_ColoredEntry(ch, colorF, colorS);
    i++;
    X_INDEX++;
  }
}

#endif
