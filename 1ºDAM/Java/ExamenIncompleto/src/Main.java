import com.gag.examen.Incidencia;
import com.gag.examen.Presupuesto;
import com.gag.examen.Proyecto;

public class Main {

    public static void main(String[] args) {

        //Creación y prolongación de proyectos

        Proyecto primero=new Proyecto("Primer proyecto");
        Proyecto segundo=new Proyecto("Segundo proyecto");
        System.out.println(primero);
        System.out.println(segundo);
        System.out.println("-----------------------------");
        primero.prolongar(20);
        System.out.println(primero);
        System.out.println(segundo);

        System.out.println("********************************************************************");

        Presupuesto barato=new Presupuesto(1000,0,0,0);
        Proyecto tercero=new Proyecto("Tercer proyecto", barato, 5);
        Proyecto cuarto=new Proyecto("Cuarto proyecto", barato, 5);
        System.out.println(tercero);
        System.out.println(cuarto);
        System.out.println("-----------------------------");
        tercero.prolongar(5);
        System.out.println(tercero);
        System.out.println(cuarto);

        System.out.println("/////////////////////////////////////////////////////////////////////////");
        System.out.println("/////////////////////////////////////////////////////////////////////////");

        //Registro y resolución de incidencias

        segundo.registraIncidencia("Muro de contención",4444);
        segundo.registraIncidencia("Explosión propano",5555);
        segundo.registraIncidencia("Faltan bocadillos",150);//Fallará por falta de presupuesto
        System.out.println(segundo);
        System.out.println("-----------------------------");
        segundo.resuelveIncidencia(3);
        segundo.resuelveIncidencia(1);
        segundo.resuelveIncidencia(1);//Fallará porque ya está resuelta
        System.out.println(segundo);
        System.out.println("-----------------------------");

//        System.out.println("Intento fallido de modificación fraudulenta de incidencias:");
//        //TODO: pide la lista de incidencias del proyecto "segundo".
        Incidencia[] lista=segundo.getIncidencias();
//        //fin del TODO
//
//        //Intentamos "trampear" el proyecto cambiando los datos de la primera incidencia
//        lista[0]=new Incidencia(1,"Ficticia",101.0f);
//        //El intento de trampa debe haber fallado. Al mostrar los datos del proyecto no han variado
//        System.out.println(segundo);
    }
}
