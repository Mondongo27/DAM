#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ALTO 5
#define ANCHO 11
#define CANT_MINAS 10

void inicializar();
void mostrar();
void pedir();
void calcular();

//constantes globales
const int fila_inicio=ALTO-1;
const int col_inicio=ANCHO/2;
const int col_fin=col_inicio;
const int fila_fin=0;
int fila_jugador;
int col_jugador;
bool muerto=false;
bool victoria=false;
const char* COLOR_JUGADOR="\033[105;30m";
const char* COLOR_SALIDA="\033[102;30m";
const char* COLOR_VISITADA="\033[106;30m";
const char* COLOR_IGNOTA="\033[47;30m";
const char* COLOR_DEFECTO="\033[0m";
const char* Preguntar="\nMueve: ";
const char* MENSAJE_DERROTA="\nHas pisado una mina";
const char* MENSAJE_VICTORIA="\nHas ganado";

//ARRAYS
bool mina[ALTO][ANCHO];
int cantidad[ALTO][ANCHO];
bool visitada[ALTO][ANCHO];

int main()
{
   inicializar();
   do{
        mostrar();
        if(muerto){
            printf(MENSAJE_DERROTA);
            break;
        }else if(victoria){
            printf(MENSAJE_VICTORIA);
            break;
        }
        pedir();
        calcular();

   }while(true);
    return 0;
}
void mostrar(){
        for(int i=0;i<ALTO;i++) {
            printf("\n");
            for(int j=0;j<ANCHO;j++) {
            //si he visitado la celda la pongo de su color
            if(visitada[i][j]) printf(COLOR_VISITADA);
            else printf(COLOR_IGNOTA);
            //si es la celda del jugador la pongo de su color
            if(i==fila_jugador && j==col_jugador)printf(COLOR_JUGADOR);
            //si es la celda de salida, la pongo de su color
            if(i==fila_fin && j==col_fin) printf(COLOR_SALIDA);
            if(visitada[i][j]==true){
                if(i==fila_jugador && j==col_jugador){
                  printf(COLOR_JUGADOR);
                  if(muerto)printf("#");
                  else if(victoria)printf("V");
                  else printf("%d",cantidad[i][j]);
                }else{
                    printf("%d",cantidad[i][j]);
                }
            }else{
                printf(" ");
            }
            }
            printf(COLOR_DEFECTO);
        }
}

void pedir(){
    char respuesta=' ';
    do{
        printf(Preguntar);
        scanf("%c",&respuesta);
        while(getchar()!='\n');

        switch(respuesta){
            case 'w':
                if(fila_jugador>0)
                fila_jugador--;
                break;
            case 's':
                if(fila_jugador<ALTO-1)
                fila_jugador++;
                break;
            case 'a':
                if(col_jugador>0)
                col_jugador--;
                break;
            case 'd':
                if(col_jugador<ANCHO-1)
                col_jugador++;
                break;
        }
    }while(respuesta!='w' && respuesta!='a' && respuesta!='s' && respuesta!='d');

}

void inicializar(){
    srand(time(NULL));
    int minas_colocadas=0;
    int f,c;

    //ninguna celda ha sido visitada todavia
    for(int i=0;i<ALTO;i++){
        for(int j=0;j<ANCHO;j++){
            visitada[i][j]=false;
        }
    }
    //salvo la posicion de inicio
    fila_jugador=fila_inicio;
    col_jugador=col_inicio;
    visitada[fila_jugador][col_jugador]=true;

   //limpiamos campo de minas
        for(int i=0;i<ALTO;i++){
        for(int j=0;j<ANCHO;j++){
            mina[i][j]=false;
        }
    }
        //limpiar cantidades

        for(int i=0;i<ALTO;i++){
            for(int j=0;j<ANCHO;j++){
                cantidad[i][j]=0;
            }
        }
    //Colocamos las minas
    do{
        f=rand()%ALTO;
        c=rand()%ANCHO;
        if(mina[f][c]==false
        && !(f==fila_inicio&&c==col_inicio)
        &&!(f==fila_fin&&c==col_fin)){
            mina[f][c]=true;
            minas_colocadas++;
            //cuando coloco una mina debo ajustar cantidades
            for(int i=f-1;i<=f+1;i++){
                for(int j=c-1;j<=c+1;j++){
                    if(i<0 || i>=ALTO || j<0 || j>=ANCHO ||( f==i && j==c)) continue;
                    cantidad[i][j]++;
                }
            }
        }
    }while(minas_colocadas<CANT_MINAS);
}

void calcular(){
    visitada[fila_jugador][col_jugador]=true;
    if(mina[fila_jugador][col_jugador]==true){
       muerto=true;
    }else if(fila_jugador==fila_fin && col_jugador==col_fin){
        victoria=true;
    }
}
