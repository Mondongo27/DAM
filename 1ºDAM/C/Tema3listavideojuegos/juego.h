#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#define LONG_TIT 20
#define LONG_PLAT 10

typedef struct{
    char titulo[LONG_TIT+1];
    char plataforma[LONG_PLAT+1];
    int puntuacion;
    int ventas;
}Juego;


#endif // JUEGO_H_INCLUDED
