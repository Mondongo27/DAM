import java.util.List;
import java.util.Random;

public class TarjetaRegalo {
    private static final int TOPE=10;
    private static int contador=0;
    private static final Random GENERADOR=new Random();
    static final TarjetaRegalo[] LISTA=new TarjetaRegalo[TOPE];

    private  int id;
    private double saldo;

    private TarjetaRegalo(double saldo) {
        this.saldo = saldo;
        int idProvisional;
        do{
            idProvisional=GENERADOR.nextInt(TOPE);
        }while(LISTA[idProvisional]!=null);
        this.id=idProvisional;
        LISTA[this.id]=this;
        contador++;
    }
    public static int nuevaTarjeta(double saldo){
        if(contador>=TOPE) return -1;
        TarjetaRegalo nueva=new TarjetaRegalo(saldo);
        return nueva.id;
    }

    public static boolean gasta(TarjetaRegalo t, double importe){
        if(t==null) return false;
        t.saldo-=importe;
        return true;
    }

    public static int fusiona(TarjetaRegalo una, TarjetaRegalo otra){
        if(una==null || otra==null) return -1;
        int nuevoId=nuevaTarjeta(una.saldo+otra.saldo);
        if(nuevoId>=0){
            una.saldo=0;
            otra.saldo=0;
        }
        return nuevoId;

    }








    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Tarjeta nº");
        sb.append(String.format("%05d",id)).
                append(" – Saldo ").
                append(String.format("%.2f",saldo)).
                append("€");
        return sb.toString();
    }

    public static void muestraLista(){
        for(TarjetaRegalo t:LISTA) System.out.println(t);
    }
}
