import com.gag.Empleado;
import com.gag.Puesto;

import java.util.Objects;
import java.util.Scanner;

public class Main {
    //Elementos del menú
    public static final String MENU_1 = "1. Dar de alta un puesto de trabajo";
    public static final String MENU_2 = "2. Modificar el salario de un puesto de trabajo";
    public static final String MENU_3 = "3. Dar de alta un empleado fijo";
    public static final String MENU_4 = "4. Dar de alta un empleado provisional";
    public static final String MENU_5 = "5. Cambiar de puesto a un empleado";
    public static final String MENU_6 = "6. Modificar el complemento de un empleado";
    public static final String MENU_7 = "7. Mostrar los puestos de trabajo existentes";
    public static final String MENU_8 = "8. Mostrar la lista de empleados";
    public static final String MENU_0 = "0. Salir";
    public static final String MENU_ELIGE = "Elige una opcion: ";
    //Mensajes para las diferentes opciones
    public static final String PREGUNTA_DESCRIPCION = "Dime la descripción del puesto: ";
    public static final String PREGUNTA_SALARIO = "Dime el salario para ese puesto: ";
    public static final String ERROR_MUCHOS_PUESTOS = "ERROR: No puedes crear más de %d puestos de trabajo\n";
    public static final String ERROR_DESCRIPCION_REPETIDA = "ERROR: No puedes crear ese puesto. Ya existe";
    //No se usa para nada ya que nunca tiene conlfictos porque usamos los Contadores y el puesto de practicas
    //No cuenta para aumentar el contador
    //public static final String ERROR_PUESTO_PRUEBAS = "ERROR: El puesto '%s' existe por defecto y no se puede sobreescribir\n";
    public static final String OK_PUESTO_CREADO = "...Creando puesto...OK: %s\n";
    public static final String PREGUNTA_PUESTO = "Dime el número del puesto: ";
    public static final String ERROR_PUESTO_NO_EXISTE = "ERROR: Ese puesto no existe";
    public static final String OK_SALARIO_MODIFICADO = "...Modificando salario del puesto...OK: %s\n";
    public static final String ERROR_MUCHOS_EMPLEADOS = "ERROR: No puedes dar de alta más de %d empleados\n";
    public static final String PREGUNTA_NOMBRE = "Dime el nombre del empleado: ";
    public static final String PREGUNTA_COMPLEMENTO = "Dime el complemento salarial: ";
    public static final String OK_ALTA_EMPLEADO = "...Dando de alta empleado...OK: %s\n";
    public static final String PREGUNTA_EMPLEADO = "Dime el id del empleado: ";
    public static final String ERROR_EMPLEADO_NO_EXISTE = "ERROR: Ese empleado no existe";
    public static final String OK_ASIGNACION_EMPLEADO = "...Reasignando empleado...OK: %s\n";
    //Esta cadena no se acaba usando ya que no hace falta para el funcionamiento y no se por que esta
    //public static final String ERROR_ASIGNACION_EMPLEADO = "ERROR: no puedes REasignar un empleado a %s";
    public static final String OK_COMPLEMENTO_MODIFICADO = "...Modificando complemento del empleado...OK: %s\n";
    public static final String MUESTRA_PUESTOS = "%d %s\n";
    public static final String MUESTRA_EMPLEADOS = "%s\n";
    //General
    private static final Scanner sc = new Scanner(System.in);
    //Para los puestos
    private static final int MAX_PUESTOS=10;
    private static int contadorPuestos=0;
    private static final Puesto[] puestos = new Puesto[MAX_PUESTOS];
    //Para los empleados
    private static final int MAX_EMPLEADOS=100;
    private static int contadorEmpleados=0;
    private static final Empleado[] empleados = new Empleado[MAX_EMPLEADOS];
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public static void main(String[] args) {
        int opcion;
        do {
            presentaMenu();
            opcion = leeInt();
            procesaOpcion(opcion);
        } while (opcion != 0);
    }

    private static void presentaMenu() {
        System.out.println();
        System.out.println(MENU_1);
        System.out.println(MENU_2);
        System.out.println(MENU_3);
        System.out.println(MENU_4);
        System.out.println(MENU_5);
        System.out.println(MENU_6);
        System.out.println(MENU_7);
        System.out.println(MENU_8);
        System.out.println(MENU_0);
        System.out.print(MENU_ELIGE);
    }

    private static void procesaOpcion(int opcion) {
        switch (opcion) {
            case 1:
                altaPuesto();
                break;
            case 2:
                modificaSalarioBase();
                break;
            case 3:
                altaEmpleadoFijo();
                break;
            case 4:
                altaEmpleadoProvisional();
                break;
            case 5:
                cambiarDePuesto();
                break;
            case 6:
                modificaComplemento();
                break;
            case 7:
               muestraPuestos();
                break;
            case 8:
                muestraEmpleados();
                break;
        }
    }

    ///////////////////////////////////////     opciones        ////////////////////////////////////////////////////////
    private static void altaPuesto() {
        String descripcion;
        float salario;
        boolean repetido;
        Puesto nuevo;
        if(contadorPuestos>=MAX_PUESTOS){
            System.out.printf(ERROR_MUCHOS_PUESTOS,MAX_PUESTOS);
            return;
        }
        //si llego aquí, es que todavía puedo crear puestos
        System.out.print(PREGUNTA_DESCRIPCION);
        descripcion = sc.nextLine();
        //Compruebo si la descripción que me da ya existe
        repetido = false;
        //Compruebo que su descripcion no sea la misma que la del puesto de pruebas
        if(Objects.equals(descripcion, Puesto.PUESTO_PRUEBAS.getDescripcion())){
            repetido=true;
        }
        //Compruebo que la descripcion no exista ya
        for(int i=0;i<contadorPuestos;i++){
            if(puestos[i].getDescripcion().equalsIgnoreCase(descripcion)){
                repetido=true;
            }
        }

        if (repetido) {//no puedo crear puestos con una descripción repetida
            System.out.println(ERROR_DESCRIPCION_REPETIDA);
            return;
        }
        //Si llego hasta aquí es que, en principio, puedo crearlo
        System.out.print(PREGUNTA_SALARIO);
        salario = leeFloat();
        nuevo = new Puesto(descripcion,salario);
        //Recordar que al crear algo nuevo hay que meterlo en el array que si no al buscarlo no se encuentra y peta
        puestos[contadorPuestos]=nuevo;
        contadorPuestos++;
        //No se por que el codigo te añade este comprobador de si es null ya que antes de el ya has creado el puesto
        //si todo lo anterior ha salido bien
//        if (nuevo == null) {// No he podido crear el puesto porque la descripción coincide con la de pruebas
//            System.out.printf(ERROR_PUESTO_PRUEBAS, Puesto.PUESTO_PRUEBAS);
//            return;
//        }
        //Si llego hasta aquí es que el puesto nuevo se ha creado correctamente
        System.out.printf(OK_PUESTO_CREADO,nuevo);
    }

    private static void modificaSalarioBase() {
        int puesto;
        float salario;
        System.out.print(PREGUNTA_PUESTO);
        puesto = leeInt();
        if(puesto<=0 || puesto>contadorPuestos){
            System.out.println(ERROR_PUESTO_NO_EXISTE);
            return;
        }
        System.out.println(PREGUNTA_SALARIO);
        salario = leeFloat();
        puestos[puesto-1].setSalario(salario);
        System.out.printf(OK_SALARIO_MODIFICADO,puestos[puesto-1]);
    }

    private static void altaEmpleadoFijo() {
        String nombre;
        int puesto;
        float complemento;
        Empleado nuevo;
        if (!puedoCrearEmpleados()) return;
        //Si llego hasta aquí es que todavía puedo dar de alta un empleado
        System.out.print(PREGUNTA_PUESTO);
        puesto = leeInt();
        if(puesto<=0 || puesto>contadorPuestos){
            System.out.println(ERROR_PUESTO_NO_EXISTE);
            return;
        }
        System.out.print(PREGUNTA_NOMBRE);
        nombre = sc.nextLine();
        System.out.print(PREGUNTA_COMPLEMENTO);
        complemento = leeFloat();
        //Instanciamos y guardamos el nuevo empleado
        nuevo = new Empleado(nombre,puestos[puesto-1],complemento);
        empleados[contadorEmpleados]=nuevo;
        System.out.printf(OK_ALTA_EMPLEADO,empleados[contadorEmpleados]);
        contadorEmpleados++;
    }

    private static void altaEmpleadoProvisional() {
        String nombre;
        Empleado nuevo;
        if (!puedoCrearEmpleados()) return;
        //Si llego hasta aquí es que todavía puedo dar de alta un empleado
        System.out.print(PREGUNTA_NOMBRE);
        nombre = sc.nextLine();
        //Instanciamos y guardamos el nuevo empleado
        nuevo = new Empleado(nombre);
        empleados[contadorEmpleados]=nuevo;
        System.out.printf(OK_ALTA_EMPLEADO,empleados[contadorEmpleados]);
        contadorEmpleados++;
    }

    private static boolean puedoCrearEmpleados() {//Para usar en las altas de empleado (fijo y provisional)
        if (Empleado.getContadorId() >= MAX_EMPLEADOS) {
            System.out.printf(ERROR_MUCHOS_EMPLEADOS, MAX_EMPLEADOS);
            return false;
        } else {
            return true;
        }
    }

    private static void cambiarDePuesto() {
        int id;
        int nuevoPuesto;
        System.out.print(PREGUNTA_EMPLEADO);
        id = leeInt();
        if (id < 1 || id > Empleado.getContadorId()) {
            System.out.println(ERROR_EMPLEADO_NO_EXISTE);
            return;
        }
        System.out.print(PREGUNTA_PUESTO);
        nuevoPuesto = leeInt();
        if(nuevoPuesto<=0 || nuevoPuesto>contadorPuestos){
            System.out.println(ERROR_PUESTO_NO_EXISTE);
            return;
        }
        //Si llego aquí es que he introducido un empleado y un puesto de destino correctos
        empleados[id-1].setPuesto(puestos[nuevoPuesto-1]);
        System.out.printf(OK_ASIGNACION_EMPLEADO,empleados[id-1]);
    }

    private static void modificaComplemento() {
        int id;
        float complemento;
        System.out.print(PREGUNTA_EMPLEADO);
        id = leeInt();
        if (id < 1 || id > Empleado.getContadorId()) {
            System.out.println(ERROR_EMPLEADO_NO_EXISTE);
            return;
        }
        System.out.print(PREGUNTA_COMPLEMENTO);
        complemento = leeFloat();
        empleados[id-1].setComplemento(complemento);
        System.out.printf(OK_COMPLEMENTO_MODIFICADO,empleados[id-1]);
    }

    private static void muestraPuestos() {
        System.out.print(Puesto.PUESTO_PRUEBAS + "\n");
        for(int i=0;i<contadorPuestos;i++){
            System.out.printf(MUESTRA_PUESTOS,i+1,puestos[i]);
        }
    }

    private static void muestraEmpleados() {
        for(int i=0;i<contadorEmpleados;i++){
            System.out.printf(MUESTRA_EMPLEADOS,empleados[i]);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Se usa para leer valores float
    private static float leeFloat() {
        float resultado;
        while (!sc.hasNextFloat()) sc.next();
        resultado = sc.nextFloat();
        sc.nextLine();
        return resultado;
    }

    private static int leeInt() {
        int resultado;
        while (!sc.hasNextInt()) sc.next();
        resultado = sc.nextInt();
        sc.nextLine();
        return resultado;
    }
}