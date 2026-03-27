package iestr.var.herencia;

public class Alumno extends Persona{
    private final String curso;

    public Alumno(int dni, String nombre,String curso) {
        super(dni, nombre);
        this.curso=curso;
    }

    @Override
    public void saludar() {
        System.out.printf("%s: ¡Que pasa!\n",this);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("D. ");
        sb.append(super.toString()).append("(");
        sb.append(curso).append(")");
        return sb.toString();
    }
}
