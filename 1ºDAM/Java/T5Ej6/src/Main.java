public class Main {
    public static void main(String[] args) {
        Tiempo t1 = new Tiempo(90, 900, 943580);
        System.out.println(t1);
        Tiempo t2= new Tiempo(1,30,65);
        System.out.println(t2);
        Tiempo t3= new Tiempo(1,65,50);
        System.out.println(t3);
        Tiempo t4= new Tiempo(2,182,40);
        System.out.println(t4);

        t1.sumar(t2);
        t4.restar(t3);

        System.out.println(t1);
        System.out.println(t2);
        System.out.println(t3);
        System.out.println(t4);

        t2.sumar(80);
        t3.sumar(-80);

        System.out.println(t2);
        System.out.println(t3);
    }
}