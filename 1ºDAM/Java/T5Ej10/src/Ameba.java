public class Ameba {
    private int peso;

    public Ameba() {
        this.peso = 3;
    }

    public void come(int n){
        if(n<1) return;
        this.peso+=n-1;
    }
    public void come(Ameba otra){
        if(this.equals(otra)) return;
        come(otra.peso);
        otra.peso=0;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Soy una ameba y peso ");
        sb.append(peso).append(" microgramos");
        return sb.toString();
    }
}
