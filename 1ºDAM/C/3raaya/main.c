#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mostrar_estado();
void leer_entradas();
void procesar_entradas();

const char* CABECERA_COLUMNAS="\n    a  b  c";
const char* PIDE_CELDAS=" \n\nJugador %d introduce celda : \n> ";
const char* TABLAS="\nPartida en TABLAS";
const char* GANADOR="\nHa ganado el jugador %d";
const char SIMBOLOS[3]={' ','X','O'};
int tablero[3][3]={
    {0,0,0},
    {0,0,0},
    {0,0,0}};
int turno=1;
char fila;
char columna;
int ganador=-1;
int fichascolocadas=0;

int main()
{
   do{
            system("cls");
            mostrar_estado();
            leer_entradas();
            procesar_entradas();
            turno=(turno==1)?2:1;
   }while(ganador<0);
   mostrar_estado();
   if (ganador==0){
        printf(TABLAS);
   }else{
       printf(GANADOR,ganador);
       }
    return 0;
}

void mostrar_estado(){
    printf(CABECERA_COLUMNAS);
    for(int i=0;i<3;i++){
        printf("\n%d  ", i+1);
        printf("\033[107m");
        for(int j=0;j<3;j++) {
         printf("%s",tablero[i][j]==1?"\033[31m":"\033[30m");
         printf(" %c ",SIMBOLOS[tablero[i][j]]);
    }
    printf("\033[0m");
}
}
void leer_entradas(){
    char f,c;
    do{
        printf(PIDE_CELDAS, turno);
        scanf("%c%c", &c, &f);
        while(getchar()!='\n');
    fila=f-'1';
    columna=c-'a';
    }while(c<'a'||c>'c'||f<'1'||f>'3'||tablero[fila][columna]!=0);
}
void procesar_entradas(){
    tablero[fila][columna]=turno;
    fichascolocadas++;
    if(fichascolocadas<5) return;
    //Compruebo la fila en la que he colocado la ficha
    //Las demás no, porque no han cambiado
    if((tablero[fila][0]==tablero[fila][1])
       && (tablero[fila][0]==tablero[fila][2])){
        ganador=turno;
        return;
       }
    //Compruebo la columna en la que he colocado la ficha
    //Las demás no, porque no han cambiado
    if((tablero[0][columna]==tablero[1][columna])
       && (tablero[0][columna]==tablero[2][columna])){
        ganador=turno;
        return;
       }
    //Diagonal principal
    if(fila==columna){
        if((tablero[0][0]==tablero[1][1])
            && (tablero[0][0]==tablero[2][2])){
            ganador=turno;
            return;
        }
    }
    if(fila+columna==2){
        if((tablero[0][2]==tablero[1][1])
            && (tablero[0][2]==tablero[2][0])){
            ganador=turno;
            return;
        }
    }
    if(fichascolocadas==9){
        ganador=0;
        return;
    }
}
