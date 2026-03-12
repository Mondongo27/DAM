package com.juego;

import java.sql.SQLOutput;

public class Personaje {
    private final static int VIDA_MAX=100;
    private final static int CAP_INV=3;
    private final static String ERROR_COGER="ERROR: %s, no puedes llevar mas cosas (%s)\n";
    private final static String ERROR_GASTAR="ERROR: %s, no tienes para gastar tanto (%s)\n";
    private final static String INFO_COGER="%s recolectando %sx%d...\n";

    private int vida;
    private final String nombre;
    private final Item[] inventario;

    public Personaje(String nombre) {
        this.nombre = nombre;
        vida=VIDA_MAX;
        inventario=new Item[3];
    }

    public void mostrarEstado(){
        System.out.printf("%s (%d)\n",nombre,vida);
        for(Item i:inventario){
            System.out.printf("\t%s\n",i==null?"(vacío)":i);
        }
    }

    public void anadirItem(Item nuevo){
        boolean ubicacionCoincidente=false;
        boolean ubicacionVacia=false;
        for(int i=0;i<CAP_INV;i++){
            if(inventario[i]==null) continue;
            if(inventario[i].getNombre().equals(nuevo.getNombre())){
                inventario[i].setCantidad(inventario[i].getCantidad() + nuevo.getCantidad());
                ubicacionCoincidente=true;
                break;
            }
        }
        if(!ubicacionCoincidente){
            for(int i=0;i<CAP_INV;i++){
                if(inventario[i]==null){
                    inventario[i]=nuevo;
                    ubicacionVacia=true;
                    break;
                }
            }
        }
        //Si no he conseguido colocarlo, aviso
        if(ubicacionCoincidente || ubicacionVacia){
            System.out.printf(INFO_COGER,nombre,nuevo.getNombre(),nuevo.getCantidad());
        }else{
            System.out.printf(ERROR_COGER,nombre,nuevo.getNombre());
        }
    }

    public void gastarItem(String cosa, int cantidad){
        for(int i=0;i<CAP_INV;i++){
            if(inventario[i]==null) continue;
            if(inventario[i].getNombre().equals(cosa)){
                if(inventario[i].getCantidad()>=cantidad){
                    inventario[i].setCantidad(inventario[i].getCantidad()-cantidad);
                }else{
                    System.out.printf(ERROR_GASTAR,this.nombre,cosa);
                }
                break;
            }
        }
    }
}