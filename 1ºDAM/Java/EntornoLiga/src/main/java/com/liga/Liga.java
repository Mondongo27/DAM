package com.liga;
import java.util.ArrayList;
import java.util.List;

public class Liga {
    private List<Equipo> equipos;
    private List<Partidos> partidos;

    public Liga(){
        equipos = new ArrayList<>();
        partidos = new ArrayList<>();
    };

    public List<Equipo> getequipos(){
        return equipos;
    }
    public void setequipos(List<Equipo> equipos){
        this.equipos=equipos;
    }
    public List<Partidos> getpartidos(){
        return partidos;
    }
    public void setpartidos(List<Partidos> partidos){
        this.partidos=partidos;
    }
    public static void main(String[] args) {
        
    }
    public void registrarPartido(Partidos partido){
        partidos.add(partido);
        partido.registrarPartido();
    }
    public void registrarEquipo(Equipo equipo){
        equipos.add(equipo);
    }
    public void mostrarClasificacion(){
        equipos.sort((e1,e2) -> {
            if(e2.getpuntos() != e1.getpuntos()) {
                return Integer.compare(e2.getpuntos(),e1.getpuntos());
            }
            return Integer.compare(e2.getgoles_favor(),e1.getgoles_favor());
        });

        System.out.println("Clasificacion:");
        for (Equipo equipo : equipos) {
            System.out.println(equipo);
        }
    }

    public Equipo buscarEquipoPorNombre(String nEquipo){
        for(int i=0; equipos.size()>i;i++) {
            if(equipos.get(i).getnEquipo().equalsIgnoreCase(nEquipo)) {
                Equipo e=equipos.get(i);
                System.out.println(e);
                return e;
            }
        }
        System.out.println("Equipo no encontrado.");
        return null;
    }

        public boolean buscarEquipo(String nEquipo){
        for(int i=0; equipos.size()>i;i++) {
            if(equipos.get(i).getnEquipo().equalsIgnoreCase(nEquipo)) {
                Equipo e=equipos.get(i);
                System.out.println(e);
                return true;
            }
        }
        System.out.println("Equipo no encontrado.");
        return false;
    }

    public void listaPartidos(){
        System.out.println("Partidos jugados:");
        for(int i=0; partidos.size()>i;i++){
            Partidos p= partidos.get(i);
            System.out.println(p);
        }
    }
}