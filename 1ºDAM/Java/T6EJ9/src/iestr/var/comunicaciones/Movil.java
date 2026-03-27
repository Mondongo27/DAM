package iestr.var.comunicaciones;

public class Movil extends Terminal{
    private Tarifa tarifa;
    private float tarificado;

    public Movil(String numero, Tarifa tarifa) {
        super(numero);
        this.tarifa=tarifa;
        this.tarificado=0.0f;
    }

    @Override
    public void llama(Terminal otro, int duracion){
        super.llama(otro,duracion);
        tarificado+=duracion*tarifa.cpm/60.0f;
    } 

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder(super.toString());
        sb.append(" - tarificado ")
                .append(String.format("%.2f euros",tarificado));
        return sb.toString();
    }
}
