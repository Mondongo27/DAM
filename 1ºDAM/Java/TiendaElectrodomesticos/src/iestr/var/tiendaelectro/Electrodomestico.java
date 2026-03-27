package iestr.var.tiendaelectro;

public class Electrodomestico {
    private static final float PRECIO_DEFECTO=100.0f;
    private static final String DESC_DEFECTO="Genérico-%d";
    private static final Color COLOR_DEFECTO=Color.Blanco;
    private static final Consumo CONSUMO_DEFECTO=Consumo.A;

    private static int contador=0;

    private final int id;
    private final String descripcion;
    private final float precio;
    private final Color color;
    private final Consumo consumo;

    public Electrodomestico(String descripcion, float precio, Color color, Consumo consumo) {
        this.id=++contador;
        this.descripcion = descripcion;
        this.precio = precio;
        this.color = color;
        this.consumo = consumo;
    }

    public Electrodomestico() {
        this(DESC_DEFECTO,PRECIO_DEFECTO,COLOR_DEFECTO,CONSUMO_DEFECTO);
    }
}
