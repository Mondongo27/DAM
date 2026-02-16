#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
# define ANCHO 20
# define ALTO 20

void inicializar();
void mostrar();
void pedir();
void detonar(int,int);
bool hay_bomba(int,int);
void espera(double);

const char* TEXTO_CELDA="\n\nDame la fila y columna de la bomba a detonar: ";
const int TOTAL_BOMBAS=20;
const int RANGO_MIN_BOMBA=2;
const int RANGO_MAX_BOMBA=5;
int terreno[ALTO][ANCHO];
int fila,columna;

int main()
{
    srand(time(NULL));

    inicializar();
    do{
        mostrar();
        pedir();
        detonar(fila,columna);
    }while(true);

    return 0;
}

void inicializar(){
    int bombas_colocadas=0;
    //Declaro el terreno y lo "limpio"
    for(int i=0;i<ALTO;i++) for(int j=0;j<ANCHO;j++) terreno[i][j]=0;
    //Colocar bombas
    do{
        int fila=rand()%ALTO;
        int columna=rand()%ANCHO;
        if(terreno[fila][columna]==0){
            terreno[fila][columna]=rand()%(RANGO_MAX_BOMBA-RANGO_MIN_BOMBA+1)+RANGO_MIN_BOMBA;
            bombas_colocadas++;
        }
    }while(bombas_colocadas<TOTAL_BOMBAS);
}

void mostrar(){
    system("cls");
    //Cabeceras de columnas
    printf("\n    ");
    for(int j=0;j<ANCHO;j++){
        printf("%d ",j+1);
        if(j<9) printf(" ");
    }
    for(int i=0;i<ALTO;i++){
        //Cabeceras de las filas
        printf("\n%d ",i+1);
        if(i<9) printf(" ");
        //Contenido de la fila
        for(int j=0;j<ANCHO;j++){
            if(terreno[i][j]==0){
                printf(" . ");
            }else if(terreno[i][j]==-1){
                printf(" # ");
            }else{
                printf(" %d ",terreno[i][j]);
            }
        }
    }
    espera(0.1);
}

void pedir(){
    do{
        printf(TEXTO_CELDA);
        fila=-1;columna=-1;
        scanf("%d%d",&fila,&columna);
        while(getchar()!='\n');
        fila--;columna--;//para usar como índices del array
    }while(fila<0 || fila>=ALTO ||columna<0 || columna>=ANCHO
           ||(!hay_bomba(fila,columna)));
    //Si he llegado aqui es porque la entrada del usuario es VÁLIDA
    //Y fila columna son índices válidos de una bomba del array
}

bool hay_bomba(int fila,int columna){
    return (terreno[fila][columna]>=RANGO_MIN_BOMBA
           &&terreno[fila][columna]<=RANGO_MAX_BOMBA);
}

void detonar(int fila,int columna){
    int rango=terreno[fila][columna];
    //Exploto la bomba
    terreno[fila][columna]=-1;
    mostrar();
    //printf("(%d,%d)",fila,columna);
    //Onda expansiva
    printf("\n");
    for(int n=0;n<rango;n++){
        if((columna+n)<ANCHO){
            if(hay_bomba(fila,columna+n)){
                detonar(fila,columna+n);
            }else{
                if(terreno[fila][columna+n]!=-1);
                terreno[fila][columna+n]=-1;
                mostrar();
                //printf("(%d,%d)",fila,columna+n);
            }
        }
        if((columna-n)>=0){
            if(hay_bomba(fila,columna-n)){
                detonar(fila,columna-n);
            }else{
                if(terreno[fila][columna-n]!=-1);
                terreno[fila][columna-n]=-1;
                mostrar();
                //printf("(%d,%d)",fila,columna-n);
            }
        }
        if((fila-n)>=0){
            if(hay_bomba(fila-n,columna)){
                detonar(fila-n,columna);
            }else{
                if(terreno[fila-n][columna]!=-1);
                terreno[fila-n][columna]=-1;
                mostrar();
                //printf("(%d,%d)",fila-n,columna);
            }
        }
        if((fila+n)<ALTO){
            if(hay_bomba(fila+n,columna)){
                detonar(fila+n,columna);
            }else{
                if(terreno[fila+n][columna]!=-1);
                terreno[fila+n][columna]=-1;
                mostrar();
                //printf("(%d,%d)",fila+n,columna);
        }
    }
//    //Propago explosión a la derecha
//    for(int j=0;j<rango;j++){
//            if((columna+j)>=ANCHO) break;
//        terreno[fila][columna+j]=-1;
//    }
//    //Propago explosión a la izquierda
//    for(int j=0;j<rango;j++){
//            if((columna-j)<0) break;
//        terreno[fila][columna-j]=-1;
//    }
//    //Propago hacia abajo
//    for(int i=0;i<rango;i++){
//            if((fila+i)>=ALTO) break;
//        terreno[fila+i][columna]=-1;
//    }
//    //Propago hacia arriba
//    for(int i=0;i<rango;i++){
//            if((fila-i)<0) break;
//        terreno[fila-i][columna]=-1;
//    }

    }
}

void espera(double rato){
    clock_t inicio,ahora;
    double transcurrido;
    inicio=clock();
    do{
        ahora=clock();
        transcurrido=(double)(ahora-inicio)/CLOCKS_PER_SEC;
        if(transcurrido>=rato) break;
    }while(true);
}
