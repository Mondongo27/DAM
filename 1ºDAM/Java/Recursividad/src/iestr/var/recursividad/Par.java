package iestr.var.recursividad;

public class Par {
    private final Pieza pieza;
    private final int cantidad;

    public Par(Pieza pieza, int cantidad) {
        this.pieza = pieza;
        this.cantidad = cantidad;
    }

    Pieza getPieza() {
        return pieza;
    }

    int getCantidad() {
        return cantidad;
    }
}
