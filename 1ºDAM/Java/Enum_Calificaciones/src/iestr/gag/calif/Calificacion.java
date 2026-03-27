package iestr.gag.calif;

public enum Calificacion {
    SUSPENSO("Susp"),
    APROBADO("Apro"),
    NOTABLE("Not"),
    SOBRESALIENTE("Sob");
    private final String descripcion;

    Calificacion(String descripcion) {
        this.descripcion = descripcion;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Calificacion{");
        sb.append("descripcion='").append(descripcion).append('\'');
        sb.append('}');
        return sb.toString();
    }
}
