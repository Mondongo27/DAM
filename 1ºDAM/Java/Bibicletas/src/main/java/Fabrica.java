import iestr.var.bicicleta.Bici;
import iestr.var.bicicleta.Extra;
import iestr.var.bicicleta.Pro;
import iestr.var.bicicleta.Tipo;

public class Fabrica {
    public static void main(String[] args) {
        //Bicicletas básicas
        Extra[] extras1=new Extra[]{Extra.GUARDABARROS,Extra.SOPORTE_MOVIL};
        Bici b1=new Bici(Tipo.CARBONO,"Transparente",extras1);
        System.out.println(b1);
        b1.rodar(5);
        Bici b2=new Bici(Tipo.MADERA,"Ébano");
        System.out.println(b2);
        b2.rodar(7);
        Bici b3=new Bici();
        System.out.println(b3);
        b3.rodar(123);
        
        //Bicicletas pro
        Extra[] extras2=new Extra[]{Extra.SOPORTE_MOVIL,Extra.LUCES,Extra.RUEDA_GORDA};
        Pro p1=new Pro(50,true,true,Tipo.MADERA,"Marfil",extras2);
        System.out.println(p1);
        p1.rodar(1000);
        p1.subir();
        Pro p2=new Pro(20,true,false,Tipo.ALUMNIO,"Acero templado");
        System.out.println(p2);
        p2.rodar(2000);
        p2.bajar();
        Pro p3=new Pro();
        System.out.println(p3);
        p3.rodar(3000);
        for(int i=0;i<4;i++) p3.subir();
    }
    
    
}
