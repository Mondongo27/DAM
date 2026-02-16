#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int preguntar_cantidad();
int hacer_preguntas(int);
void mostrar_resultado(int,int);

const char* PREGUNTA_CUANTAS="\nDime cuantas preguntas quieres responder: ";
const char* CUESTION="\n%d.  %d %c %d = ";
const char* MENSAJE_ACIERTO=" Good boy\n";
const char* MENSAJE_ERROR=" Mal (%d)\n";
const char* MENSAJE_PUNTOS="\nAciertos: %d -> %d puntos ";
const char* MENSAJE_ERRORES="\nErrores: %d -> %.1f puntos ";
const char* MENSAJE_FINAL="\nPuntuacion: %.1f/%d -> %s";
const char* CADENA_APTO="APTO";
const char* CADENA_NOAPTO="NO APTO";


int main()
{
    srand(time(NULL));
    int cantidad=preguntar_cantidad();
    int aciertos=hacer_preguntas(cantidad);
    mostrar_resultado(cantidad,aciertos);
    return 0;
}




//FUNCIONES:

int preguntar_cantidad(){
    int cantidad=0;
    while(cantidad<=0){
        printf(PREGUNTA_CUANTAS);
        scanf("%d", &cantidad);
        while(getchar()!='\n');
    }
    return cantidad;
}

int hacer_preguntas(int cant){
    int primero,segundo,operacion;
    char simbolo;
    int solucion;
    int respuesta;
    int aciertos=0;
    for(int i=1;i<=cant;i++){
        primero=rand()%11;
        segundo=rand()%11;
        operacion=rand()%3;//0 suma, 1 resta, 2 multiplicacion
        if(operacion==0){
            simbolo='+';
            solucion=primero+segundo;
        }else if(operacion==1){
            simbolo='-';
            if(segundo>primero){
                int auxiliar=segundo;
                segundo=primero;
                primero=auxiliar;
            }
            solucion=primero-segundo;
        }else{
            simbolo='*';
            solucion=primero*segundo;
        }

        do{
            respuesta=-1;
            printf(CUESTION,i,primero,simbolo,segundo);
            scanf("%d", &respuesta);
            while(getchar()!='\n');
        }while(respuesta<0);
        if(respuesta==solucion){
            printf(MENSAJE_ACIERTO);
            aciertos++;
        }else{
            printf(MENSAJE_ERROR, solucion);
        }
    }
    return aciertos;
}

void mostrar_resultado(int cantidad,int aciertos){
    int errores=cantidad-aciertos;
    float puntos=aciertos-errores/2.0f;
    float limite=cantidad/2.0f;
    printf(MENSAJE_PUNTOS,aciertos,aciertos);
    printf(MENSAJE_ERRORES,errores,errores/2.0f);
    printf(MENSAJE_FINAL,puntos,cantidad,puntos>=limite? CADENA_APTO : CADENA_NOAPTO);
}
