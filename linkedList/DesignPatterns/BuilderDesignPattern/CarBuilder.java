package linkedList.DesignPatterns.BuilderDesignPattern;

public class CarBuilder {
    
    private String name;
    private String make;
    private String model;
    private String capacity;
    private String maxSpeed;
    private String price;

    public CarBuilder name (String name){
        this.name = name;
        return this;
    }
    public CarBuilder make(String make){
        this.make = make;
        return this;
    }

    public CarBuilder model(String model){
        this.model = model;
        return this;
    }
    public CarBuilder capacity(String capacity){
        this.capacity = capacity;
        return this;
    }
    public CarBuilder maxSpeed(String maxSpeed){
        this.maxSpeed = maxSpeed;
        return this;
    }
    public CarBuilder price(String price) {
        this.price = price;
        return this;
    }

    public Car build(){
        return new Car(name, make, model, capacity, maxSpeed, price);
    }
}
