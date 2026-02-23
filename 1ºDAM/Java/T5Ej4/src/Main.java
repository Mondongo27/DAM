public class Main {
    static void main(String[] args) {
        Fraccion f1= Fraccion.nuevaFraccion(3,1);
        System.out.println(f1);
        Fraccion.simplificar(f1);
        System.out.println(f1);
        Fraccion f2= Fraccion.nuevaFraccion(200,100);
        System.out.println(f2);
        System.out.println(Fraccion.multiplicar(f1,f2));
    }
}