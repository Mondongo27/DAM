public class Tiempo {
    private int horas;
    private int minutos;
    private int segundos;

    public Tiempo(int horas, int minutos, int segundos) {
        this.horas = Math.max(horas,0);
        this.minutos = Math.max(minutos,0);
        this.segundos = Math.max(segundos,0);
        normalizar();
    }

    public Tiempo(int segundos){
        this(0,0,segundos);
    }

    private void normalizar(){
        int segundosNormalizados=segundos%60;
        int minutosExtra=segundos/60;
        minutos+=minutosExtra;
        int minutosNormalizados=minutos%60;
        int horasExtra=minutos/60;
        horas+=horasExtra;
        minutos=minutosNormalizados;
        segundos=segundosNormalizados;
    }

    private static int desnormalizar(Tiempo t){
        return (t.horas*3600+t.minutos*60+t.segundos);
    }

    public static Tiempo sumar(Tiempo primero,Tiempo segundo){
        return new Tiempo(
                primero.horas+segundo.horas,
                primero.minutos+segundo.minutos,
                primero.segundos+segundo.segundos
        );
    }

    public static Tiempo sumar(Tiempo primero,int cantSeg){
        int segundos=desnormalizar(primero);
        return new Tiempo(
                0,
                0,
                Math.max(segundos+cantSeg,0)
        );
    }

    public static Tiempo sumar(int seg1,int seg2){
        return new Tiempo(0,0,seg1+seg2);
    }

    public void sumar(Tiempo otro){
        sumar(desnormalizar(otro));
//        this.horas+=otro.horas;
//        this.minutos+=otro.minutos;
//        this.segundos+=otro.segundos;
//        normalizar();
    }

    public void sumar(int cantSeg){
        int segundos=desnormalizar(this);
        this.horas=0;
        this.minutos=0;
        this.segundos=Math.max(segundos+cantSeg,0);
        normalizar();
    }

    public void restar(Tiempo otro){
        int segundos=-desnormalizar(otro);
        sumar(segundos);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder();
        sb.append(horas).append(":").append(String.format("%02d",minutos)).append(":").append(String.format("%02d",segundos));
        return sb.toString();
    }
}
