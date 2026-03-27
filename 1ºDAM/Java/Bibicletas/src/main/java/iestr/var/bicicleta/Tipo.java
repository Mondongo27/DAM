package iestr.var.bicicleta;

public enum Tipo {
    ALUMNIO(0),
    MADERA(100),
    CARBONO(150);

    float precio;

    private Tipo(float precio) {
        this.precio=precio;
    }
}
