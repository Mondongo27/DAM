public class Punto {
    private double x;
    private double y;

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public Punto(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void desplazar(double dx,double dy){
        x+=dx;
        y+=dy;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("(");
        sb.append(x).append(", ").append(y).append(")");
        return sb.toString();
    }
}
