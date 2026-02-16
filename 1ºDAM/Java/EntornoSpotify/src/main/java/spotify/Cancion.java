package spotify;

public class Cancion {
    private String titulo;
    private String artista;
    private int duracion;
    private int reproducciones;

    public Cancion(String titulo, String artista, int duracion){
        this.titulo=titulo;
        this.artista=artista;
        this.duracion=duracion;
        this.reproducciones=0;
    }

    public String get_titulo(){
        return titulo;
    }
    public String get_artista(){
        return artista;
    }
    public int get_duracion(){
        return duracion;
    }
    public int get_reproducciones(){
        return reproducciones;
    }
    public void set_titulo(String titulo){
        this.titulo=titulo;
    }
    public void set_artista(String artista){
        this.artista=artista;
    }
    public void set_duracion(int duracion){
        this.duracion=duracion;
    }
    public void set_reproducciones(int reproducciones){
        this.reproducciones=reproducciones;
    }
    
    public void reproducir(){
        reproducciones++;
    }

    @Override

    public String toString(){
        String s="Titulo: "+titulo+"Artista: "+artista+"Duracion: "+duracion+"Reproducciones: "+reproducciones;
        return s;
    }
}
