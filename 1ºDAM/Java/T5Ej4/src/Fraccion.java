public class Fraccion {
    private int numerador;
    private int denominador;

    public static Fraccion nuevaFraccion(int numerador, int denominador){
        if(denominador==0){
            return null;
        }else{
            return new Fraccion(numerador, denominador);
        }
    }

    private Fraccion(int numerador, int denominador) {
        this.numerador = numerador;
        this.denominador = denominador;
        simplificar(this);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder();
        sb.append(numerador).append('/').append(denominador);
        return sb.toString();
    }

    //////////////////////////////////// OPERACIONES ////////////////////////////////////
    public static Fraccion multiplicar(Fraccion f1,Fraccion f2){
        return nuevaFraccion(
                f1.numerador*f2.numerador,
                f1.denominador*f2.denominador);
    }
    public Fraccion multiplicar(Fraccion otra){
        if(otra==null) return null;
        return nuevaFraccion(
                this.numerador*otra.numerador,
                this.denominador*otra.denominador);
    }

    public static Fraccion dividir(Fraccion f1,Fraccion f2){
        return nuevaFraccion(
                f1.numerador*f2.denominador,
                f1.denominador*f2.numerador);
    }
    public Fraccion dividir(Fraccion otra){
        if(otra==null) return null;
        return nuevaFraccion(
                this.numerador*otra.denominador,
                this.denominador*otra.numerador);
    }

    public Fraccion invertir(){
        return nuevaFraccion(denominador,numerador);
    }

    public void simplificar(){
        if(this==null) return;
        int min=Math.min(numerador,denominador);
        for(int i=min;i>=2;i--){
            if(numerador%i==0 && denominador%i==0){
                numerador/=i;
                denominador/=i;
            }
        }
    }
    public static void simplificar(Fraccion f){
        if(f==null) return;
        int min=Math.min(f.numerador,f.denominador);
        for(int i=min;i>=2;i--){
            if(f.numerador%i==0 && f.denominador%i==0){
                f.numerador/=i;
                f.denominador/=i;
            }
        }
    }
}