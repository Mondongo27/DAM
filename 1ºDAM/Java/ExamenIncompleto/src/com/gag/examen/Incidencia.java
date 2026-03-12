package com.gag.examen;

public class Incidencia {
    private final int id;
    private final String descripcion;
    private final float coste;
    private boolean resuelta;

    Incidencia(int id, String descripcion, float coste) {
        this.id = id;
        this.descripcion = descripcion;
        this.coste=Math.max(0,coste);
        this.resuelta=false;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Incidencia ");
        sb.append(id);
        sb.append(" (");
        sb.append(resuelta?"resuelta): ":"PENDIENTE): ");
        sb.append(descripcion);
        sb.append(" (").append(String.format("%.2f€",coste)).append(")");
        return sb.toString();
    }

    boolean resolver() {
        if(resuelta) return false;
        resuelta=true;
        return true;
    }
}
