#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define LONG_INICIALES 4
#define LONG_NIF 10

typedef struct cliente{
    char iniciales[LONG_INICIALES];
    char nif[LONG_NIF];
}Cliente;


#endif // CLIENTE_H_INCLUDED
