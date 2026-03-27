package iestr.var.herencia;

public class Maestro extends Persona{
    private final String especialidad;

    public Maestro(int dni, String nombre, String especialidad) {
        super(dni, nombre);
        this.especialidad = especialidad;
    }

    @Override
    public void saludar(){
        System.out.printf("%s: ¡Firmes!\n",this);
    }

    public void examinar(int n){
        System.out.printf("%s: ¡Examinando a %d alumnos!\n",this,n);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("D. ");
        sb.append(super.toString()).append("(");
        sb.append(especialidad).append(")");
        return sb.toString();
    }
}
