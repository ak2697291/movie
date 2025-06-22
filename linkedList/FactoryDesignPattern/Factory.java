package linkedList.FactoryDesignPattern;

import java.util.HashMap;

public class Factory {

    
    HashMap<String, Cars> availableCars = new HashMap<>();
     Factory(){
     availableCars.put("THAR", new Thar());
        availableCars.put("SWIFT", new Swift());
        }

        


    public Cars getCar(String carType) throws Exception {
   
        if (!availableCars.containsKey(carType)){
            throw new CarNotFoundException("Car not available");
            
        }
        return availableCars.get(carType);
    }
}
