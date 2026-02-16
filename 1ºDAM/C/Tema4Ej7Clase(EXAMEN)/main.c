#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Tipos de datos propios
typedef struct {
  int id; // es un secuencial automático (empieza en 1)
  char nombre[40];
  int cantidad; // ventas realizadas
  float importe;  // importe acumulado de esas ventas
} empleado;

// Prototipos de funciones
int presenta_menu();
void elige_camino(int);
void recupera_ultimo_id();
void registra_empleado();
void lista_empleados();
void registra_venta();
void muestra_ventas_empleado();
int solicita_id();

// Constantes y variables globales
const char *NOMBRE_ARCHIVO_EMPLEADOS = "empleados.dat";
FILE *archivo_empleados=NULL;
const char *NOMBRE_ARCHIVO_VENTAS = "ventas.txt";
FILE *archivo_ventas=NULL;
const char *MENU_1 = "\n\n1) Registra empleado\n";
const char *MENU_2 = "2) Lista de empleados\n";
const char *MENU_3 = "3) Registra venta\n";
const char *MENU_4 = "4) Ventas de un empleado\n";
const char *MENU_0 = "0) Salir\n";
const char *ERROR_ACCESO_EMPLEADOS = "ERROR al acceder al archivo de empleados\n";
const char *ERROR_ACCESO_VENTAS = "ERROR al acceder al archivo de ventas\n";
const char* PREGUNTA_EMPLEADO="\nNombre del empleado: ";
const char * PREGUNTA_ID="\nId del empleado: ";
const char * PREGUNTA_DESCRIPCION="\nDescipción de la venta: ";
const char * PREGUNTA_IMPORTE="\nImporte de la venta: ";
const char * ERROR_ESCRITURA_EMPLEADOS="\nNo se pudo guardar el empleado";
const char * ERROR_EMPLEADO="El empleado no existe";

int ultimo_id = 0; // para saber cuál fue el último id que se asigno a alguien

//////////////////////////////// FUNCIONES ////////////////////////////////////////////
int main(void) {
  int opcion;
  recupera_ultimo_id();
  // Hasta que se elija salir, presenta el menú y elige el camino adecuado
  do {
    opcion = presenta_menu();
    elige_camino(opcion);
  } while (opcion != 0);
  return 0;
}

void recupera_ultimo_id() {
  //Es el último id almacenado en el archivo de empleados
  //Si el archivo no existe, simplemente no hacemos nada -> ultimo_id=0
  //----------------EJERCICIO 1------------------------------
    FILE* f=fopen(NOMBRE_ARCHIVO_EMPLEADOS,"rb");
    if(!f) return;

    //Nos aseguramos de que el archivo no este vacio
    fseek(f,0,SEEK_END);
    size_t longitud=ftell(f);
    if(longitud==0) return;

    //Si el archivo tiene empleados, me quedo con el id del ultimo
    fseek(f,-sizeof(empleado),SEEK_END); //Me coloco en el final del archivo y retrocedo el tamaño de un empleado porque todos los empleados ocupan lo mismo
    empleado ultimo;
    fread(&ultimo,sizeof(empleado),1,f);
    ultimo_id=ultimo.id;

    fclose(f);
}

int presenta_menu() {
  int opcion;
  printf(MENU_1);
  printf(MENU_2);
  printf(MENU_3);
  printf(MENU_4);
  printf(MENU_0);
  do {
    opcion = -1;
    scanf("%d", &opcion);
    while (getchar() != '\n');
  } while (opcion < 0 || opcion > 4);
  return opcion;
}

void elige_camino(int camino) {
  switch (camino) {
  case 1:
    registra_empleado();
    break;
  case 2:
    lista_empleados();
    break;
  case 3:
    registra_venta();
    break;
  case 4:
    muestra_ventas_empleado();
    break;
  }
}

void registra_empleado(){
  //Pide el nombre del empleado y guaŕdalo en el archivo correspondiente con:
  //el id que le corresponda (el siguiente al último), ventas 0, importe 0
  //----------------EJERCICIO 2------------------------------
    empleado nuevo={ultimo_id+1 ,"",0,0.0f};
    printf(PREGUNTA_EMPLEADO);
    scanf("%39[^\n]",nuevo.nombre);
    getchar();//Limpio el buffer con getchar porque al llegar hasta el enter solo queda enter
    FILE* f=fopen(NOMBRE_ARCHIVO_EMPLEADOS,"ab");
    if(!f){
        printf(ERROR_ACCESO_EMPLEADOS);
        return;
    }
    fseek(f,0,SEEK_END);
    if(fwrite(&nuevo,sizeof(empleado),1,f)==1){
        ultimo_id++;
    }else{
        printf(ERROR_ESCRITURA_EMPLEADOS);
    }
    fclose(f);
}

void lista_empleados(){
  //Presenta la información de los empleados como se muestra en el enunciado
  //----------------EJERCICIO 3------------------------------
    FILE* f=fopen(NOMBRE_ARCHIVO_EMPLEADOS,"rb");
    if(!f){
        printf(ERROR_ACCESO_EMPLEADOS);
        return;
    }
    empleado e;
    do{
        if(fread(&e,sizeof(empleado),1,f)==1)
            printf("\n%d - %s -> %.2f (%d ventas)",e.id,e.nombre,e.importe,e.cantidad);
    }while(!feof(f));
    fclose(f);
}

void registra_venta(){
  //Pide el nombre los datos de la venta:
  //  - id (a través de la función solicita_id)
  //  - descripción
  //  - importe
  //Añade una línea con esos datos al archivo de ventas (es un archivo de texto)
  //Modifica el bloque del archivo de empleados (es un archivo binario) correspondiente
  // a ese id para que tenga en cuenta los datos de la venta realizada
  //----------------EJERCICIO 4------------------------------
    int id=solicita_id();
    char descripcion[100];
    float importe;
    printf(PREGUNTA_DESCRIPCION);
    scanf("%[^\n]",descripcion);
    getchar();
    printf(PREGUNTA_IMPORTE);
    scanf("%f",&importe);
    while(getchar()!='\n');

    //Abrimos los dos archivos
    archivo_ventas=fopen(NOMBRE_ARCHIVO_VENTAS,"a");
    if(!archivo_ventas){
        printf(ERROR_ACCESO_VENTAS);
        return;
    }
    archivo_empleados=fopen(NOMBRE_ARCHIVO_EMPLEADOS,"rb+");
    if(!archivo_empleados){
        printf(ERROR_ACCESO_EMPLEADOS);
        fclose(archivo_ventas);
        return;
    }

    //Me guardo los datos originales de ese empleado (por si hay errores luego)
    fseek(archivo_empleados,0,SEEK_SET);
    empleado original;
    bool encontrado=false;
    do{
        fread(&original,sizeof(empleado),1,archivo_empleados);
        if(original.id==id){
                encontrado=true;
            break;
        }
    }while(!feof(archivo_empleados));
    if(!encontrado){
        printf(ERROR_EMPLEADO);
        return;
    }

    //Actualizo los datos del empleado con la nueva venta
    empleado nuevo=original;
    nuevo.cantidad++;
    nuevo.importe+=importe;
    fseek(archivo_empleados,-sizeof(empleado),SEEK_CUR);//estaba al final de ese empleado
    if(fwrite(&nuevo,sizeof(empleado),1,archivo_empleados)!=1){
        printf(ERROR_ESCRITURA_EMPLEADOS);
        return;
    }
    //Registro la venta en su archivo (si falla,restauro los datos originales del empleado)
    fseek(archivo_ventas,0,SEEK_END);

    if(ftell(archivo_ventas)>0){
        fprintf(archivo_ventas,"\n");
    }
    if(fprintf(archivo_ventas,"%d;%s;%.2f",id,descripcion,importe)<0){
        //Hay que deshacer lo que hicimos en empleados
        fseek(archivo_empleados,-sizeof(empleado),SEEK_CUR);
        fwrite(&original,sizeof(empleado),1,archivo_empleados);
    }
    //Cierro los dos archivos
    fclose(archivo_empleados);
    fclose(archivo_ventas);
}

void muestra_ventas_empleado(){
  //Pide el id (a través de la función solicita_id)
  //Recupera los datos de ese empleado del archivo correspondiente y
  // preséntalos por pantalla como se muestra en el enunciado
  //Recupera las ventas de ese empleado del archivo correspondiente y
  // preséntalas por pantalla como se muestra en el enunciado
  //----------------EJERCICIO 5------------------------------
    int id_solicitado=solicita_id();
    int id;
    char descripcion[100];
    float importe;
    archivo_ventas=fopen(NOMBRE_ARCHIVO_VENTAS,"r");
    if(!archivo_ventas){
        printf(ERROR_ACCESO_VENTAS);
        return;
    }

    do{
        fscanf(archivo_ventas,"%d;%[^%];%f\n",&id,descripcion,&importe);
        if(id==id_solicitado){
            printf("\n\t%s %.2f€",descripcion,importe);
        }
    }while(!feof(archivo_ventas));

    fclose(archivo_ventas);
}

int solicita_id(){
    int id;
    do{
        printf(PREGUNTA_ID);
        scanf("%d",&id);
        while(getchar()!='\n');
    }while(id<1 || id>ultimo_id);
    return id;
}
