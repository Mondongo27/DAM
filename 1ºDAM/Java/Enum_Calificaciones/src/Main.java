import iestr.gag.calif.Alumno;
import iestr.gag.calif.Calificacion;

public class Main {
    public static void main(String[] args) {
        int longitud=Calificacion.values().length;
        System.out.println("Elementos "+longitud);
        System.out.println("-----------------------");
        for(Calificacion c:Calificacion.values()){
            System.out.println(c);
        }
        System.out.println("-----------------------");



        Alumno ana=new Alumno("Ana Alvarez", Calificacion.NOTABLE);
        System.out.println(ana);
        Alumno blas=new Alumno("Blas Bueno", Calificacion.SUSPENSO);
        System.out.println(blas);
    }
}