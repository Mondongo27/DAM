package com.gag.examen;

public class Presupuesto {
    private static final int IMPORTE_MINIMO=1;

    private float nominas;
    private final float licencia;
    private float horas_extra;
    private float imprevistos;
    private float total;

    public Presupuesto(float nominas, float licencia, float horas_extra, float imprevistos) {
        this.nominas = Math.max(IMPORTE_MINIMO,nominas);
        this.licencia = Math.max(IMPORTE_MINIMO,licencia);
        this.horas_extra = Math.max(IMPORTE_MINIMO,horas_extra);
        this.imprevistos = Math.max(IMPORTE_MINIMO,imprevistos);
        actualizaTotal();
    }

    private void actualizaTotal() {
        total=nominas+licencia+horas_extra+imprevistos;
    }

    Presupuesto clonar(){
        return new Presupuesto(nominas,licencia,horas_extra,imprevistos);
    }

    public void prolongar(float factor) {
        nominas*=factor;
        horas_extra*=factor;
        imprevistos*=factor;
        actualizaTotal();
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Presupuesto:\n");
        sb.append("\t\tNóminas: ").append(String.format("%.2f€\n",nominas));
        sb.append("\t\tLicencia: ").append(String.format("%.2f€\n",licencia));
        sb.append("\t\tHoras Extra: ").append(String.format("%.2f€\n",horas_extra));
        sb.append("\t\tImprevistos: ").append(String.format("%.2f€\n",imprevistos));
        sb.append("\t\tTotal: ").append(String.format("%.2f€",total));
        return sb.toString();
    }

    float getImprevistos() {
        return imprevistos;
    }
}
