public class Tiempo {
    private int horas;
    private int minutos;
    private int segundos;

    public Tiempo(int horas, int minutos, int segundos) {
        this.horas = Math.max(horas,0);
        this.minutos = Math.max(minutos,0);
        this.segundos = Math.max(segundos,0);
        normalizar();
    }

    public Tiempo(int segundos){
        this(0,0,segundos);
    }

    private void normalizar(){
        int segundosNormalizados=segundos%60;
        int minutosExtra=segundos/60;
        minutos+=minutosExtra;
        int minutosNormalizados=minutos%60;
        int horasExtra=minutos/60;
        horas+=horasExtra;
        minutos=minutosNormalizados;
        segundos=segundosNormalizados;
    }

    private static int desnormalizar(Tiempo t){
        return (t.horas*3600+t.minutos*60+t.segundos);
    }

    public static Tiempo sumar(Tiempo primero,Tiempo segundo){
        return new Tiempo(
                primero.horas+segundo.horas,
                primero.minutos+segundo.minutos,
                primero.segundos+segundo.segundos
        );
    }

    public static Tiempo sumar(Tiempo primero,int cantSeg){
        int segundos=desnormalizar(primero);
        return new Tiempo(
                0,
                0,
                Math.max(segundos+cantSeg,0)
        );
    }

    public static Tiempo sumar(int seg1,int seg2){
        return new Tiempo(0,0,seg1+seg2);
    }

    public void sumar(Tiempo otro){
        sumar(desnormalizar(otro));
//        this.horas+=otro.horas;
//        this.minutos+=otro.minutos;
//        this.segundos+=otro.segundos;
//        normalizar();
    }

    public void sumar(int cantSeg){
        int segundos=desnormalizar(this);
        this.horas=0;
        this.minutos=0;
        this.segundos=Math.max(segundos+cantSeg,0);
        normalizar();
    }

    public void restar(Tiempo otro){
        int segundos=-desnormalizar(otro);
        sumar(segundos);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder();
        sb.append(horas).append(":").append(String.format("%02d",minutos)).append(":").append(String.format("%02d",segundos));
        return sb.toString();
    }
}

package com.mycompany.examen;

public class Robot {
    public static final int VALOR_MAXIMO = 100;
    public static final int ROBOTS_POR_EQUIPO = 3;
    private static final double PORCENTAJE_EFECTIVIDAD = 0.5;
    private static final int ENERGIA_DESCANSO = 10;
    private static int contador = 0;

    private String nombre;
    private int energia;
    private int integridad;

    public Robot(String nombreEquipo, int energia, int integridad) {
        contador++;
        this.nombre = nombreEquipo + (contador % ROBOTS_POR_EQUIPO == 0 ? ROBOTS_POR_EQUIPO : contador % ROBOTS_POR_EQUIPO);
        this.energia = (energia < 1) ? 1 : (energia > 100) ? 100 : energia;
        this.integridad = (integridad < 1) ? 1 : (integridad > 100) ? 100 : integridad;
        this.saluda();
    }

    public Robot(String nombreEquipo, int energia) {
        this(nombreEquipo, energia, VALOR_MAXIMO - energia);
    }

    public Robot(String nombreEquipo) {
        this(nombreEquipo, (int) (Math.random() * 100 + 1));
    }

    public int getIntegridad() {
        return integridad;
    }

    public void saluda() {
        System.out.println(this.toString() + ": listo");
    }

    public void ataca(Robot objetivo, int intensidad) {
        if (this.integridad <= 0) {
            System.out.println(this.toString() + ": estoy eliminado de la partida");
            return;
        }
        if (this.energia <= 0) {
            System.out.println(this.toString() + ": no tengo energía para pelear");
            return;
        }
        if (intensidad <= 0) {
            System.out.println(this.toString() + ": eso es una tontería");
            return;
        }
        if (objetivo.integridad <= 0) {
            System.out.println(objetivo.toString() + " está eliminado. No es ético atacarle");
            return;
        }

        System.out.println(this.toString() + ": atacando a " + objetivo.toString());

        int energiaEmpleada = Math.min(this.energia, intensidad);
        this.energia -= energiaEmpleada;

        int daño = (int) (energiaEmpleada * PORCENTAJE_EFECTIVIDAD);
        objetivo.integridad -= daño;

        if (objetivo.integridad <= 0) {
            objetivo.integridad = 0;
            System.out.println(objetivo.toString());
        }

        if (this.energia <= 0) {
            this.energia = 0;
            System.out.println(this.toString() + ": agotado");
        }
    }

    public void descansa() {
        if (this.integridad > 0) {
            this.energia = Math.min(VALOR_MAXIMO, this.energia + ENERGIA_DESCANSO);
            System.out.println(this.toString() + ": descansando");
        }
    }

    public void ayuda(int cantidad, Robot receptor) {
        if (this.integridad <= 0) {
            System.out.println(this.toString() + ": estoy eliminado de la partida");
            return;
        }
        if (receptor == this) {
            System.out.println(this.toString() + ": no me puedo ayudar a mi mismo");
            return;
        }
        if (receptor.integridad <= 0) {
            System.out.println(this.toString() + ": ya es tarde para él. " + receptor.toString() + " es irrecuperable");
            return;
        }

        int trasvase = Math.min(this.integridad, cantidad);
        this.integridad -= trasvase;
        receptor.integridad = Math.min(VALOR_MAXIMO, receptor.integridad + trasvase);

        System.out.println(this.toString() + ": trasvasando " + trasvase + " uds. de integridad a " + receptor.toString());

        if (this.integridad <= 0) {
            this.integridad = 0;
            System.out.println(this.toString());
        }
    }

    @Override
    public String toString() {
        if (this.integridad <= 0) {
            return nombre + " (desactivado)";
        } else {
            return nombre + " (E:" + energia + ", I:" + integridad + ")";
        }
    }

    public static Robot[] montaEquipo(String nombre) {
        Robot[] equipo = new Robot[ROBOTS_POR_EQUIPO];
        equipo[0] = new Robot(nombre, 100, 100);
        equipo[1] = new Robot(nombre, 60);
        equipo[2] = new Robot(nombre);
        return equipo;
    }
}