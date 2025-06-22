package linkedList.FactoryDesignPattern;

public class Thar  implements Cars{
 
    @Override
    public String getCarPrice(){
        return "24 Lakhs";
    }

    @Override
    public Features getCarFeatures(){
        Features features= new Features();
        features.setAverage("14.5 Km/liter");
        features.setColor("black");
        features.setMaxSpeed("150 Km/hr");
        return features;

    }
    
}
