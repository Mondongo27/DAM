#include <stdlib.h>
#include "proveedorvj.h"

void inicia_vj_aleat(Juego* j){
    int long_titulo=1+rand()%(LONG_TIT-1);
    for(int i=0;i<long_titulo;i++) j->titulo[i]=65+rand()%25;
    j->titulo[long_titulo]='\0';

    int long_plataforma=1+rand()%(LONG_PLAT-1);
    for(int i=0;i<long_plataforma;i++) j->plataforma[i]=65+rand()%25;
    j->plataforma[long_plataforma]='\0';

    j->puntuacion=rand()%11;

    j->ventas=1000*rand()%1001 + rand()%1000;
}
