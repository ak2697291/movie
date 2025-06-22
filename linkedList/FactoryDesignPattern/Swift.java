package linkedList.FactoryDesignPattern;

public class Swift implements Cars{

    @Override
    public String  getCarPrice() {
        return "8 Lakhs";
    }

    @Override
    public Features getCarFeatures() {
        Features features= new Features();
        features.setAverage("17 Km/liter");
        features.setColor("white");
        features.setMaxSpeed("130 Km/hr");
        return features;
    }
    
}
