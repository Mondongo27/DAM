package iestr.var.herencia;

public class Persona {
    final int dni;
    final String nombre;

    public Persona(int dni, String nombre) {
        this.dni = dni;
        this.nombre = nombre;
    }

    public void andar(int pasos){
        System.out.printf("%s: andando %d pasos...\n",this,pasos);
    }

    public void saludar(){
        System.out.printf("%s. ¡Hola!\n",this);
    }

    @Override
    public String toString() {
        return nombre;
    }
}
