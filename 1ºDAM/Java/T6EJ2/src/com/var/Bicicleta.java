package com.var;

public class Bicicleta extends Vehiculo{
    public void caballito(int metros){
        if(recorrer(metros*0.001f))
            System.out.printf("Haciendo el caballito durante %d metros\n",metros);
    }
}
