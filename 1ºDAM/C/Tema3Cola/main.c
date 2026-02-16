#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
//Queremos controlar las personas que acceden a nuestras instalaciones
//Cada persona tiene 3 iniciales y un nif de 8 números y una letra

//Construye una cola de Persona's e implementala utilizando la lista enlazada simple.
//Crea un programa básico para probar la funcionalidad: insertar, consultar, sacar, iniciar, limpiar.


int main(){
    Lista lista;
    ListaIniciar(&lista);

    printf("\nAgregar cinco personas\n");
    Cliente p1={"VAR","12345V"};
    ListaInsertar(&lista,&p1);
    Cliente p2={"ABC","12345A"};
    ListaInsertar(&lista,&p2);
    Cliente p3={"ABR","ABERREA"};
    ListaInsertar(&lista,&p3);
    Cliente p4={"MCH","12345M"};
    ListaInsertar(&lista,&p4);
    Cliente p5={"GCN","12345G"};
    ListaInsertar(&lista,&p5);

    printf("\nConsultar 3 personas\n");
    Cliente cliente;
    for(int i=1;i<=3;i++){
        ListaConsultar(&lista,&cliente);
        printf("\n%s\t%s",cliente.iniciales,cliente.nif);
        ListaSacar(&lista);
    }

    printf("\n\n%d",ListaVaciar(&lista));
    printf("\n%d\n",ListaConsultar(&lista,&cliente));

    return 0;
}
