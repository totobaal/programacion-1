#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int body[200][2];
int h=1;
int score = 0;
int tam = 15;
int x = 10, y = 12;
int dir=3;
int ch;
int ya=20 , xb=20;
void guardar_posicion(){
	body[h][0] = x;
	body[h][1] = y;
	h ++;
	if(h == tam) h = 1;
	}
	
void pintar_body(){
    for (int i =1; i<tam;i++){
	mvprintw(body[i][1], body[i][0], "o"); 	
		}
    	
}	

void borrar_body(){
	   
	mvprintw(body[h][1], body[h][0], " "); 	
		
}

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

void puntos(){
	mvprintw(30,27,"SCORE 00000");

}

void mov_snake(){
	
	  switch( ch ) {
        case KEY_UP: 
        if( dir != 2)  
         dir = 1;
        break;
        case KEY_DOWN:
          if(dir !=1)
          dir = 2;
        break;
        case KEY_RIGHT: 
        if(dir != 4)
        dir=3; 
        break;
        case KEY_LEFT: 
        if(dir !=3)
        dir=4; 
        break;
    }
	}

void comida(){
	srand(time(NULL));
    if(x == xb && y == ya){
	ya = ((rand()%28)+2);
	xb = ((rand()%68)+2);
	
	tam++;
	mvprintw(ya,xb,"X");
  
  }
}

bool fin(){
	if(x == 0 || x==70 ||y==0 ||y==30)	
	return true;
				
else 
return false;
}

int main()
{

	int N = 30;
	int M = 70;
  
    
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);     
    noecho();
    pantalla(N,M);
   	mvprintw(ya,xb,"X");
    while (1 && !fin())
    {
	
	
        puntos();
        borrar_body();
        guardar_posicion();
        pintar_body();
        comida();
		timeout(100);   
        ch = getch();
        mov_snake();
        
    if( dir == 1) y--;
    if( dir == 2) y++;
    if( dir == 3) x++;
    if( dir == 4) x--;   
        refresh();
    }
    
    endwin();         
    return 0;
}

