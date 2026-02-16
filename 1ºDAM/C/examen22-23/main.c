#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int decide_dados();
void jugar_partida(int);
bool procesar_ronda(int);

const char *COMIENZO ="Vamos a jugar con %i DADO%c";
const char* PREGUNTA_DADOS="¿Cuántos dados usamos? (1->11p, 2->21p, 3->31p): ";
const int TOPE1 = 11;
const int TOPE2 = 21;
const int TOPE3 = 31;
int tope;
const int LIMITE1=8;
const int LIMITE2=15;
const int LIMITE3=21;
int limite;
const char* TEXTO_BANCA = "\n\nPuntos de la banca: %d";
const char* TEXTO_JUGADOR = "\nPuntos del jugador: %d";
const char* TURNO_BANCA = "\n\nTurno para la banca: ";
const char* TURNO_JUGADOR = "\nTurno para el jugador: ";
const char* PREGUNTA_PLANTARSE ="\n\n¿Quieres plantarte?(p/P sí. Otra cosa no): ";
const char* NADIE_GANA = "¡NADIE GANA!";
const char* JUGADOR_GANA = "¡VICTORIA PARA EL JUGADOR!";
const char* BANCA_GANA = "¡VICTORIA PARA LA BANCA!";
const char* FIN = "--- Fin de la partida ---";
int puntos_banca = 0;
int puntos_jugador = 0;
//int dado;
//int tirada_actual;
//int banca_plantada = 0;
//int jugador_plantado = 0;
//char opcion_jugador;


int main()
{
    srand(time(NULL));
    int dados=decide_dados();
    jugar_partida(dados);
    //resultado();
    return 0;
}

int decide_dados(){
    int respuesta=1;
    printf(PREGUNTA_DADOS);
    scanf("%d",&respuesta);
    while(getchar()!='\n');
    if (respuesta<1 || respuesta>3) respuesta=1;
    printf(COMIENZO,respuesta,respuesta>1?'S':' ');
    return respuesta;
}

void jugar_partida(int dados){
    int tope;
    int limite;
    switch(dados){
    case 1:
        tope=11;
        limite=8;
        break;
    case 2:
        tope=21;
        limite=15;
        break;
    case 3:
        tope=31;
        limite=21;
    }
    //Pasamos a jugar
    do{
        bool procesar_ronda(int dados);
    }while(true);
}

bool procesar_ronda(int dados){
    int dado;
    char plantarme;
    printf(TURNO_BANCA);
    for(int i=1;i<=dados;i++){
        dado=rand()%6+1;
        puntos_banca+=dado;
        printf("%d", dado);
    }
    printf(TURNO_JUGADOR);
    for(int i=1;i<=dados;i++){
        dado=rand()%6+1;
        puntos_banca+=dado;
        printf("%d", dado);
    }
    printf(TEXTO_BANCA,puntos_banca);
    printf(TEXTO_JUGADOR,puntos_jugador);
    printf(PREGUNTA_PLANTARSE);
    scanf("%c",&plantarme);
    while(getchar()!='\n');
    if(plantarme=='p'||plantarme=='P')return true;
    return false;
}
