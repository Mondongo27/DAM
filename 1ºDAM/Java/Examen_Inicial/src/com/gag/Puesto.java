package com.gag;

public class Puesto {
    //Constantes
    private static final double BASE_MINIMA=500.00;
    //Puesto de pruebas predeterminado
    public static final Puesto PUESTO_PRUEBAS=new Puesto("En practicas",BASE_MINIMA);

    //Atributos de Puesto
    private final String descripcion;
    private double saralio;

    //Constructor
    public Puesto(String descripcion, double saralio) {
        this.descripcion = descripcion;
        //Si el salario asignado es menor que el minimo, se asigna el minimo
        setSalario(saralio);
    }

    @Override
    public String toString() {
        return descripcion + " - " + String.format("%.2f€",saralio);
    }

    //Getters

    public String getDescripcion() {
        return descripcion;
    }

    public double getSaralio() {
        return saralio;
    }

    //Setters

    public void setSalario(double salario) {
        this.saralio = Math.max(salario, BASE_MINIMA);
    }
}
