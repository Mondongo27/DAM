package iestr.var.comunicaciones;

public enum Tarifa {
    RATA(0.06f),
    MONO(0.12f),
    BISONTE(0.30f);

    public final float cpm;

    Tarifa(float cpm) {
        this.cpm = cpm;
    }
}
