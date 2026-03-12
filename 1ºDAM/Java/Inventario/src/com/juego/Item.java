package com.juego;

public class Item {
    private final String nombre;
    private int cantidad;

    public Item(String nombre, int cantidad) {
        this.nombre = nombre;
        this.cantidad = cantidad;
    }

    public String getNombre() {
        return nombre;
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder(nombre);
        sb.append(" (Cantidad: ").append(cantidad).append(')');
        return sb.toString();
    }
}