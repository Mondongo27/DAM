package iestr.var.recursividad;

import java.util.Arrays;

public class Pieza {
    private static int contador_id=0;

    private final int id;
    private final String nombre;
    private final float coste;
    private final Par[] pares;

    private Pieza(String nombre, float coste, Par[] pares) {
        this.nombre = nombre;
        this.pares = pares;
        id=++contador_id;
        if(pares==null){//supongo que me pasan pares o coste, pero no los dos
            this.coste = coste;
        }else{
            float costeAcumulado=0;
            for (Par p : pares) {
                costeAcumulado += p.getPieza().coste * p.getCantidad();
            }
            this.coste=costeAcumulado;
        }
    }

    public Pieza(String nombre, float coste) { //Pieza simple, sin componentes
        this(nombre,coste,null);
    }

    public Pieza(String nombre,Par[] pares) { //Pieza con componentes
        this(nombre,-1,pares);
    }

    public float getCoste() {
        return coste;
    }

    public int getId() {
        return id;
    }

    public static int getContador_id() {
        return contador_id;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("[");
        sb.append(id)
                .append("] ")
                .append(nombre)
                .append(", coste: ")
                .append(String.format("%.2f€",coste));
        if(pares==null) sb.append(" (E)");
        return sb.toString();
    }
}
