// comentario demuestra cambios
#include <ncurses.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
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
	
		
  mvprintw(y,x,"oooo");
}

void comida(){
	srand(time(NULL));
	int a,b;
	a = ((rand())%30)+1;
	b = ((rand())%70)+1;
	mvprintw(a,b,"x");
}

int main()
{
    int x = 10;
    int y = 10;
    int N = 30;
    int M = 70;
    int ch; 
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);     
    noecho(); 
	comida();
    while (1)
    {
	
	    pantalla(N,M); 
        serpiente(y,x);
        
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
}  
