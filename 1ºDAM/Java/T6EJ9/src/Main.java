import iestr.var.comunicaciones.Movil;
import iestr.var.comunicaciones.Tarifa;

public class Main{
    static void main(String[] args){
        Movil m1 = new Movil("678 11 22 33", Tarifa.RATA);
        Movil m2 = new Movil("644 74 44 69", Tarifa.MONO);
        Movil m3 = new Movil("622 32 89 09", Tarifa.BISONTE);
        System.out.println(m1);
        System.out.println(m2);
        m1.llama(m2, 320);
        m1.llama(m3, 200);
        m2.llama(m3, 550);
        System.out.println(m1);
        System.out.println(m2);
        System.out.println(m3);
    }
}