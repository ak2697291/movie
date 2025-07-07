package linkedList.Multithreading;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Multithreading {
    
    public static void main (String [] args){

        MultithreadingExample1 multithreadingExample1 = new MultithreadingExample1();
        multithreadingExample1.start();
     
        System.out.println("hello");


        MultithreadingExample2 multithreadingExample2 = new MultithreadingExample2();

        Thread thread = new Thread(multithreadingExample2);

        ExecutorService executor = Executors.newFixedThreadPool(3);
        Runnable task1 = () -> System.out.println("hello 1");
        Runnable task2 = () -> System.out.println("hello 2");
        Runnable task3 = () -> System.out.println("hello 3");
        executor.submit(task1);
        executor.submit(task2);
        executor.submit(task3);
        // for returning some result;
        Callable<String> task  = () -> {
            Thread.sleep(1000);
            return "hello world";
        };

        Future<String> future = executor.submit(task);

        try{
            String mystring = future.get();
            System.out.println(mystring);
        }catch(Exception e){

        }
executor.shutdown();
        thread.start();
    }
}
