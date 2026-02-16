#include <stdio.h>
#define MAX 100
#define LONG 10
// Prototipos
char mostrar_menu();
void insertar_palabra();
void mostrar_lista();
//Constantes y variables globales
const char* CABECERA_MENU="\n--- Menú ---\n";
const char* OPCION_A="a) Añadir palabra\n";
const char* OPCION_B="b) Mostrar lista de palabras\n";
const char* OPCION_Z="z) Salir\n";
const char* MENSAJE_SALIENDO="Saliendo del programa...\n";
const char* MENSAJE_OPCION_NO_VALIDA="Opción no válida.\n";
const char* ERROR_LISTA_LLENA="Error: la lista está llena.\n";
const char* PREGUNTA_PALABRA="Dime una palabra (long.max. %d): ";
const char* MENSAJE_LISTA_VACIA="La lista está vacía.\n";
//Para almacenar las palabras
char lista[MAX][LONG];
int contador=0;

int main(){
    char opcion;

    //Quiero mostrar por pantalla la cadena "%9s"
    printf("%%%ds",LONG-1);
    printf("\n..................................");

    do{
        opcion=mostrar_menu();
        switch (opcion) {
            case 'a':
                insertar_palabra();
            break;
            case 'b':
                mostrar_lista();
            break;
            case 'z':
                printf(MENSAJE_SALIENDO);
            break;
            default:
                printf(MENSAJE_OPCION_NO_VALIDA);
            break;
        }
    }while (opcion != 'z');
 return 0;
}

char mostrar_menu() {
 char opcion;
 printf(CABECERA_MENU);
 printf(OPCION_A);
 printf(OPCION_B);
 printf(OPCION_Z);
 scanf("%c", &opcion);
 while(getchar()!='\n');
 return opcion;
}

void insertar_palabra(){
    if(contador>=MAX){
        printf(ERROR_LISTA_LLENA);
        return;
    }
    char palabra[LONG];
    printf(PREGUNTA_PALABRA,LONG-1);
    char formato[7];//="%9s"
    sprintf(formato,"%%%ds",LONG-1);
    scanf(formato,palabra);
    while(getchar()!='\n');
    //Insertar palabra en el array
    for(int i=0;i<LONG;i++){
        lista[contador][i]=palabra[i];
    }
    //Contabilizo
    contador++;
}

void mostrar_lista(){
    if(contador==0){
        printf(MENSAJE_LISTA_VACIA);
    }else{
        for(int i=0;i<contador;i++)printf("\n%s",lista[i]);
    }
}
