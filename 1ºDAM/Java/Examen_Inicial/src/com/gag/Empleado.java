package com.gag;

public class Empleado {
    private static int contadorId=1;

    private int id;
    private String nombre;
    private Puesto puesto;
    private float complemento;

    public Empleado(String nombre, Puesto puesto, float complemento) {
        this.id = contadorId;
        contadorId++;
        this.nombre = nombre;
        this.puesto = puesto;
        setComplemento(complemento);
    }

    public Empleado(String nombre) {
        this.nombre = nombre;
        this.id=contadorId;
        contadorId++;
        this.puesto=Puesto.PUESTO_PRUEBAS;
        this.complemento=0;
    }

    @Override
    public String toString() {
        String cadena = id + " - " + nombre + " - " + puesto.getDescripcion() +
                " - " + String.format("%.2f", puesto.getSaralio()) + "€";
        if (complemento > 0) {
            cadena += " (+" + String.format("%.2f", complemento) + "€)";
        }
        return cadena;
    }

    public int getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public Puesto getPuesto() {
        return puesto;
    }

    public double getComplemento() {
        return complemento;
    }

    public static int getContadorId() {
        return contadorId;
    }

    public void setComplemento(float complemento) {
        if(complemento<0){
            this.complemento=0;
        }else{
            this.complemento=complemento;
        }
    }

    public void setPuesto(Puesto puesto) {
        this.puesto = puesto;
    }
}
