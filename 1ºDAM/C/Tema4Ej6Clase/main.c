#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char palabra[25];
    int longitud;
}Paquete;

void transformar();
void comprobar();
bool trastocar(int,char);


int main(){
    //transformar();
    //comprobar();
    printf("\n%d",trastocar(3,'X'));
    comprobar();
}

void comprobar(){
    FILE* origen=fopen("diccionario.dat","rb");
    if(!origen){
        printf("\nERROR al abrir el archivo de binario");
        exit (-1);
    }

    fseek(origen,0,SEEK_END);
    int cantidad=ftell(origen)/sizeof(Paquete);
    Paquete lista[cantidad];
    fseek(origen,0,SEEK_SET);
    fread(lista,sizeof(Paquete),cantidad,origen);
    for(int i=0;i<cantidad;i++){
        printf("\n%s - %d",lista[i].palabra,lista[i].longitud);
    }

    fclose(origen);
}

void transformar(){
    Paquete paquete;
    //Apertura de archivos
    FILE* origen=fopen("diccionario.txt","r");
    if(!origen){
        printf("\nERROR al abrir el archivo de origen");
        exit (-1);
    }

    FILE* destino=fopen("diccionario.dat","wb");
    if(!destino){
        printf("\nERROR al abrir el archivo de destino");
        fclose(origen);
        exit (-1);
    }
    //Procesamiento
    int contador=0;
    do{
        fscanf(origen,"%s\n",paquete.palabra);
        paquete.longitud=strlen(paquete.palabra);
        fwrite(&paquete,sizeof(Paquete),1,destino);
        contador++;
    }while(!feof(origen));
    printf("\nContador: %d",contador);
    //Cierre
    fclose(origen);
    fclose(destino);
}

bool trastocar(int posicion, char letra){
    Paquete paquete;
    //cambia la primera letra de la palabra en esa posicion por la letra que me dan
    if(posicion<0) return false;
    FILE* archivo=fopen("diccionario.dat","rb+");
    if(!archivo){
        printf("\nERROR al abrir el archivo de binario");
        return false;
    }
    //Determino cuantos apquetes hay en el archivo
    fseek(archivo,0,SEEK_END);
    int cantidad=ftell(archivo)/sizeof(Paquete);
    //Compruebo que la posicion sea valida (el primero es el paquete 0)
    if(posicion>=cantidad) return false;
    //Me coloco al inicio del paquete deseado
    fseek(archivo,posicion*sizeof(Paquete),SEEK_SET);
    //Hago una lectura
    fread(&paquete,sizeof(Paquete),1,archivo);
    //Modifico el contenido
    paquete.palabra[0]=letra;
    //Actualizo el archivo
    fseek(archivo,-sizeof(Paquete),SEEK_CUR);
    fwrite(&paquete,sizeof(Paquete),1,archivo);

    fclose(archivo);
    return true;
}
