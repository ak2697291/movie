package linkedList.FactoryDesignPattern;

public class Features {
    
    private String maxSpeed;
    private String average;
    private String color;
    public Features(){
        
    }
    public Features(String maxSpeed, String average, String color){
        this.maxSpeed = maxSpeed;
        this.average = average;
        this.color = color;
    }

    public String getAverage() {
        return average;
    }
    public void setAverage(String average) {
        this.average = average;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }public void setMaxSpeed(String maxSpeed) {
        this.maxSpeed = maxSpeed;
    }public String getMaxSpeed() {
        return maxSpeed;
    }


    @Override
    public String toString() {
return "maxSpeed: "+ this.maxSpeed + " average: "+this.average+" color:" +this.color;
    }

}
