package iestr.var.bicicleta;

import java.util.Arrays;

public class Bici {
    static final int PRECIO_MINIMO=100;
    static final Tipo TIPO_DEFECTO=Tipo.ALUMNIO;
    static final String COLOR_DEFECTO="Azul";
    
    protected static int contador=0;
    
    private int id;
    float pvp;
    private Tipo tipo;
    private String color;
    private Extra[] extras;

    //---------------------- CONSTRUCTORES ---------------------------
    public Bici(Tipo tipo, String color, Extra[] extras) {
        this.id = ++contador;
        this.tipo = tipo;
        this.color = color;
        this.pvp = PRECIO_MINIMO+tipo.precio;
        if(extras!=null){
            this.extras = Arrays.copyOf(extras, extras.length);
            for(Extra e:this.extras){
                this.pvp+=e.precio;
            }
        }
    }
    
    public Bici(Tipo tipo, String color){
        this(tipo,color,null);
    }
    
    public Bici(){
        this(TIPO_DEFECTO,COLOR_DEFECTO);
    }

    //------------------------ ACCIONES ------------------------------
    public void rodar(int metros){
        System.out.println(id+" --> rodando "+metros+" metros");
    }
    
    //------------------------ AUXILIARES -----------------------------
    @Override
    public String toString() {
        StringBuilder sb=new StringBuilder("");
        sb.append("(").append(id).append(")-->").append(pvp).append("€ ")
                .append(tipo).append(" ")
                .append(color);
        if(extras!=null){
            for(Extra e:extras){
                sb.append(" + "+e.name());
            }
        }
        return sb.toString();
    }
    
    //----------------------SETTERS/GETTERS -----------------------------

    public int getId() {
        return id;
    }
    
}
