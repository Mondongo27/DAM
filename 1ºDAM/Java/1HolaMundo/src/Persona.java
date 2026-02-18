public class Persona {
    String nombre;
    int edad;

    public Persona(String n,int e){
        nombre=n;
        edad=e;
        hablar("¡Ya estoy aquí!");
    }

    public void hablar(String mensaje){
        System.out.printf("%s: %s\n",nombre,mensaje);
    }

    public void reir(int carcajadas){
        if(carcajadas<=0) carcajadas=1;
        String risa="¡";
        for(int i=1;i<carcajadas;i++){
            risa=risa+" JA ";
        }
        risa+="!";
        hablar(risa);
    }

    @Override
    public String toString(){
        return(nombre+edad);
    }
}