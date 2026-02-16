#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    int longitud=10;
    int datos[longitud];
    bool repetido;
    srand(time(NULL));
//    for(int i=0;i<100000;i++){
//        do{
//            datos[i]=rand()%100000+1;
//            repetido=false;
//            for(int j=0;j<i;j++){
//                if(datos[j]==datos[i]){
//                    repetido=true;
//                    break;
//                }
//            }
//        }while(repetido);
//        printf(" %d ",datos[i]);
//    }

    for(int i=0;i<longitud;i++) datos[i]=i+1;
    //Barajo los valores
    for(int i=1;i<=10*longitud;i++){
        int p1=rand()%longitud;
        int p2=rand()%longitud;
        int auxiliar=datos[p1];
        datos[p1]=datos[p2];
        datos[p2]=auxiliar;
    }
    for(int i=0;i<longitud;i++) printf(" %d ",datos[i]);

    return 0;
}
