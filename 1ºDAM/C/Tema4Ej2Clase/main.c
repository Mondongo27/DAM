#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LONG_NOMBRE 20
#define LONG_DIR 40
#define LONG_NIF 10

typedef struct{
    char nombre[LONG_NOMBRE];
    int edad;
    char dir[LONG_DIR];
    char nif[LONG_NIF];
}Cliente;

bool recupera();
bool guarda();
void pedir_cliente(Cliente*);
void muestra_cliente(Cliente);

const char* NOMBRE_ARCHIVO="clientes.txt";
const char* ERROR_ARCHIVO="\nError al acceder al archivo";
const char* ERROR_MEMORIA="\nError al reservar espacio";

int main(){
    //guarda();
    recupera();
    return 0;
}

bool recupera(){
    FILE* f=fopen(NOMBRE_ARCHIVO,"r");
    if(f==NULL){
        printf(ERROR_ARCHIVO);
        return false;
    }

    Cliente* clientes = malloc(sizeof(Cliente));
    if(!clientes){
        printf(ERROR_MEMORIA);
        return false;
    }
    int contador=0;
    Cliente nuevo;
    do{
        int lecturas = fscanf(f,"%[^;];%d;%[^;];%[^\n]\n",nuevo.nombre,&nuevo.edad,nuevo.dir,nuevo.nif);
        if(lecturas==4){
            Cliente* puntero=clientes+contador;
            strcpy(puntero->nombre,nuevo.nombre);
            puntero->edad=nuevo.edad;
            strcpy(puntero->dir,nuevo.dir);
            strcpy(puntero->nif,nuevo.nif);
            contador++;
            Cliente* temporal = realloc(clientes,sizeof(Cliente)*(contador+1));
            if(!temporal){
                printf(ERROR_MEMORIA);
                return false;
            }
            clientes=temporal;
        }
    }while(!feof(f));
    fclose(f);

    for(int i=0;i<contador;i++) muestra_cliente(clientes[i]);

    free(clientes);
    return true;
}

void muestra_cliente(Cliente nuevo){
    printf("\n%s",nuevo.nombre);
    printf(" - %d",nuevo.edad);
    printf(" - %s",nuevo.dir);
    printf(" - %s",nuevo.nif);
}

bool guarda(){
    Cliente cliente;

    FILE* f=fopen(NOMBRE_ARCHIVO,"a");
    if(f==NULL){
        printf(ERROR_ARCHIVO);
        return false;
    }


    for(int i=0;i<3;i++){
        pedir_cliente(&cliente);
        //Si el archivo tiene datos -> salto de linea
        fseek(f,0,SEEK_END);                //Coloca en el final
        int cantidad = ftell(f);            //A cuanto esta el curso del principio
        if(cantidad>0) fputc('\n',f);       //Si esta a 0 el archivo esta vacio asi que no pone salto de linea
        fprintf(f,"%s;%d;%s;%s",cliente.nombre,cliente.edad,cliente.dir,cliente.nif);
    }

    fclose(f);
    return true;
}

void pedir_cliente(Cliente* nuevo){
    printf("\nDame el nombre: ");
    scanf("%[^\n]",nuevo->nombre);
    getchar();
    printf("\nDame la edad: ");
    scanf("%d",&(nuevo->edad));
    while(getchar()!='\n');
    printf("\nDame la direccion: ");
    scanf("%[^\n]",nuevo->dir);
    getchar();
    printf("\nDame el nif: ");
    scanf("%[^\n]",nuevo->nif);
    getchar();
}
