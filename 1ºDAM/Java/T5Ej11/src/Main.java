public class Main{
    static void main() {
        TarjetaRegalo.nuevaTarjeta(100);
        TarjetaRegalo.nuevaTarjeta(120);
        TarjetaRegalo.nuevaTarjeta(30);
        TarjetaRegalo.nuevaTarjeta(40);
        TarjetaRegalo.nuevaTarjeta(50);
        TarjetaRegalo.nuevaTarjeta(60);
        TarjetaRegalo.nuevaTarjeta(70);
        TarjetaRegalo.nuevaTarjeta(80);
        TarjetaRegalo.nuevaTarjeta(90);
//        TarjetaRegalo.nuevaTarjeta(100);
//        TarjetaRegalo.nuevaTarjeta(110);
        TarjetaRegalo.muestraLista();
        System.out.println("--------------------------");
        TarjetaRegalo t1= TarjetaRegalo.LISTA[1];
        TarjetaRegalo t2=TarjetaRegalo.LISTA[2];
        TarjetaRegalo.gasta(t1,45.90);
        TarjetaRegalo.gasta(t2,5);
        TarjetaRegalo.gasta(t2,200);
        TarjetaRegalo.gasta(t1,3.55);
        System.out.println(t1);
        System.out.println(t2);

        System.out.println(t1);
        System.out.println(t2);
        int id=TarjetaRegalo.fusiona(t1,t2);
        if(id>=0) System.out.println(TarjetaRegalo.LISTA[id]);


    }
}