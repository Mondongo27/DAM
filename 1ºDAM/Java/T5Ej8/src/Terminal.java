import java.util.Objects;

public class Terminal {
    private String numero;
    private int tiempo;

    public Terminal(String numero) {
        this.numero = numero;
        this.tiempo = 0;
    }

    public void llama(Terminal otro, int duracion){
        if(duracion<=0) return;
        if(this.numero.equals(otro.numero)) return;
        this.tiempo+=duracion;
        otro.tiempo+=duracion;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Nº ");
        sb.append(numero).
                append(" - ").
                append(tiempo).
                append("s de conversación");
        return sb.toString();
    }
}