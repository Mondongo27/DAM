package com.liga;
import java.util.Date;

public class Partidos {
    private Equipo eqlocal;
    private Equipo eqVisitante;
    private int gEqLocal;
    private int gEqVisitante;
    private Date fecha;  

    public Partidos (Equipo eqlocal, Equipo eqVisitante, int gEqLocal, int gEqVisitante, Date fecha){
        this.eqlocal=eqlocal;
        this.eqVisitante=eqVisitante;
        this.gEqLocal=gEqLocal;
        this.gEqVisitante=gEqVisitante;
        this.fecha=fecha;
    }
   
    @Override
    public String toString() {
        return eqlocal + " " + gEqLocal + " - " + gEqVisitante + " " + eqVisitante +
        "| Fecha: " + fecha;
    }

    public void registrarPartido(){
        eqlocal.setgoles_favor(eqlocal.getgoles_favor() + gEqLocal);
        eqVisitante.setgoles_favor(eqVisitante.getgoles_favor() + gEqLocal);
        eqlocal.setgoles_contra(eqlocal.getgoles_contra() + gEqLocal);
        eqVisitante.setgoles_contra(eqVisitante.getgoles_contra() + gEqLocal);
        if(gEqLocal > gEqVisitante) {
            eqlocal.setpuntos(eqlocal.getpuntos() + 3);
        } else if (gEqVisitante > gEqLocal) {
            eqVisitante.setpuntos(eqVisitante.getpuntos() + 3);
        } else {
            eqlocal.setpuntos(eqlocal.getpuntos() + 1);
            eqVisitante.setpuntos(eqVisitante.getpuntos() + 1);
        }
    }

    public Equipo geteqlocal(){
        return eqlocal;
    }
    public void seteqlocal(Equipo eqlocal){
        this.eqlocal=eqlocal;
    }
    public Equipo geteqVisitante(){
        return eqVisitante;
    }
    public void seteqVisitante(Equipo eqVisitante){
        this.eqVisitante=eqVisitante;
    }
    public int getgEqLocal(){
        return gEqLocal;
    }
    public void setgEqLocal(int gEqLocal){
        this.gEqLocal=gEqLocal;
    }
    public int getgEqVisitante(){
        return gEqVisitante;
    }
    public void setgEqVisitante(int gEqVisitante){
        this.gEqVisitante=gEqVisitante;
    }
    public Date getfecha(){
        return fecha;
    }
    public void setfecha(Date fecha){
        this.fecha=fecha;
    }
}