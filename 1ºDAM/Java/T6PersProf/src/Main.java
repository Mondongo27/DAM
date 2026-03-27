import iestr.var.herencia.Alumno;
import iestr.var.herencia.Persona;
import iestr.var.herencia.Maestro;

public class Main {
    public static void main(String[] args) {
        Persona p1=new Persona(1111111,"Juan");
        p1.saludar();
        p1.andar(5);

        Maestro m1=new Maestro(1,"Gustavo Fring","Programación");
        m1.saludar();
        m1.andar(3);

        Alumno a1=new Alumno(1,"Caca","DAM");
        a1.saludar();
        a1.andar(3);
    }
}