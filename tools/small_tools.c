#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "env.h"


struct _curser_pos CurserPos={1,1};

#ifdef __linux__

  #include <ncurses.h>

  void draw(const char *str, ...){
    va_list args;
    va_start(args,str);

    move(CurserPos.row,CurserPos.col);
    while(*str){//récupère les arguments
      if(*str=='%'){
        str++;
        if(*str=='d'){
          int val=va_arg(args,int);
          printw("%d",val);
        }else if(*str=='f'){
          char val=va_arg(args,double);
          printw("%c",val);
        }else if(*str=='s'){
          char* val=va_arg(args,char*);
          printw("%s",val);
        }
      }else{
        printw("%c",*str);
      }
      str++;
    }

    va_end(args);
  }

  void init(){
    initscr();
    refresh();
    endwin();
    draw("Hello World\n");
  }

  int getKey(){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    int key=getch();
    endwin();
    return key;
  }

#else
  
  #include <conio.h>
  #include <windows.h>

  void draw(const char* str, ...){
    va_list args;
    va_start(args,str);
    COORD coord;
    coord.X=CurserPos.col;
    coord.Y=CurserPos.row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    
    while(*str){//récupère les arguments
      if(*str=='%'){
        str++;
        if(*str=='d'){
          int val=va_arg(args,int);
          printf("%d",val);
        }else if(*str=='f'){
          char val=va_arg(args,double);
          printf("%c",val);
        }else if(*str=='s'){
          char* val=va_arg(args,char*);
          printf("%s",val);
        }
      }else{
        printf("%c",*str);
      }
      str++;
    }

    va_end(args);
  }

  void init(){
    system("cls");
    draw("Hello World\n");
  }

  int getKey(){
    return _getch();
  }

#endif