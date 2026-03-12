public class Main{
    static void main() {
        Punto p1 = new Punto(4.21, 7.3);
        Punto p2 = new Punto(-2, 1.66);
        Linea l = new Linea(p1, p2);
        System.out.println(l);
        System.out.println("--------------------");
        l.desplazar(10,20);
        System.out.println(l);
        System.out.println(p1);
        System.out.println(p2);
        System.out.println("--------------------");
        Punto primero=l.getA();
        primero.desplazar(1000,2000);
        System.out.println(l);
    }
}