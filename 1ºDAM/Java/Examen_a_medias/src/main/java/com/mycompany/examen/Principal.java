package com.mycompany.examen;

import java.util.Scanner;

public class Principal {
    private static final String EQUIPO_ORDENADOR="Droide";
    private static Scanner sc=new Scanner(System.in);
    private static Robot[] ordenador,humano;
    private static int contadorTurno=0;
    
    public static void main(String[] args) {
        //Pide un nombre para el equipo del jugador, que no coincida con el otro
        String nombre=EQUIPO_ORDENADOR;
        while(nombre.equals(EQUIPO_ORDENADOR)){
            System.out.println("Dame el nombre de tu equipo (distinto de 'Droide')");
            nombre=sc.nextLine();
        }
        //Monta los dos equipos
        ordenador=Robot.montaEquipo(EQUIPO_ORDENADOR);
        humano=Robot.montaEquipo(nombre);
        //Ejecuta los turnos del juego
        do{
            contadorTurno++;
            turnoHumano();
            turnoOrdenador();
            muestraEquipo(humano);
            muestraEquipo(ordenador);
        }while(cuentaActivos(humano)>0 && cuentaActivos(ordenador)>0);
        //Informa del éxito o fracaso
        if(cuentaActivos(humano)>0){
            System.out.println("¡Has ganado!");
        }else{
            System.out.println("¡Has perdido!");
        }
    }
    
    private static int cuentaActivos(Robot[] equipo){
        int resultado=0;
        for(Robot r:equipo){
            if(r.getIntegridad()>0) resultado++;
        }
        return resultado;
    }
    
    private static void muestraEquipo(Robot[] equipo){
        for(Robot r:equipo){
            System.out.print(r+"   ");
        }
        System.out.println("");
    }
    
    private static void turnoHumano(){
        int atacante,donante, objetivo,receptor;
        System.out.println("-----------TURNO HUMANO ("+contadorTurno+")-----------");

        //Uno para atacar
        System.out.println("Elige un atacante: ");
        atacante=sc.nextInt();
        sc.nextLine();
        if(eleccionValida(atacante)){
            System.out.println("Elige un objetivo: ");
            objetivo=sc.nextInt();
            sc.nextLine();
            if(eleccionValida(objetivo)){
                System.out.println("Elige intensidad: ");
                int intensidad=sc.nextInt();
                sc.nextLine();
                humano[atacante-1].ataca(ordenador[objetivo-1], intensidad);
            }
        }

        //Otro para ayudar (puede ser el mismo)
        System.out.println("Elige un donante: ");
        donante=sc.nextInt();
        sc.nextLine();
        if(eleccionValida(donante)){
            System.out.println("Elige un receptor: ");
            receptor=sc.nextInt();
            sc.nextLine();
            if(eleccionValida(receptor)){
                System.out.println("Elige cantidad: ");
                int cantidad=sc.nextInt();
                sc.nextLine();
                humano[donante-1].ayuda(cantidad, humano[receptor-1]);
            }
        }

        //El resto descansan (los que sigan vivos)
        for(int i=1;i<=Robot.ROBOTS_POR_EQUIPO;i++){
            if(i!=atacante && i!=donante && humano[i-1].getIntegridad()>0){
                humano[i-1].descansa();
            }
        }
    }

    private static void turnoOrdenador(){
        int atacante,donante, objetivo,receptor;
        System.out.println("-----------TURNO ORDENADOR ("+contadorTurno+")-----------");

        //Uno para atacar
        atacante=(int)(Math.random()*Robot.ROBOTS_POR_EQUIPO+1);
        System.out.println("Eligiendo atacante..."+atacante);
        objetivo=(int)(Math.random()*Robot.ROBOTS_POR_EQUIPO+1);
        System.out.println("Eligiendo objetivo..."+objetivo);
        int intensidad=(int)(Math.random()*100+1);
        System.out.println("Eligiendo intensidad..."+intensidad);
        ordenador[atacante-1].ataca(humano[objetivo-1],intensidad);

        //Otro para ayudar
        donante=(int)(Math.random()*Robot.ROBOTS_POR_EQUIPO+1);
        System.out.println("Eligiendo un donante..."+donante);
        receptor=(int)(Math.random()*Robot.ROBOTS_POR_EQUIPO+1);
        System.out.println("Eligiendo un receptor..."+receptor);
        int cantidad=(int)(Math.random()*100+1);
        System.out.println("Eligiendo cantidad..."+cantidad);
        ordenador[donante-1].ayuda(cantidad, ordenador[receptor-1]);

        //El resto descansan
        for(int i=1;i<=Robot.ROBOTS_POR_EQUIPO;i++){
            if(i!=atacante && i!=donante && ordenador[i-1].getIntegridad()>0){
                ordenador[i-1].descansa();
            }
        }
    }

    private static boolean eleccionValida(int indice){
        if(indice<1 || indice>Robot.ROBOTS_POR_EQUIPO){
            System.out.println("Mala elección. Elige mejor la próxima vez");
            return false;
        }else{
            return true;
        }
    }
}
