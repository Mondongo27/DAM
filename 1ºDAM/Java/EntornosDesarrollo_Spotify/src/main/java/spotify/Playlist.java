package spotify;
import java.util.ArrayList;

public class Playlist {
    private String nombre;
    private ArrayList<Cancion> canciones;
    private int duracionTotal;
    
    public Playlist(String nombre){
        this.nombre=nombre;
        canciones=new ArrayList<>();
        this.duracionTotal = 0;
    }
    public String get_nombre(){
        return nombre;
    }
    public ArrayList<Cancion> get_canciones(){
        return canciones;
    }
    public int get_duracionTotal(){
        return duracionTotal;
    }
    public void set_nombre(String nombre){
        this.nombre=nombre;
    }
    public void set_canciones(ArrayList<Cancion> canciones){
        this.canciones=canciones;
    }
    public void set_duracionTotal(int duracionTotal){
        this.duracionTotal=duracionTotal;
    }

    @Override

    public String toString(){
        String s="Nombre: "+nombre+"Duracion: "+duracionTotal+"\n";
        for(int i=0;i<canciones.size();i++){
            s=s+canciones.get(i).toString();
        }
        return s;
    }

    public void mostrarPlaylist(){
        System.out.println(toString());
    }

    public boolean anadirCanciones(Cancion cancion){
        canciones.add(cancion);
        duracionTotal += cancion.get_duracion();
        return true;
    }
    
}
