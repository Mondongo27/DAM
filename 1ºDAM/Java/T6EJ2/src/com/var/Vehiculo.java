package com.var;

public abstract class Vehiculo {
    private static int vehiculosCreados=0;
    private static float kmTotales=0.0f;
    private float kilometrosRecorridos;

    Vehiculo() {
        vehiculosCreados++;
        this.kilometrosRecorridos = 0.0f;
    }

    public void andar(float km){
        if(recorrer(km)) return;
        System.out.println("Andando "+km);
    }

    public static void KilometrosTotales() {
        System.out.println("Total de este vehiculo: "+kmTotales);
    }

    public void KilometrosRecorridos() {
        System.out.println("Total de todos los vehículos: "+kilometrosRecorridos);
    }

    boolean recorrer(float distancia){
        if(distancia<=0) return false;
        kilometrosRecorridos+=distancia;
        kmTotales+=distancia;
        return true;
    }
}
