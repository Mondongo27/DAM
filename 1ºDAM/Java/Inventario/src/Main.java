import com.juego.Item;
import com.juego.Personaje;

public class Main {
    public static final String NOMBRE_JUGADOR = "Juan";
    public static final String ITEM_DINERO = "Dinero";
    public static final String ITEM_COMIDA = "Comida";
    public static final String ITEM_AGUA = "Agua";
    public static final String ITEM_SEMILLAS = "Semillas";
    public static void main(String[] args) {
        Personaje jugador=new Personaje(NOMBRE_JUGADOR);
        jugador.mostrarEstado();
        jugador.anadirItem(new Item(ITEM_DINERO, 50));
        jugador.anadirItem(new Item(ITEM_COMIDA, 10));
        jugador.anadirItem(new Item(ITEM_AGUA, 5));
        jugador.gastarItem(ITEM_COMIDA,40);
        jugador.anadirItem(new Item(ITEM_SEMILLAS, 5));//Debe fallar
        jugador.anadirItem(new Item(ITEM_DINERO, 30));
        jugador.mostrarEstado();
        jugador.gastarItem(ITEM_DINERO, 20);
        jugador.gastarItem(ITEM_COMIDA, 10);
        jugador.mostrarEstado();
        jugador.anadirItem(new Item(ITEM_SEMILLAS, 3));//Este sí debe permitirlo
        jugador.mostrarEstado();
    }
}
