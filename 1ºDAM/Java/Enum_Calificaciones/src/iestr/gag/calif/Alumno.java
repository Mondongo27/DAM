package iestr.gag.calif;

public class Alumno {
    private final String nombre;
    private Calificacion calificacion;

    public Alumno(String nombre, Calificacion calificacion) {
        this.nombre = nombre;
        this.calificacion = calificacion;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder(nombre)
                .append(" --> ").append(calificacion);
        return sb.toString();
    }
}
