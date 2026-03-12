package com.gag.examen;

public class Proyecto {
    private static int MAX_INCIDENCIAS=100;
    private static final Presupuesto PRESUPUESTO_DEFECTO=new Presupuesto(50000,2000,10000,10000);
    private static int DIAS_DEFECTO=30;

    private final String nombre;
    private int dias;
    private final Presupuesto presupuesto;
    private final Incidencia[] incidencias;
    private int contadorIncidencias;
    private float costeIncidencias;

    public Proyecto(String nombre, Presupuesto presupuesto, int dias) {
        this.nombre = nombre;
        this.presupuesto = presupuesto.clonar();
        this.dias = dias;
        incidencias=new Incidencia[MAX_INCIDENCIAS];
        contadorIncidencias=0;
        costeIncidencias=0;
    }
    public Proyecto(String nombre) {
        this(nombre, PRESUPUESTO_DEFECTO,  DIAS_DEFECTO);
    }

    public void registraIncidencia(String nombre,float coste){
        if(contadorIncidencias>=MAX_INCIDENCIAS){
            System.out.printf("[%s]ERROR: No se pueden registrar mas incidencias\n", this.nombre);
        }else if(costeIncidencias+coste>presupuesto.getImprevistos()){
            System.out.printf("[%s]ERROR: No llega el presupuesto \n", this.nombre);
        }else{
            Incidencia nueva=new Incidencia(contadorIncidencias+1,nombre,coste);
            incidencias[contadorIncidencias]=nueva;
            contadorIncidencias++;
            costeIncidencias+=coste;
            System.out.printf("[%s]Resolviendo incidencia ... %s\n",this.nombre,nueva);
        }
    }

    public void resuelveIncidencia(int id){
        if(id>contadorIncidencias || id<1){
            System.out.printf("[%s]ERROR: la incidencia %d no existe\n",nombre,id);
        }else{
            if(incidencias[id-1].resolver()){
                System.out.printf("[%s]Resolviendo incidencia ... %s\n", nombre,incidencias[id]);
            }else{
                System.out.printf("[%s]ERROR: La incidencia %d ya estaba resuelta!!\n",nombre,id);
            }
        }
    }

    public void prolongar(int periodo){
        if(periodo<=0) return;
        float factor=(dias+periodo)/(dias*1.0f);
        dias+=periodo;
        presupuesto.prolongar(factor);
    }

    @Override
    public String toString() {
        StringBuilder sb=new StringBuilder(nombre.toUpperCase())
                .append("\n\tDuración: ").append(dias).append(" días")
                .append("\n\t").append(presupuesto)
                .append("\n\tIncidencias(").append(String.format("%.2f",costeIncidencias)).append("€)");
        for(int i=0;i<contadorIncidencias;i++){
            sb.append("\n\t\t").append(incidencias[i]);
        }
        return sb.toString();
    }

    public Incidencia[] getIncidencias() {
        return incidencias;
    }
}
