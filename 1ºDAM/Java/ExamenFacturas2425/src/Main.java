import java.util.Scanner;

public class Main{
    final static int MAX_FACTURAS=1000;
    static Scanner sc = new Scanner(System.in);
    static int id;
    static String cliente;
    static double importe;
    static Factura factura;
    static Factura[] facturas= new Factura[MAX_FACTURAS];//@TODO completa la sentencia adecuadamente
    static StringBuilder sb=new StringBuilder("");
    static int pendientes;

    public static void main(String[] args) {
        boolean terminar=false;
        String opcion;

        while (true) {
            System.out.println("1)CreaFactura 2)ModificaImporte 3)Abona 4)Lista 5)Resumen 6)Morosos");
            opcion = sc.nextLine();
            switch (opcion) {
                case "1":
                    if(Factura.getContador()>=MAX_FACTURAS){
                        System.out.println("Ya no caben más facturas");
                        break;
                    }
                    registraFacturaNueva();
                    break;
                case "2":
                    modificaImporteFactura();
                    break;
                case "3":
                    abonaFactura();
                    break;
                case "4":
                    muestraListado();
                    break;
                case "5":
                    muestraResumen();
                    break;
                case "6":
                    listaMorosos();
                    break;
                default://Si elige cualquier otra opción se termina el programa
                    terminar=true;
                    System.out.println("Saliendo...");
                    break;
            }
            if(terminar) break;
        }
    }

    private static void listaMorosos() {
        for(Factura f:facturas){
            if(f==null) break;
            if(f.isAbonada()) break;
            System.out.printf("| %s |",f.getCliente());
        }
        System.out.println("");
    }

    private static void muestraResumen() {
        System.out.printf(
                "Facturas abonadas (%d) --> %.2f€",
                Factura.getAbonadas(),
                Factura.getImportetotalabonado());
        System.out.printf(
                "Facturas sin pagar (%d) --> %.2f€",
                Factura.getSinpagar(),
                Factura.getImportetotalpendiente()
        );
    }

    private static void muestraListado() {
        for(int i=0; i<Factura.getContador(); i++){
            System.out.println(facturas[i]);
        }
//        for(Factura f:facturas){
//            if(f==null) break;
//            System.out.println(f);
//        }
    }

    private static void abonaFactura() {
        System.out.println("Introduce Id de la factura");
        while(!sc.hasNextInt()) sc.next();
        id=sc.nextInt();
        sc.nextLine();
        if(id>Factura.getContador()){
            System.out.println("Esa factura no existe");
            return;
        }
        System.out.println("...abonando factura...");
        if(facturas[id-1].abona()){
            System.out.printf("OK: %s\n",facturas[id-1]);
        }else{
            System.out.printf("ERROR. No se ha podido hacer: %s\n",facturas[id-1]);
        }
    }

    private static void modificaImporteFactura() {
        System.out.println("Introduce Id de la factura y nuevo importe (en dos líneas)");
        //Cogemos el id
        while(!sc.hasNextInt()) sc.next();
        id=sc.nextInt();
        sc.nextLine();
        if(id>Factura.getContador()){
            System.out.println("Esa factura no existe");
            return;
        }
        //Cogemos el importe
        while(!sc.hasNextDouble()) sc.next();
        importe=sc.nextDouble();
        sc.nextLine();
        //Actualizamos los datos
        System.out.print("...modificando importe...");
        if(facturas[id-1].setImporte(importe)){
            System.out.printf("OK: %s\n",facturas[id-1]);
        }else{
            System.out.printf("ERROR. No se ha podido hacer: %s\n",facturas[id-1]);
        }
    }

    private static void registraFacturaNueva() {
        System.out.println("Introduce cliente e importe (en dos líneas)");
        cliente=sc.nextLine();
        while(!sc.hasNextDouble()) sc.next();
        importe=sc.nextDouble();
        sc.nextLine();
        factura=new Factura(cliente,importe);
        facturas[factura.getId()-1]=factura;
        System.out.println("...creando factura... OK: "+factura);
    }
}
