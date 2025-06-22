package linkedList;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
// import java.util.stream.Collectors;

import linkedList.FactoryDesignPattern.Features;

public class JavaStream {
    
    public class Mapper{
        String maximumSpeed;
        String allowedAverage;
        String givenColor;

        public Mapper(String speed, String average, String color){
            maximumSpeed = speed;
            allowedAverage = average;
            givenColor = color;
        }

        @Override
        public String toString(){
            return "maximumSpeed: " + maximumSpeed + " allowedAverage: "+ allowedAverage + " givenColor: " + givenColor;
        }

        @Override
        public boolean equals(Object o){
            if (this == o){
                return true;
            }
            if (o == null || o.getClass() != this.getClass())return false;
            Mapper oMapper = (Mapper)o;
            return maximumSpeed.equals(oMapper.maximumSpeed)&&allowedAverage.equals(oMapper.allowedAverage)&&givenColor.equals(oMapper.givenColor);
        }

        @Override
        public int hashCode(){
            return Objects.hash(maximumSpeed, allowedAverage, givenColor);
        }
        
    }
 
       public Mapper getMappedClass(Features features){
        return new Mapper(features.getMaxSpeed(), features.getAverage(), features.getColor());
 
    }
    public static void main(String [] args){
        List<Features> features = new ArrayList<>();

        features.add(new Features("120 Km/hr", "15 Km/l", "Red"));
        features.add(new Features("150 Km/hr", "14 Km/l", "Black"));
        features.add(new Features("130 Km/hr", "17 Km/l", "White"));
        features.add(new Features("120 Km/hr", "15 Km/l", "Red"));
        JavaStream javaStream = new JavaStream();
        // List<Features> features2 = features.stream().filter(f->f.getColor().equals("Red")).collect(Collectors.toList());
        List<Mapper> mappers = features.stream().filter(f->f.getColor().equals("Red")).map(javaStream::getMappedClass).distinct().toList();
        for(Mapper mapper: mappers){
            System.out.println(mapper.toString());
        }




    }
}
