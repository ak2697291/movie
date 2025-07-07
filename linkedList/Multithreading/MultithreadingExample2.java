package linkedList.Multithreading;

public class MultithreadingExample2 implements Runnable{

    @Override
    public void run (){

        for(int i=0;i<5;i++){
            System.out.println("Hell0_ " + i);
            try {
            Thread.sleep(1000);
            }catch(Exception e){

            }
        }
    }
    
}
