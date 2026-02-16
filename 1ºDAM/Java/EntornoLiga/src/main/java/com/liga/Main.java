package com.liga;
import java.util.Date;
import java.util.Scanner;

public class Main {
    private static final Scanner scanner = new Scanner(System.in);
    private static final Liga liga = new Liga();

    public static void main(String[] args) {
        int opcion;
         do{
            mostrarMenu();
            opcion = scanner.nextInt();
            scanner.nextLine();
            switch (opcion) {
                case 1 -> {
                    System.out.print("Nombre del equipo: ");
                    String nombre = scanner.nextLine();
                    System.out.print("Ciudad del equipo: ");
                    String ciudad = scanner.nextLine();
                    Equipo equipo = new Equipo(nombre, ciudad);
                    liga.registrarEquipo(equipo);
                    System.out.println("Equipo registrado: " + equipo.getnEquipo());
                }
                case 2 -> {
                    System.out.print("Equipo local: ");
                    String eqlocal = scanner.nextLine();
                    System.out.print("Equipo Visitante: ");
                    String eqVisitante = scanner.nextLine();
                    System.out.print("Goles equipo local");
                    int gEqLocal = scanner.nextInt();
                    System.out.print("Goles equipo visitante: ");
                    int gEqVisitante = scanner.nextInt();
                    scanner.nextLine();

                    if(liga.buscarEquipo(eqlocal) && liga.buscarEquipo(eqVisitante)){
                        Partidos partido=new Partidos(liga.buscarEquipoPorNombre(eqlocal),liga.buscarEquipoPorNombre(eqVisitante),gEqLocal,gEqVisitante,new Date());
                        liga.registrarPartido(partido);
                        
                    }else{
                        System.out.println("Uno de los equipos no existe.");
                    }
                }
                case 3 -> liga.mostrarClasificacion();
                case 4 -> {
                    System.out.println("Dime el nombre del equipo: ");
                    String NombreEquipo = scanner.nextLine();
                    liga.buscarEquipoPorNombre(NombreEquipo);
                }
                case 5 -> liga.listaPartidos();
                case 6 -> System.out.println("Saliendo...");
                default -> System.out.println("Opcion no valida.");
            }
        }while(opcion!=6);
    }

    private static void mostrarMenu(){
        System.out.println("\n--- Menu de la Liga de Futbol ---");
        System.out.println("1. Registrar equipo");
        System.out.println("2. Registrar partido");
        System.out.println("3. Ver clasificacion");
        System.out.println("4. Buscar equipo");
        System.out.println("5. Listar partidos");
        System.out.println("6. Salir");
        System.out.printf("Elige una opcion");
    }
}