#include <ncurses.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void pantalla(int N, int M){
	for(int i=0;i<N;i++)//filas
        {
			 move(i,0);
			 addch(ACS_CKBOARD);
			 move(i,M);
			 addch(ACS_CKBOARD); 
		}
	for(int j=0;j<M;j++){
	   //move(fila,columna)
	   //move(y,x)
	   move(0,j);
	   addch(ACS_CKBOARD);
	   move(N,j+1);
	   addch(ACS_CKBOARD);
	}
mvprintw(0,30,"Snaaaake !");
}

void serpiente(int y, int x){

  mvprintw(y,x,"oooooooo");
  
}

void comida(int a, int b){
	mvprintw(a,b,"X");
}

void gen_comida(int& a, int& b){
	srand(time(NULL));
	
	a = ((rand())%30)+1;
	b = ((rand())%70)+1;
    comida(a,b);	
}

void score(int N, int M){
	mvprintw(30,27,"SCORE 00000");
	
}

int main()
{
    int x = 10;
    int y = 10;
    int N = 30;
    int M = 70;
    int ch;
    int op; 
 cout<<"==================="<<endl;
 cout<<"   MENU DE SNAKE   "<<endl;
 cout<<"==================="<<endl;
 cout<<"                   "<<endl; 
 cout<<"1. Jugar"<<endl;
 cout<<"2. Salir"<<endl;
 cin>>op;
  switch(op){
	  
	  case 1:
  
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);     
    noecho();
    
    int a,b;
	
	gen_comida(a,b);
		
    while (1)
    {
	    pantalla(N,M); 
        comida(a,b);
        serpiente(y,x);
        score(N,M);
       
        // verificar que serpiente comio, y generar comida otra vez
        ch = getch();
        if (ch == KEY_DOWN)
        {
            y++;
            clear();
        }
        if (ch == KEY_UP)
        {
            y--;
            clear();
		}
        if (ch == KEY_LEFT)
        {
            x--;
            clear();
        }
        if (ch == KEY_RIGHT)
        {
            x++;
            clear();
        }
 
	refresh();
	  }
    endwin(); 

    return 0;
    break;
    case 2: 
    return 0;
    break;
}  
}
