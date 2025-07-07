package linkedList.Multithreading;

public class MultithreadingExample1 extends Thread{
    @Override
    public void run (){

        for(int i=0;i<5;i++){
            System.out.println(i);
            try{
            Thread.sleep(1000);
            }catch(Exception e){
                
            }
        }

    }
    
}
