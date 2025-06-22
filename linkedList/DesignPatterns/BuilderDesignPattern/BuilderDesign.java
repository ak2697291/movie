package linkedList.DesignPatterns.BuilderDesignPattern;

public class BuilderDesign {
    

    public static void main (String [] args){

        Car car = new CarBuilder().name("THAR").make("TATA").model("XYZ").maxSpeed("150").build();

        System.out.println(car.toString());
    }
}
