package com.liga;

public class Equipo {
    private String nEquipo;
    private String ciudad;
    private int puntos;
    private int goles_favor;
    private int goles_contra;

    public Equipo(String nEquipo, String ciudad){
        this.nEquipo=nEquipo;
        this.ciudad=ciudad;
        goles_favor=goles_contra=puntos=0;
    }
    public String getnEquipo(){
        return nEquipo;
    }
    public void setnEquipo(String nEquipo){
        this.nEquipo=nEquipo;    
    }
    public String getciudad(){
        return ciudad;
    }
    public void setciudad(String ciudad){
        this.ciudad=ciudad;
    }
    public int getpuntos(){
        return puntos;
    }
    public void setpuntos(int puntos){
        this.puntos=puntos;
    }
    public int getgoles_favor(){
        return goles_favor;
    }
    public void setgoles_favor(int goles_favor){
        this.goles_favor=goles_favor;
    }
    public int getgoles_contra(){
        return goles_contra;
    }
    public void setgoles_contra(int goles_contra){
        this.goles_contra=goles_contra;
    }
    
    @Override
    public String toString() {
        return " | Equipo:  " + nEquipo + " | Ciudad: " + ciudad + "| Puntos: " + puntos +  
               " | GF: " + goles_favor + " | GC: " + goles_contra;
    }
}
