public class Linea {
    private final Punto a;
    private final Punto b;

    public Linea(Punto a, Punto b) {
        this.a = new Punto(a.getX(), a.getY());
        this.b = new Punto(b.getX(),b.getY());
    }

    public Punto getA() {
        return a;
    }

    public Punto getB() {
        return b;
    }

    public void desplazar(double dx, double dy){
        a.desplazar(dx,dy);
        b.desplazar(dx,dy);
    }
    
    public void moverA(Punto c){
        a.desplazar(c.getX(),c.getY());
    }
    
    public void moverB(Punto c){
        b.desplazar(c.getX(),c.getY());
    }
    
    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Línea formada por los puntos ");
        sb.append(a).append(" y ").append(b);
        return sb.toString();
    }
}
