public class Main{

    public static void main(String[] args) throws Exception{

        tThreads time1 = new tThreads("Brasil", 1);
        tThreads time2 = new tThreads("Argentina", 0);

        time1.start();
        time2.start();

    }
    
}