#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define ANCHO 15 //dimensiones del mundo
#define ALTO 10
#define NUM_HIEDRAS 4 //cantidad de HIEDRAs que vamos a colocar
#define TAM_MIN_HIEDRA 2 //tama�o m�nimo de los HIEDRAs
#define TAM_MAX_HIEDRA 4 //tama�o m�ximo de los HIEDRAs
#define NUM_OGROS 3 //cantidad de ogros que vamos a colocar
#define DIST_OGRO 5 // espacio m�nimo inicial entre ogro y jugador
#define ALCANCE_OGRO 3 // distancia a la que te ven los ogros
#define NUM_MONEDAS 3 //cantidad de monedas que vamos a colocar

//Prototipos
void iniciar_partida();
void planta_hiedra();
void coloca_jugador();
void coloca_ogro(int);
void coloca_moneda();
void mostrar_salida();
void leer_entrada();
void procesar();
void propaga_activacion(int,int);
void mover_ogro(int);

//Constantes globales
const char* MUESTRA_MONEDAS="\n(%d monedas)";
const char* PIDE_MOVIMIENTO="\nMueve: ";
const int TIPO_TIERRA=0;
const int TIPO_HIEDRA=1;
const int TIPO_OGRO=2;
const int TIPO_JUGADOR=3;
const int TIPO_MONEDA=4;
const int TIPO_JUGADOR_MUERTO=5;
const int TIPO_HIEDRA_ACTIVA=6;
const char ASPECTO[7]={
    ' ', // representaci�n gr�fica de tierra
    ' ', // representaci�n gr�fica de hiedra
    'O', // representaci�n gr�fica de ogro
    '@', // representaci�n gr�fica de jugador
    '$', // representaci�n gr�fica de moneda
    '@', // representaci�n gr�fica de jugador muerto
    ' ' // representaci�n gr�fica de hiedra activa
    };
const char COLOR[7][12]={
    "\033[43m", // color(es) de la tierra
    "\033[42m", // color(es) de la hiedra
    "\033[43;95m",  // color(es) de los ogros
    "\033[43;30m", // color(es) del jugador
    "\033[43;93m", // color(es) de las monedas
    "\033[41;30m", // color(es) del jugador muerto
    "\033[41m" // color(es) de la hiedra activa
    };
const char* FORMATO_DEFECTO="\033[0m";

//Variables globales
int xjugador, yjugador;//La nueva posici�n del jugador
int xanterior, yanterior;//La anterior posici�n del jugador
int mundo[ALTO][ANCHO];//Este es el terreno de juego. @EJERCICIO_1 - INICIO Y FIN
int ogros[NUM_OGROS][2];//para cada ogro, guardamos fila y columna
int monedas=0;
bool vivo=true;
bool turno_ogros=false;


int main(){
    srand(time(NULL));
    iniciar_partida();
    do{
        mostrar_salida();
        leer_entrada();
        procesar();
    }while(vivo);
    mostrar_salida();
    return 0;
}

void iniciar_partida(){
    //Limpio el terreno de juego de todo ser viviente
    //@EJERCICIO_2 - INICIO
    for(int i=0;i<ALTO;i++){
        for(int j=0;j<ANCHO;j++){
            mundo[i][j]=TIPO_TIERRA;
        }
    }
    monedas=0;
    vivo=true;
    turno_ogros=false;
    //@EJERCICIO_2 - FIN

    //Coloco los elementos para la partida
    for(int n=1;n<=NUM_HIEDRAS;n++){
        planta_hiedra();
    }
    coloca_jugador();
    for(int n=0;n<NUM_OGROS;n++){
        coloca_ogro(n);
    }
    for(int n=0;n<NUM_MONEDAS;n++){
        coloca_moneda();
    }
}

void coloca_moneda(){
    //@EJERCICIO_6 - INICIO
    int cant_moneda=0;
    int c,f;
    do{
        do{
            c=rand()%ANCHO;
            f=rand()%ALTO;
        }while(mundo[f][c]!=TIPO_TIERRA);
        mundo[f][c]=TIPO_MONEDA;
        cant_moneda++;
    }while(cant_moneda<NUM_MONEDAS);
    //@EJERCICIO_6 - FIN
}

void coloca_ogro(int n){
    //@EJERCICIO_5 - INICIO
    int j, i;
    do{
        j=rand()%ANCHO;
        i=rand()%ALTO;
    }while(mundo[i][j]!=TIPO_TIERRA||
            (abs(j-xjugador)+abs(i-yjugador)< DIST_OGRO));
    mundo[i][j]=TIPO_OGRO;
    ogros[n][0]=i;
    ogros[n][1]=j;
    //@EJERCICIO_5 - FIN
}

void coloca_jugador(){
    //@EJERCICIO_4 - INICIO
    do{
        xjugador=rand()%ANCHO;
        yjugador=rand()%ALTO;
    }while(mundo[yjugador][xjugador]==TIPO_HIEDRA);
    mundo[yjugador][xjugador]=TIPO_JUGADOR;
    //@EJERCICIO_4 - FIN
}

void planta_hiedra(){
    //@EJERCICIO_3 - INICIO
    int tam=TAM_MIN_HIEDRA+rand()%(TAM_MAX_HIEDRA-TAM_MIN_HIEDRA+1);
    int max_j=ANCHO-tam-1;
    int max_i=ALTO-tam-1;
    if(max_j<1)max_j=1;
    if(max_i<1)max_i=1;
    int j=1+rand()%(max_j-1+1);
    int j_min=1;
    int j_max=ANCHO-tam-1;
    int i_min=1;
    int i_max=ALTO-tam-1;
    if(j_max<j_min)j_max=j_min;
    if(i_max<i_min)i_max=i_min;
    j=j_min+rand()%(j_max-j_min+1);
    int i=i_min+rand()%(i_max-i_min+1);

    for(int k=0;k<tam;k++){
        for(int l=0;l<tam;l++){
            mundo[i+k][j+l]=TIPO_HIEDRA;
        }
    }
    //@EJERCICIO_3 - FIN
}

void mostrar_salida(){
    system("cls");//system("clear")
    //@EJERCICIO_7 - INICIO
    for (int i=0;i<ALTO;i++){
        for (int j=0;j<ANCHO;j++){
            int tipo=mundo[i][j];
            printf("%s%c%s", COLOR[tipo], ASPECTO[tipo], FORMATO_DEFECTO);
        }
        printf("\n");
    }

    printf(MUESTRA_MONEDAS, monedas);
    printf("\n");
    //@EJERCICIO_7 - FIN
}

void leer_entrada(){
    char direccion=' ';//direcci�n en la que decide moverse el jugador
	bool direccion_valida=false;//para no salirme del terreno
	//Me guarfo la posici�n
	xanterior=xjugador;
	yanterior=yjugador;
	//Pido movimiento y calculo la nueva
    while(!direccion_valida){
        printf(PIDE_MOVIMIENTO,monedas);
        scanf("\n%c",&direccion);
        while(getchar()!='\n');
        switch(direccion){
        case 'w':
            if(yjugador>0){
                yjugador--;
                direccion_valida=true;
            }
            break;
        case 's':
            if(yjugador<ALTO-1){
                yjugador++;
                direccion_valida=true;
            }
            break;
        case 'a':
            if(xjugador>0){
                xjugador--;
                direccion_valida=true;
            }
            break;
        case 'd':
            if(xjugador<ANCHO-1){
                xjugador++;
                direccion_valida=true;
            }
            break;
        }
    }
}

void procesar(){
    //@EJERCICIO_8 - INICIO

    //@EJERCICIO_8 - FIN

    //Mover a los ogros SI LES TOCA. Se mueven a una de las 8 celdas adyacentes
    if(turno_ogros){
        for(int n=0;n<NUM_OGROS;n++){
            mover_ogro(n);
            if(ogros[n][0]==yjugador && ogros[n][1]==xjugador){
                mundo[yjugador][xjugador]=TIPO_JUGADOR_MUERTO;
                vivo=false;
                break;
            }
        }
    }
    //Los ogros se mueven un turno s� y otro no. Son lentos de reflejos
    turno_ogros=!turno_ogros;
}

void propaga_activacion(int fila, int col){
    //@EJERCICIO_9 - INICIO

    //@EJERCICIO_9 - FIN

}
void mover_ogro(int n){
    int xogro=ogros[n][1];
    int yogro=ogros[n][0];

    //Si la vista del ogro no capta al jugador, no se mueve
    if(abs(yogro-yjugador)>ALCANCE_OGRO || abs(xogro-xjugador)>ALCANCE_OGRO) return;

    //Le ha captado -> calculamos la celda a la que se mover�a
    int xnueva=xogro;
    int ynueva=yogro;
    if(xogro<xjugador) xnueva++;
    else if(xogro>xjugador) xnueva--;
    if(yogro<yjugador) ynueva++;
    else if(yogro>yjugador) ynueva--;

    //El ogro s�lo puede moverse a una celda vac�a o a la celda del jugador
    if(mundo[ynueva][xnueva]==TIPO_TIERRA || mundo[ynueva][xnueva]==TIPO_JUGADOR){
        mundo[yogro][xogro]=TIPO_TIERRA;
        mundo[ynueva][xnueva]=TIPO_OGRO;
        ogros[n][0]=ynueva;
        ogros[n][1]=xnueva;
    }
}
