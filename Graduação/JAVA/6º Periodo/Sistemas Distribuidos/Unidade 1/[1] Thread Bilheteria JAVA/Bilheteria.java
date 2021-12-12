public class Bilheteria extends Thread{
	
	public static int NIngressos=0;
	
	public static void main(String[] args) throws Exception{
		
		System.out.println("Numeros de Cartelas Inicial: 0");
		
		Bilheteria Fabrica = new Bilheteria("Fabrica");
		Bilheteria Comprador1 = new Bilheteria("Comprador1");
		Bilheteria Comprador2 = new Bilheteria("Comprador2");
		Bilheteria Comprador3 = new Bilheteria("Comprador3");
		Bilheteria Comprador4 = new Bilheteria("Comprador4");
		Bilheteria Comprador5 = new Bilheteria("Comprador5");
		
		Fabrica.start();
		Comprador1.start();
		Comprador2.start();
		Comprador3.start();
		Comprador4.start();
		Comprador5.start();
			  
	}
    public Bilheteria(String id) throws InterruptedException{ 
    	
    	super(id);
    	
    }
    public void run(){
    	
    	while(NIngressos<15){
    	
	    	if(getName()=="Fabrica")
	    		Bilheteria.metodo(5, getName());
	    	else
	    		Bilheteria.metodo(-1, getName());
	    	
			try {Thread.sleep(1000);}
			catch (InterruptedException e){e.printStackTrace();} 
    	
    	}
    	   	
    }
    public synchronized static void metodo(int num, String id){
    	
    	if(NIngressos>0 || num==5)
    		NIngressos+=num;
    	else
    		System.out.print("SEM INGRESSOS ");
    	System.out.println(id + " " + NIngressos);

    }
	
}