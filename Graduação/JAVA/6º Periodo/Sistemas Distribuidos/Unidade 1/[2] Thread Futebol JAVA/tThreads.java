public class tThreads extends Thread{

    private int l; 
    public static int comp=0;
    
    public tThreads(String nome, int num) throws InterruptedException{

    	super(nome);
    	l=num;
    	
    }
    public void run(){

        for (int x=l+5; l<x; l++){
        	
        	while(getName()=="Brasil" && comp!=0){}
        	while(getName()=="Argentina" && comp!=1){}

        	System.out.println(l + getName());
    		comp++;
    		if(comp==2){comp=0;}

        	if(getName()=="Argentina" && l==4)
        		System.out.println("DONE!!");
 	
			try {Thread.sleep(1000);}
			catch (InterruptedException e){e.printStackTrace();}
        	    	
        }	  	
    	
    }

}