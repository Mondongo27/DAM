package iestr.var.recursividad;

public class Producto extends Pieza{
    private final float pvp;

    public Producto(float pvp, String nombre, Par[] pares) {
        super(nombre, pares);
        this.pvp = pvp;
    }

    public Producto(String nombre, Par[] pares, int margen) {
        super(nombre, pares);
        pvp=this.getCoste()*(1+margen/100.0f);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder(super.toString());
        sb.append(" pvp: ")
                .append(String.format("%.2f€",pvp));
        return sb.toString();
    }
}
