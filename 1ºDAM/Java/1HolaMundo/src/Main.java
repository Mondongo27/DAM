import java.util.Scanner;

public class Main {
    static void main() {
        Persona p1=new Persona("Pepe",40);
        Persona p2=new Persona("Ana",30);
        Persona p3=new Persona("Ana",30);
        p1.hablar("Hola!");
        p2.hablar("Ah, Hola!");
        System.out.println(p1);
        System.out.println(p2);
        System.out.println(p3);
    }
}