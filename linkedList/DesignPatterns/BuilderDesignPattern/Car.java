package linkedList.DesignPatterns.BuilderDesignPattern;

public class Car {
   
    private String name;
    private String make;
    private String model;
    private String capacity;
    private String maxSpeed;
    private String price;

    public Car(String name, String make, String model, String capacity, String maxSpeed, String price){
        this.name = name;
        this.make = make;
        this.model = model;
        this.capacity = capacity;
        this.maxSpeed = maxSpeed;
        this.price = price;
    }
    @Override
    public String toString(){
        return "name: "+ name+ " make: "+make+ " model: "+model+" capacity: "+capacity+" maxSpeed: "+maxSpeed+" price: "+price;
    }

}
