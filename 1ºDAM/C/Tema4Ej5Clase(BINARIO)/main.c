#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TMP 21
#define FALLOS_FATALES 6

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef struct {
    int id;
    char texto[20];
} Palabra;

typedef struct {
    char nombre[21];
    int puntos;
} Puntuacion;

int pedir_palabra();
void mostrar_estado(int, int, int);
char pedir_letra();
int procesar(char, int);
void mostrar_resultado(int, int);
void jugar();
void ver_puntos();
void actualizar_puntos(char[], int);
void registrar_acertada(int);
int ya_acertada(int);

const char* PREGUNTA_PALABRA = "\nDime la palabra: ";
const char* PREGUNTA_LETRA = "\nDime una letra: ";
const char* TEXTO_VICTORIA = "\n\n\t\t¡¡¡VICTORIA!!! (llevas %d puntos)";
const char* TEXTO_DERROTA = "\n\n\t\t¡¡¡HAS PERDIDO!!! (has conseguido %d puntos)";
const char* TEXTO_MENU = "\n1) Ver puntos\n2) Jugar\n3) Salir\n";
const char* PREGUNTA_NOMBRE = "\nDime tu nombre: ";

char oculta[TMP];
char visible[TMP];
char entradas[TMP + FALLOS_FATALES];

int main() {
    srand(time(NULL));
    char opcion = '0';
    do {
        printf(TEXTO_MENU);
        scanf(" %c", &opcion);
        while (getchar() != '\n');
        switch (opcion) {
        case '1':
            ver_puntos();
            break;
        case '2':
            jugar();
            break;
        }
    } while (opcion != '3');
    return 0;
}

void jugar() {
    int puntos = 0;
    int fallos;
    char letra;
    int coincidencias;
    int aciertos;
    int contador_entradas;
    int longitud;
    int id_actual;

    char nombre[21];
    printf(PREGUNTA_NOMBRE);
    scanf("%20[^\n]", nombre);
    while (getchar() != '\n');

    FILE* f = fopen("acertadas.txt", "w");
    if (f) fclose(f);

    do {
        fallos = 0;
        aciertos = 0;
        contador_entradas = 0;

        id_actual = pedir_palabra();
        if (id_actual == -1) {
            printf("\nNo hay mas palabras disponibles.\n");
            break;
        }

        longitud = strlen(oculta);
        for (int i = 0; i < longitud; i++) visible[i] = '_';
        visible[longitud] = '\0';

        do {
            mostrar_estado(fallos, longitud, contador_entradas);
            letra = pedir_letra();
            entradas[contador_entradas] = letra;
            contador_entradas++;
            coincidencias = procesar(letra, longitud);
            if (!coincidencias) fallos++;
            aciertos += coincidencias;
        } while (aciertos < longitud && fallos < FALLOS_FATALES);

        mostrar_estado(fallos, longitud, contador_entradas);

        if (aciertos == longitud) {
            puntos += aciertos;
            registrar_acertada(id_actual);
        }

        mostrar_resultado(fallos, puntos);

        if (fallos >= FALLOS_FATALES) {
            actualizar_puntos(nombre, puntos);
        }

    } while (fallos < FALLOS_FATALES);
}

int pedir_palabra() {
    FILE* f = fopen("diccionario.dat", "rb");
    if (!f) return -1;

    fseek(f, 0, SEEK_END);
    int num_palabras = ftell(f) / sizeof(Palabra);

    int indices[num_palabras];
    for(int i=0; i<num_palabras; i++) indices[i] = i;

    for(int i = num_palabras-1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    Palabra p;
    int encontrado = 0;

    for(int i=0; i<num_palabras; i++) {
        fseek(f, indices[i] * sizeof(Palabra), SEEK_SET);
        fread(&p, sizeof(Palabra), 1, f);
        if (!ya_acertada(p.id)) {
            strcpy(oculta, p.texto);
            encontrado = 1;
            break;
        }
    }

    fclose(f);
    return encontrado ? p.id : -1;
}

int ya_acertada(int id) {
    FILE* f = fopen("acertadas.txt", "r");
    if (!f) return 0;
    int id_leido;
    while (fscanf(f, "%d", &id_leido) != EOF) {
        if (id_leido == id) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

void registrar_acertada(int id) {
    FILE* f = fopen("acertadas.txt", "a");
    if (f) {
        fprintf(f, "%d\n", id);
        fclose(f);
    }
}

void actualizar_puntos(char nombre[], int puntos) {
    FILE* f = fopen("puntos.dat", "r+b");
    Puntuacion p;
    int encontrado = 0;

    if (!f) {
        f = fopen("puntos.dat", "wb");
    } else {
        while (fread(&p, sizeof(Puntuacion), 1, f)) {
            if (strcmp(p.nombre, nombre) == 0) {
                p.puntos = puntos;
                fseek(f, -(long)sizeof(Puntuacion), SEEK_CUR);
                fwrite(&p, sizeof(Puntuacion), 1, f);
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        fseek(f, 0, SEEK_END);
        strcpy(p.nombre, nombre);
        p.puntos = puntos;
        fwrite(&p, sizeof(Puntuacion), 1, f);
    }
    fclose(f);
}

void ver_puntos() {
    FILE* f = fopen("puntos.dat", "rb");
    if (!f) {
        printf("\nNo hay puntuaciones registradas.\n");
        return;
    }
    Puntuacion p;
    printf("\n--- TABLA DE PUNTOS ---\n");
    while (fread(&p, sizeof(Puntuacion), 1, f)) {
        printf("%-20s : %d pts\n", p.nombre, p.puntos);
    }
    fclose(f);
}

void mostrar_estado(int fallos, int longitud, int contador) {
    system(CLEAR);
    printf("\n_____");
    printf("\n|/ | ");
    printf("\n|  %c ", (fallos >= 1) ? 'O' : ' ');
    printf("\n| %c%c%c ", (fallos >= 3) ? '/' : ' ',
           (fallos >= 2) ? '|' : ' ', (fallos >= 4) ? '\\' : ' ');
    printf("\n| %c %c ", (fallos >= 5) ? '/' : ' ', (fallos >= 6) ? '\\' : ' ');
    printf("\n|_______\n\n");
    for (int i = 0; i < longitud; i++) printf("%c", visible[i]);
    if (contador > 0) {
        printf("\t(");
        for (int i = 0; i < contador; i++) printf("%c", entradas[i]);
        printf(")");
    }
}

char pedir_letra() {
    char letra;
    printf(PREGUNTA_LETRA);
    scanf(" %c", &letra);
    while (getchar() != '\n');
    return letra;
}

int procesar(char letra, int longitud) {
    int aciertos_letra = 0;
    for (int i = 0; i < longitud; i++) {
        if (letra == oculta[i] && letra != visible[i]) {
            aciertos_letra++;
            visible[i] = letra;
        }
    }
    return aciertos_letra;
}

void mostrar_resultado(int fallos, int puntos) {
    if (fallos < FALLOS_FATALES) {
        printf(TEXTO_VICTORIA, puntos);
        printf("\nPresiona Enter para siguiente palabra...");
        getchar();
    } else {
        printf(TEXTO_DERROTA, puntos);
        printf("(Era %s)\n", oculta);
    }
}


