#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define LONG_DICC 955
#define TAM_PALABRA 16

void elegir_palabra();
void presentar();
char leer_entrada();
void procesar(char);
void borra_pista();
const char* PAT_1="\n_______";
const char* PAT_2="\n |  |";
const char* PAT_3="\n |  %c";
const char* PAT_4="\n | %c%c%c";
const char* PAT_5="\n | %c %c";
const char* PAT_6="\n |  ";
const char* PAT_7="\n |  ";
const char SIMBOLO_CABEZA='O';
const char SIMBOLO_TRONCO='|';
const char SIMBOLO_BRAZO_DER='/';
const char SIMBOLO_BRAZO_IZQ='\\';
const char SIMBOLO_PIERNA_DER='/';
const char SIMBOLO_PIERNA_IZQ='\\';
const char* PETICION_LETRA="\n\nDame una letra: ";
const int FALLOS_MAX=6;
const char HUECO='_';
const char* MENSAJE_PIERDES="\n ¡¡¡HAS PERDIDO!!! (la palabra era '%s')";
const char* MENSAJE_GANAS="\n ¡¡¡TE HAS SALVADO!!!";

char oculta[TAM_PALABRA];
int longitud;//la longitud efectiva (nº de letras) de la palabra "oculta"
int fallos=0;
int aciertos=0;
char pista[TAM_PALABRA];//La que se muestre bajo el patíbulo como _ _ a _ _ s_


int main(){
    srand(time(NULL));
    elegir_palabra();
    borra_pista();
    do{
        presentar();
        char letra=leer_entrada();
        procesar(letra);
    }while(fallos<FALLOS_MAX && aciertos<longitud);
    presentar();
    if(fallos<FALLOS_MAX) printf(MENSAJE_GANAS);
    else printf(MENSAJE_PIERDES,oculta);
    return 0;
}

void elegir_palabra(){
    longitud=0;
    int indice=rand()%(LONG_DICC+1);

    FILE* f=fopen("diccionario.txt","r");
    if(f==NULL) return;

    for(int i=1;i<indice;i++){
            //fgets(oculta,TAM_PALABRA,f);  No vale porque incluye el enter
            fscanf(f,"%[^\n]\n",oculta);

    }
    longitud=strlen(oculta);
    fclose(f);
}

void borra_pista(){
    for(int i=0;i<longitud;i++){
        pista[i]=HUECO;
    }
    pista[longitud]='\0';
}

void presentar(){
    char cabeza, tronco,bd,bi,pd,pi;
    cabeza=tronco=bd=bi=pd=pi=' ';
    if(fallos>=1) cabeza=SIMBOLO_CABEZA;
    if(fallos>=2) tronco=SIMBOLO_TRONCO;
    if(fallos>=3) bd=SIMBOLO_BRAZO_DER;
    if(fallos>=4) bi=SIMBOLO_BRAZO_IZQ;
    if(fallos>=5) pd=SIMBOLO_PIERNA_DER;
    if(fallos>=6) pi=SIMBOLO_PIERNA_IZQ;
    system("cls");//clear en linux
    printf(PAT_1);
    printf(PAT_2);
    printf(PAT_3,cabeza);
    printf(PAT_4,bd,tronco,bi);
    printf(PAT_5,pd,pi);
    printf(PAT_6);
    printf(PAT_7);
    //printf("%s",oculta);
    printf("\n");
    printf("\n");
    for(int i=0;i<longitud;i++) printf(" %c",pista[i]);
}

char leer_entrada(){
    char letra;
    printf(PETICION_LETRA);
    scanf("%c",&letra);
    while(getchar()!='\n');
    return letra;
}

void procesar(char letra){
    bool coincidencia=false;
    for(int i=0;i<longitud;i++){
        if(oculta[i]==letra){
            coincidencia =true;
            if(!(pista[i]==letra)) aciertos++;
            pista[i]=letra;
        }
    }
    if(!coincidencia) fallos++;
}
