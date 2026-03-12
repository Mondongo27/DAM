public class Factura {
    private static int contador=0;
    private static int abonadas=0;
    private static int sinpagar=0;
    private static double importetotalabonado=0;
    private static double importetotalpendiente=0;
    private static final String TEXTO_ABONADA="(Abonada)";
    private static final String TEXTO_PENDIENTE="(Pendiente de pago)";

    private final int id;
    private final String cliente;
    private double importe;
    private boolean abonada;

    public Factura(String cliente,double importe) {
        this.id = ++contador;
        this.cliente=cliente;
        this.importe=importe;
        abonada=false;
        sinpagar++;
        importetotalpendiente+=importe;
    }

    public int getId() {
        return id;
    }

    public static int getContador() {
        return contador;
    }

    public String getCliente() {
        return cliente;
    }

    public boolean setImporte(double importe) {
        if(abonada) return false;
        //Si esta pendiente de pago...
        importetotalpendiente+=importe-this.importe;
        this.importe = importe;
        return true;
    }

    public boolean abona(){
        if(abonada) return false;
        abonada=true;
        abonadas++;
        sinpagar--;
        importetotalpendiente-=importe;
        importetotalabonado+=importe;
        return true;
    }

    public static double getImportetotalabonado() {
        return importetotalabonado;
    }

    public static double getImportetotalpendiente() {
        return importetotalpendiente;
    }

    public static int getAbonadas() {
        return abonadas;
    }

    public static int getSinpagar() {
        return sinpagar;
    }

    public boolean isAbonada() {
        return abonada;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder(" ");
        sb.append("(").append(id).append(") ").append(cliente).append(" --> ");
        sb.append(String.format("%.2f€ ",importe));
        if(!this.abonada){
            sb.append("(Pendiente de pago)");
        }else{
            sb.append("(Abonada)");
        }
        return sb.toString();
    }
}
