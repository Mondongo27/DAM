import com.var.Bicicleta;
import com.var.Coche;
import com.var.Vehiculo;
import java.util.Scanner;

public class Main{
    static Scanner sc=new Scanner(System.in);
    static void main(String[] args){
        int opcion;
        System.out.println("VEHÍCULOS\n" +
                "=========\n" +
                "1. Anda con la bicicleta\n" +
                "2. Haz el caballito con la bicicleta\n" +
                "3. Anda con el coche\n" +
                "4. Quema rueda con el coche\n" +
                "5. Ver kilometraje de la bicicleta\n" +
                "6. Ver kilometraje del coche\n" +
                "7. Ver kilometraje total\n" +
                "8. Salir\n" +
                "Elige una opción (1-8):\n"
        );
    }
    static int pideEnteroPositivo(){
        int resultado=-1;
        do{
            if(sc.hasNextInt()){
                resultado=sc.nextInt();
            }
            sc.nextLine();
        }while(resultado<=0);
        return resultado;
    }
}
