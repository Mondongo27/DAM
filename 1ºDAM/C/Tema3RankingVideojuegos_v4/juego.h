#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

#define LONG_TIT 99
#define LONG_PLAT 19

typedef struct{
    char titulo[LONG_TIT+1];
    char plataforma[LONG_PLAT+1];
    int puntuacion;
    int ventas;
}Juego;


#endif // RANKING_H_INCLUDED
