import iestr.var.recursividad.Par;
import iestr.var.recursividad.Pieza;
import iestr.var.recursividad.Producto;

import java.util.Scanner;

public class Main {
    public static final int CAPACIDAD = 1000;
    public static final String SALIENDO = "Saliendo...";
    public static final String OPCIÓN_NO_VALIDA = "Opción no válida. Por favor, seleccione una opción del menú.";
    public static final String SALIR = "0) Salir";
    public static final String CREAR_UNA_PIEZA_ELEMENTAL = "1) Crear una pieza elemental";
    public static final String CREAR_UNA_PIEZA_COMPUESTA = "2) Crear una pieza compuesta";
    public static final String CREAR_UN_PRODUCTO_ACABADO = "3) Crear un producto acabado";
    public static final String LISTAR_LAS_PIEZAS_ELEMENTALES_Y_COMPUESTAS = "4) Listar las piezas (elementales y compuestas)";
    public static final String LISTAR_LOS_PRODUCTOS_ACABADOS = "5) Listar los productos acabados";
    public static final String MOSTRAR_EL_ÁRBOL_DE_COMPONENTES = "6) Mostrar el árbol de componentes de un producto/pieza";
    public static final String SELECCIONE_UNA_OPCION = "Seleccione una opción: ";
    public static final String PREGUNTA_NOMBRE="Nombre de la pieza: ";
    public static final String PREGUNTA_COSTE="Coste de la pieza: ";
    public static final String INFORMA_CREACION="...creando... %s\n";
    public static final String PREGUNTA_NUMERO_COMPONENTES="Nº de componentes distintos: ";
    public static final String PREGUNTA_ID_COMPONENTE="Id del componente: ";
    public static final String PREGUNTA_CANTIDAD_COMPONENTE="Cantidad: ";
    public static final String PREGUNTA_PRECIO_VENTA="Precio de venta(<0 requiere margen): ";
    public static final String PREGUNTA_MARGEN="Margen(% sin decimales): ";
    public static final String PREGUNTA_ID_ARBOL="Dime el el id la pieza: ";

    private static Scanner scanner = new Scanner(System.in);
    private static Pieza[] lista=new Pieza[CAPACIDAD];

    public static void main(String[] args) {
        int opcion;

        do {
            mostrarMenu();
            opcion = obtenerOpcion();
            switch (opcion) {
                case 0:
                    System.out.println(SALIENDO);
                    break;
                case 1:
                    opcion1();
                    break;
                case 2:
                    opcion2();
                    break;
                case 3:
                    opcion3();
                    break;
                case 4:
                    opcion4();
                    break;
                case 5:
                    opcion5();
                    break;
                case 6:
                    opcion6();
                    break;
                default:
                    System.out.println(OPCIÓN_NO_VALIDA);
                    break;
            }
        } while (opcion != 0);

        scanner.close();
    }

    private static void opcion1() {
        System.out.println(PREGUNTA_NOMBRE);
        String nombre= scanner.nextLine();
        System.out.println(PREGUNTA_COSTE);
        float coste= obtenerCoste();
        Pieza nueva=new Pieza(nombre, coste);
        System.out.printf(INFORMA_CREACION,nueva);
        lista[nueva.getId()-1]=nueva;
    }

    private static void opcion2() {
        System.out.println(PREGUNTA_NOMBRE);
        String nombre= scanner.nextLine();
        System.out.println(PREGUNTA_CANTIDAD_COMPONENTE);
        int cantidad=obtenerCantidad();
        Par[] pares=new Par[cantidad];
        for(int i=0;i<cantidad;i++){
            System.out.println(PREGUNTA_ID_COMPONENTE);
            int id=obtenerId();
            System.out.println(PREGUNTA_CANTIDAD_COMPONENTE);
            int cantidadComponente=obtenerCantidad();
            Par nuevoPar=new Par(lista[id-1],cantidadComponente);
            pares[i]=nuevoPar;
        }
        Pieza nueva=new Pieza(nombre,pares);
        System.out.println(INFORMA_CREACION);
        lista[nueva.getId()-1]=nueva;
    }

    private static void opcion3() {
        System.out.println(PREGUNTA_PRECIO_VENTA);
        float pvp=obtenerPvp();
        System.out.println(PREGUNTA_NOMBRE);
        String nombre= scanner.nextLine();
        System.out.println(PREGUNTA_CANTIDAD_COMPONENTE);
        int cantidad=obtenerCantidad();
        Par[] pares=new Par[cantidad];
        for(int i=0;i<cantidad;i++){
            System.out.println(PREGUNTA_ID_COMPONENTE);
            int id=obtenerId();
            System.out.println(PREGUNTA_CANTIDAD_COMPONENTE);
            int cantidadComponente=obtenerCantidad();
            Par nuevoPar=new Par(lista[id-1],cantidadComponente);
            pares[i]=nuevoPar;
        }
        Producto nuevo;
        if(pvp<0){
            System.out.println(PREGUNTA_MARGEN);
            int margen=obtenerCantidad();
            nuevo=new Producto(nombre,pares,margen);
        }else{
            nuevo=new Producto(pvp,nombre,pares);
        }
        System.out.printf(INFORMA_CREACION, nuevo);
        lista[nuevo.getId()-1]=nuevo;
    }

    private static void opcion4() {
        for(Pieza p:lista){
            if(p==null) break;
            System.out.println(p);
        }
    }

    private static void opcion5() {
        for(Pieza p:lista){
            if(p==null) break;
            if(p instanceof Producto) System.out.println(p);
        }
    }

    private static void opcion6() {
    }

    public static void mostrarMenu() {
        System.out.println(SALIR);
        System.out.println(CREAR_UNA_PIEZA_ELEMENTAL);
        System.out.println(CREAR_UNA_PIEZA_COMPUESTA);
        System.out.println(CREAR_UN_PRODUCTO_ACABADO);
        System.out.println(LISTAR_LAS_PIEZAS_ELEMENTALES_Y_COMPUESTAS);
        System.out.println(LISTAR_LOS_PRODUCTOS_ACABADOS);
        System.out.println(MOSTRAR_EL_ÁRBOL_DE_COMPONENTES);
        System.out.print(SELECCIONE_UNA_OPCION);
    }

    public static int obtenerOpcion() {
        while (!scanner.hasNextInt()) {
            scanner.nextLine();
        }
        int opcion=scanner.nextInt();
        scanner.nextLine();
        return opcion;
    }

    public static int obtenerCantidad(){
        int cantidad=-1;
        while(cantidad<=0){
            if(scanner.hasNextInt()){
                cantidad=scanner.nextInt();
            }
            scanner.nextLine();
        }
        return cantidad;
    }

    public static float obtenerCoste(){
        float precio=-1.0f;
        while(precio<=0){
            if(scanner.hasNextFloat()){
                precio=scanner.nextFloat();
            }
            scanner.nextLine();
        }
        return precio;
    }

    public static float obtenerPvp(){
        float precio=0.0f;
        while(precio==0.0f){
            if(scanner.hasNextFloat()){
                precio=scanner.nextFloat();
            }
            scanner.nextLine();
        }
        return precio;
    }

    public static int obtenerId(){
        int id=-1;
        while(id<=0 || id>Pieza.getContador_id()){
            if(scanner.hasNextInt()){
                id=scanner.nextInt();
            }
            scanner.nextLine();
        }
        return id;
    }
}