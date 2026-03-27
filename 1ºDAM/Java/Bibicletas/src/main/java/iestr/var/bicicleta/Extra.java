package iestr.var.bicicleta;

public enum Extra {
    RUEDA_GORDA(90.0f),
    GUARDABARROS(30.0f),
    LUCES(40.0f),
    SOPORTE_MOVIL(20.0f);

    float precio;
    private Extra(float precio) {
        this.precio = precio;
    }
}
