package linkedList.FactoryDesignPattern;

public class FactoryDesignPattern {
    
    public static void main(String [] args){
        Factory factory = new Factory();
        Cars car = null;
        try{
        car = factory.getCar("SWIFT1");
        } catch (Exception e){
            System.out.println("Exception Occurred While getting the car: " +e);
        }
        if (car == null){
            System.out.println("Car Not present");
        }else {
            System.out.println(car.getCarPrice());
            System.out.println(car.getCarFeatures().toString());
        }

    }

    

}
