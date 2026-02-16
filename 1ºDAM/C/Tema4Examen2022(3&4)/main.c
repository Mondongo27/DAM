#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LADO 8
#define CANTIDAD_COLORES 4

typedef struct{
  int movimientos;
  int celdas[LADO*LADO];
}info;

void pide_datos(int*,int*,int*);
void pide_nombre();
void construye_tablero();
void recupera_tablero();
void pinta_tablero();
void terminar();
int inserta_tablero();
void inserta_nombre(int);
void actualiza_tablero();
void serializa_tablero(int*);
void deserializa_tablero(int*);
void colorea(int,int,int);
int recupera_indice();

const char* ARCHIVO_NOMBRES="nombres.txt";
const char* ARCHIVO_TABLEROS="tableros.bin";
const char* PREGUNTA_NOMBRE="\nDime tu nombre: ";
const char* PREGUNTA_SEGUIR="%s, quieres seguir con tu tablero guardado? (s/otracosa) ";
const char* PREGUNTA_GUARDAR="Quieres guardar el tablero? (s/otracosa) ";
const char* ERROR_LECTURA_TABLEROS="\nERROR: no se ha podido leer el archivo %s";
const char* ERROR_GUARDAR_DATOS="\nERROR: no se han podido guardar los datos";
const char COLORES[CANTIDAD_COLORES][8]={"\033[40m","\033[43m","\033[46m","\033[47m"};
const char* NORMAL="\033[0m";
const char* PREGUNTA_COLOR="\nElige un color: ";
const char* PREGUNTA_FILA="\nElige una fila: ";
const char* PREGUNTA_COLUMNA="\nElige una columna: ";
const char* TEXTO_MOVIMIENTOS="\nMovimientos: %i";

int tablero[LADO][LADO];
char nombre[20];
int movimientos=0;
int indice_nombre;// >0: nº asociado a ese nombre en el archivo. =0: nombre nuevo
int reutilizar;//indica si el usuario quiere recuperar sus datos antiguos o empezar de nuevo

int main(void) {
  int tinta,columna,fila;//el color que vamos a "volcar" y la fila y columna en que lo volcamos.
  srand(time(NULL));
  pide_nombre();
  construye_tablero();
  do{
    pinta_tablero();

    ////////////////////////////////  INICIO EJERCICIO 1a  //////////////////////////
    //Llama a la función 'pide_datos' para recuperar 'color','x' e 'y' que elija el usuario
    //Este ejercicio tiene una segunda parte: ve a la definición de pide_datos
    int color,x,y;
    pide_datos(&color,&y,&x);
    ////////////////////////////////  FIN EJERCICIO 1a  //////////////////////////

    if(tinta==-1){
      terminar();
      break;
    }else{
      movimientos++;
    ////////////////////////////////  INICIO EJERCICIO 2a  //////////////////////////
    //Llama a la función 'colorea' usando el 'color', la 'x' y la 'y' que eligió el usuario
    //Complétalo con el ejercicio 2b que se pide a continuación
      colorea(color,x,y);
    ////////////////////////////////  FIN EJERCICIO 2a  //////////////////////////
    }
  }while(1);
  return 0;
}

////////////////////////////////  INICIO EJERCICIO 2b  //////////////////////////
//Crea desde cero la función 'colorea'
void colorea(int color,int y,int x){
    tablero[y][x]=color;
}
////////////////////////////////  FIN EJERCICIO 2b  //////////////////////////


void pide_nombre(){
  char confirmacion;
  //Pedimos el nombre, restringiéndonos a menos de 20 caracteres
  printf(PREGUNTA_NOMBRE);
  scanf("%s",nombre);
  while(getchar()!='\n');
  nombre[19]='\0';//Por si acaso
  //Capturamos el índice de la partida asociada a ese jugador (si ya ha jugado antes)
  indice_nombre=recupera_indice();
  if(indice_nombre>0){
    //Si ya tiene un tablero, le preguntamos si quiere seguir con él o empezar de nuevo
    printf(PREGUNTA_SEGUIR,nombre);
    scanf("%c",&confirmacion);
    if(confirmacion=='s' || confirmacion=='S') reutilizar=1;
    else reutilizar=0;
  }else{
    reutilizar=0;
  }
}

////////////////////////////////  INICIO EJERCICIO 3  //////////////////////////
//Crea desde cero la función 'recupera_indice'
int recupera_indice(){
    char recuperado_prov[20];
    int indice_prov;

    FILE* f=fopen(ARCHIVO_NOMBRES,"r");
    if(!f) return 0;

    do{
        fscanf(f,"%[^;];%d",recuperado_prov,&indice_prov);
        if(strcmp(recuperado_prov,nombre)==0) return indice_prov;
    }while(!feof(f));

    fclose(f);
    return 0;
}
////////////////////////////////  FIN EJERCICIO 3  //////////////////////////

void construye_tablero(){
  if(reutilizar==0){//Se monta desde cero
    for(int i=0;i<LADO;i++){
      for(int j=0;j<LADO;j++){
        tablero[i][j]=rand()%CANTIDAD_COLORES;
      }
    }
  }else{
    recupera_tablero();
  }
}

void recupera_tablero(){
////////////////////////////////  INICIO EJERCICIO 4  //////////////////////////
//Construye el cuerpo de la función 'recupera_tablero'
    FILE* f=fopen(ARCHIVO_TABLEROS,"rb");
    if(!f){
        printf(ERROR_LECTURA_TABLEROS);
        return;
    }

    info i;
    fseek(f,(indice_nombre-1)*sizeof(info),SEEK_SET);
    if((fread(&i,sizeof(info),1,f))!=1){
        printf(ERROR_LECTURA_TABLEROS);
        return;
    }

    deserializa_tablero(i.celdas);

    fclose(f);
////////////////////////////////  FIN EJERCICIO 4  //////////////////////////
}

void pinta_tablero(){
  //system("clear");
  //Cabecera
  printf("\n            ");
  for(int i=10;i<LADO;i++) printf("%i",i/10);
  printf("\n  ");
  for(int i=0;i<LADO;i++){
    if(i<10) printf("%i",i);
    else printf("%i",i%10);
  }
  //Las líneas de la tabla
  for(int i=0;i<LADO;i++){
    printf("\n");
    if(i<10) printf(" %i",i);
    else printf("%i",i);
    for(int j=0;j<LADO;j++){
      printf("%s%c",COLORES[tablero[i][j]],' ');
    }
    printf(NORMAL);
  }
  printf(TEXTO_MOVIMIENTOS,movimientos);
}

////////////////////////////////  INICIO EJERCICIO 1b  //////////////////////////
//Completa la definición de la función 'pide_datos'
void pide_datos(int* color,int* y,int* x){
////////////////////////////////  FIN EJERCICIO 1b  //////////////////////////
  //Primero pide el color, e insiste hasta que elija uno válido
  do{
    printf(PREGUNTA_COLOR);
    for(int i=0;i<CANTIDAD_COLORES;i++){
      printf("%i->%s %s   ",i,COLORES[i],NORMAL);
    }
    printf("-1->Salir\n");
    scanf("%i",color);
    while(getchar()!='\n');
  }while(*color<-1 || *color>=CANTIDAD_COLORES);
  if(*color==-1) return;//Si quiere salir no sigo preguntando
  //Luego las coordenadas de la celda hasta que ponga unas válidas
  do{
    printf(PREGUNTA_FILA);
    scanf("%i",y);
    while(getchar()!='\n');
  }while(*y<0 || *y>=LADO);
  do{
    printf(PREGUNTA_COLUMNA);
    scanf("%i",x);
    while(getchar()!='\n');
  }while(*x<0 || *x>=LADO);
}

void terminar(){
  //Se encarga de guardar los datos (si el usuario quiere) para que usarlos posteriormente
  char confirmacion;
  int numero_tablero;
  printf(PREGUNTA_GUARDAR);
  scanf("%c",&confirmacion);
  if(confirmacion=='s' || confirmacion=='S'){
    //Si ya existe el nombre, sólo hay que actualizar el tablero
    if(indice_nombre){
      actualiza_tablero();
    }else{//Si no existe, hay que añadir la información del tablero y del nombre
      numero_tablero=inserta_tablero();
      if(numero_tablero)
        inserta_nombre(numero_tablero);
    }
  }
}

int inserta_tablero(){
  //Devuelve: 0, si falla. En cc, la posición que ocupa el tablero en el archivo (empezando en 1)
  int resultado;
  info datos;
  FILE* archivo=fopen(ARCHIVO_TABLEROS,"ab");
  if(archivo==NULL){
    printf(ERROR_GUARDAR_DATOS);
    resultado=0;
  }else{
    datos.movimientos=movimientos;
    serializa_tablero(datos.celdas);
    fwrite(&datos, sizeof(info), 1,archivo);
    resultado=ftell(archivo)/sizeof(info);
    fclose(archivo);
  }
  return resultado;
}

void inserta_nombre(int indice){
////////////////////////////////  INICIO EJERCICIO 6  //////////////////////////
//Construye el cuerpo de la función 'actualiza_tablero'
//...
////////////////////////////////  FIN EJERCICIO 6  //////////////////////////
}

void actualiza_tablero(){
////////////////////////////////  INICIO EJERCICIO 5  //////////////////////////
//Construye el cuerpo de la función 'actualiza_tablero'
//...
////////////////////////////////  FIN EJERCICIO 5  //////////////////////////
}

void serializa_tablero(int* destino){
  for(int i=0;i<LADO;i++){
    for(int j=0;j<LADO;j++){
      destino[i*LADO+j]=tablero[i][j];
    }
  }
}

void deserializa_tablero(int* origen){
  for(int i=0;i<LADO;i++){
    for(int j=0;j<LADO;j++){
      tablero[i][j]=origen[i*LADO+j];
    }
  }
}

