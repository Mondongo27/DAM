#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variables globales
int intentos = 5;
int cifra1=1, cifra2=2, cifra3=3, cifra4=4;

const char* menu = "1) Especificar intentos\n2) Generar nuevo pin\n3) Acceder\n0) Salir\n>";
const char* preguntar_intentos = "Numero de intentos permitidos (2-10): ";
const char* nuevopin = "Nuevo pin generado\n";
const char* preguntarpin = "\nIntroduce pin de 4 cifras:\n>";
const char* nointentos="No quedan intentos\n";
const char* nocorrecto="PIN incorrecto. Te quedan %d intentos.\n";

int especificar_intentos();
void generar_nuevopin();
void acceder();

int main()
{
    srand(time(NULL));
    int eleccion;

    do {
        printf(menu);
        scanf("%d", &eleccion);
        while(getchar()!='\n');

        switch(eleccion)
        {
            case 1:
                especificar_intentos();
                break;
            case 2:
                generar_nuevopin();
                break;
            case 3:
                acceder();
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while(eleccion != 0);

    return 0;
}

int especificar_intentos()
{
    do {
        printf(preguntar_intentos);
        scanf("%d", &intentos);
        while(getchar()!='\n');
    } while(intentos < 2 || intentos > 10);

    return intentos;
}

void generar_nuevopin()
{
    do {
        cifra1=rand() % 10;
        cifra2=rand() % 10;
        cifra3=rand() % 10;
        cifra4=rand() % 10;
    } while(cifra1==cifra2 || cifra1==cifra3 || cifra1==cifra4 ||
            cifra2==cifra3 || cifra2==cifra4 ||
            cifra3==cifra4);

    printf(nuevopin);
}

void acceder()
{
    int pin_usuario;
    int intentos_restantes=intentos;

    while(intentos_restantes > 0)
    {
        printf(preguntarpin);
        scanf("%d", &pin_usuario);
        while(getchar()!='\n');

        int acierto1=pin_usuario / 1000;
        int acierto2=(pin_usuario / 100) % 10;
        int acierto3=(pin_usuario / 10) % 10;
        int acierto4=pin_usuario % 10;

        if(acierto1==cifra1 && acierto2==cifra2 &&
           acierto3==cifra3 && acierto4==cifra4)
        {
            printf("PIN correcto.\n");
            return;
        }
        else
        {
            intentos_restantes--;
            if(intentos_restantes>0)
                printf(nocorrecto, intentos_restantes);
            else
                printf(nointentos);
        }
    }
}
