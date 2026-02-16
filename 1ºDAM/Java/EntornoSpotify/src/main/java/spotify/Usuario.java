package spotify;
import java.util.ArrayList;

public class Usuario {
    private String nombre;
    private String email;
    private ArrayList<Playlist> playlist;

    public Usuario(String nombre, String email){
        this.nombre = nombre;
        playlist = new ArrayList<>();
        this.email = email;
    }
    public String get_nombre(){
        return nombre;
    }
    public String get_email(){
        return email;
    }
    public ArrayList<Playlist> get_playlist(){
        return playlist;
    }
    public void set_nombre(String nombre){
        this.nombre=nombre;
    }
    public void set_email(String email){
        this.email=email;
    }
    public void set_playlist(ArrayList<Playlist> playlist){
        this.playlist=playlist;
    }

    public void crearPlaylist(String nombre){
        Playlist p=new Playlist(nombre);
        playlist.add(p);

        for(int i=0;i<playlist.size(); i++){
            String n=playlist.get(i).get_nombre();
            if(nombre==n){
                nombre=nombre+"1";
            }
        }
    }

    public void mostrarPlaylist(){
        System.out.println(toString());
    }
}