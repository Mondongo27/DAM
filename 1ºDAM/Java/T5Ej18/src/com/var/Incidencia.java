package com.var;

public class Incidencia {
    private final int id;
    private boolean resuelta;
    private final int puesto;
    private final String descripcion;
    private String solucion;

    private static int contador=0;
    private static int pendientes=0;

    public Incidencia(int puesto, String descripcion) {
        this.puesto = puesto;
        this.descripcion = descripcion;
        resuelta=false;
        pendientes++;
        id=++contador;
        solucion="";
    }

    public void resuelve(String info){
        if(resuelta) return;
        this.resuelta=true;
        this.solucion=info;
        pendientes--;
    }

    public static int getPendientes() {
        return pendientes;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Incidencia ");
        sb.append(id)
                .append(" - Puesto: ").append(puesto)
                .append(" - ").append(descripcion);
        if(resuelta){
            sb.append(" - Resuelta - ").append(solucion);
        }else{
            sb.append(" - Pendiente");
        }

        return sb.toString();
    }
}
