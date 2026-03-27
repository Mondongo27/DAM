package iestr.var.bicicleta;

public class Pro extends Bici{
    private static final int VELOCIDADES_MINIMAS=6;
    private static final int VELOCIDADES_DEFECTO=3;
    private static final float PRECIO_SUSPENSION=120;
    private static final float PRECIO_DISCO=100;
    private static final float PRECIO_VELOCIDAD=10;
    
    private final int velocidades;
    private int velocidadActual;
    private final boolean suspension;
    private final boolean disco;

    public Pro(int velocidades, boolean suspension, boolean disco, Tipo tipo, String color, Extra[] extras) {
        super(tipo, color, extras);
        this.velocidades = Math.max(velocidades,VELOCIDADES_MINIMAS);
        this.suspension = suspension;
        this.disco = disco;
        this.velocidadActual=VELOCIDADES_DEFECTO;
        pvp+=velocidades*PRECIO_VELOCIDAD;
        if(disco) pvp+=PRECIO_DISCO;
        if(suspension) pvp+=PRECIO_SUSPENSION;
    }

    public Pro(int velocidades, boolean suspension, boolean disco, Tipo tipo, String color) {
        this(velocidades,suspension,disco,tipo,color,null);
    }

    public Pro() {
        this(0,false,false,TIPO_DEFECTO,COLOR_DEFECTO);
    }

    public void subir(){
        System.out.print(getId()+" --> ");
        if(velocidadActual<velocidades){
            System.out.println("subiendo de "+velocidadActual+" a "+ (velocidadActual+1));
            velocidadActual++;
        }else{
            System.out.println(velocidadActual+" es la velocidad máxima");
        }
    }
    
    public void bajar(){
        System.out.print(getId()+" --> ");
        if(velocidadActual>1){
            System.out.println("bajando de "+velocidadActual+" a "+ (velocidadActual-1));
            velocidadActual--;
        }else{
            System.out.println(velocidadActual+" es la velocidad mínima");
        }
    }
    
    public String toString(){
        StringBuilder sb=new StringBuilder(super.toString());
        if(suspension) sb.append(" + SUSPENSION");
        if(disco) sb.append(" + DISCO");
        sb.append(" + "+velocidades+"velocidades");
        return sb.toString();
    }

    @Override
    public void rodar(int metros) {
        System.out.println(getId()+" --> rodando "+metros+" metros en plan 'pro'");
    }
    
    
}
