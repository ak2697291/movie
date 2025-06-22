package linkedList.DesignPatterns;

public class DesignPattern {
    
    public class SingletonDesignPattern {
        private static SingletonDesignPattern singletonDesignPattern;
        private static DesignPattern designPattern = new DesignPattern();
        static {
            singletonDesignPattern = designPattern.new SingletonDesignPattern();
        }

        private SingletonDesignPattern(){

        }

        public static SingletonDesignPattern gSingletonDesignPattern(){

            return singletonDesignPattern;
        }
    }

    public class SingletonDesignPattern2{
        private static SingletonDesignPattern2 singletonDesignPattern2;
        private static DesignPattern  designPattern = new DesignPattern();

        private SingletonDesignPattern2(){

        }

        public static SingletonDesignPattern2 gSingletonDesignPattern2(){
                synchronized(SingletonDesignPattern2.class){
            if (singletonDesignPattern2 == null){
            
                    singletonDesignPattern2 = designPattern.new SingletonDesignPattern2();
                
            }
        }

            return singletonDesignPattern2;
        }
    }
    public static void main (String[] args){

        SingletonDesignPattern singletonDesignPattern = SingletonDesignPattern.gSingletonDesignPattern();

        System.out.println(singletonDesignPattern);
        System.out.println(singletonDesignPattern);
        System.out.println(singletonDesignPattern);
        System.out.println(singletonDesignPattern);
        System.out.println(singletonDesignPattern);
        System.out.println("\n");
        SingletonDesignPattern2 singletonDesignPattern2 = SingletonDesignPattern2.gSingletonDesignPattern2();
        System.out.println(singletonDesignPattern2);
        System.out.println(singletonDesignPattern2);
        System.out.println(singletonDesignPattern2);
        System.out.println(singletonDesignPattern2);
        System.out.println(singletonDesignPattern2);
    }
}
