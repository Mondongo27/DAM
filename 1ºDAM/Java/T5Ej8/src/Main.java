public class Main {
    public static void main(String[] args) {
        Terminal[] lista=new Terminal[6];
        lista[0] = new Terminal("678 11 22 33");
        lista[1] = new Terminal("644 74 44 69");
        lista[2] = new Terminal("622 32 89 09");
        lista[3] = new Terminal("664 73 98 18");
        lista[4] = new Terminal("123 45 67 89");
        lista[5] = new Terminal("669 99 66 96");
        Terminal yo=new Terminal("987 12 34 56");
        for(int i=0;i<lista.length;i++){
            yo.llama(lista[i],i*10);
        }
        for(Terminal t:lista){
            System.out.println(t);
        }
    }
}