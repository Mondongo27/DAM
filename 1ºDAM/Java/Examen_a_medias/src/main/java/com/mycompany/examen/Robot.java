package com.mycompany.examen;

public class Robot {
    public static final int VALOR_MAXIMO=100;
    //Si se cambia el valor de ROBOTS_POR_EQUIPO, hay que revisar el método montaEquipo
    public static final int ROBOTS_POR_EQUIPO=3;
    private static final double PORCENTAJE_EFECTIVIDAD = 0.5;
    private static final int ENERGIA_DESCANSO = 10;

    private static int contador=0;//Debe reiniciarse cada ROBOTS_POR_EQUIPO incrementos

    private final String nombreEquipo;
    private int energia;
    private int integridad;

    //Constructores
    public Robot(String nombreEquipo, int energia, int integridad) {
        contador++;
        this.nombreEquipo = nombreEquipo+(contador%ROBOTS_POR_EQUIPO==0 ? ROBOTS_POR_EQUIPO : contador%ROBOTS_POR_EQUIPO);
        this.energia =(energia < 1) ? 1 :Math.min(energia, 100);
        this.integridad =(integridad < 1) ? 1:Math.min(integridad, 100);
        this.saluda();
    }

    public Robot(String nombreEquipo, int energia) {
        this(nombreEquipo, energia, VALOR_MAXIMO - energia);
    }

    public Robot(String nombreEquipo) {
        this(nombreEquipo, (int) (Math.random()*100+1));
    }

    public static Robot[] montaEquipo(String nombre) {
        Robot[] equipo = new Robot[ROBOTS_POR_EQUIPO];
        equipo[0] = new Robot(nombre, 100, 100);
        equipo[1] = new Robot(nombre, 60);
        equipo[2] = new Robot(nombre);
        return equipo;
    }

    //Funciones
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

        int danio= (int)(energiaEmpleada * PORCENTAJE_EFECTIVIDAD);
        objetivo.integridad -=danio;

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

    public void ayuda (int cantidad, Robot receptor){
        if (this.integridad <= 0){
            System.out.println(this.toString()+": estoy eliminado de la partida");
            return;
        }
        if(receptor==this){
            System.out.println(this.toString()+": no me puedo ayudar a mí mismo");
            return;
        }
        if(receptor.integridad==0){
            System.out.println(receptor.toString()+": ya es tarde para él. "+receptor.toString()+" es irrecuperable");
            return;
        }

        int trasvase=Math.min(this.integridad, cantidad);
        this.integridad -= trasvase;
        receptor.integridad = Math.min(VALOR_MAXIMO, receptor.integridad + trasvase);

        System.out.println(this.toString() + ": trasvasando " + trasvase + " uds. de integridad a " + receptor.toString());

        if (this.integridad <= 0) {
            this.integridad = 0;
            System.out.println(this.toString());
        }
    }

    //Otros
    @Override
    public String toString() {
        if(this.integridad<=0){
            final StringBuilder sb = new StringBuilder(nombreEquipo);
            sb.append(": (desactivado)");
            return sb.toString();
        }else{
            final StringBuilder sb = new StringBuilder(nombreEquipo);
            sb.append(" (E:").append(energia).append(", I:");
            sb.append(integridad).append(") ");
            return sb.toString();
        }
    }

    public int getIntegridad() {
        return integridad;
    }
}
