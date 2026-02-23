public class Pizza {
    private static int totalPedidas=0;
    private static int totalServidas=0;

    private String tipo;
    private final String tamanio;
    private boolean servida;

    public Pizza(String tipo, String tamanio) {
        this.tipo = tipo;
        this.tamanio = tamanio;
        servida=false;
        totalPedidas++;
    }

    public void sirve(){
        if(servida){
            System.out.println("esa pizza ya se ha servido");
        }else{
            servida=true;
            totalServidas++;
        }
    }

    public String getTipo() {
        return tipo.toUpperCase();
    }

    public void setTipo(String tipo) {
        if(!servida) this.tipo = tipo;
    }

    public static int getTotalPedidas() {
        return totalPedidas;
    }

    public static int getTotalServidas() {
        return totalServidas;
    }

    //    @Override
//    public String toString(){
//        String cadena = "pizza "+tipo+" "+tamanio+", "+(servida?"servida":"pedida");
//        return cadena;
//    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("pizza ");
        sb.append(tipo).append(" ").append(tamanio).append(", ").append(servida?"servida":"pedida");
        return sb.toString();
    }
}
