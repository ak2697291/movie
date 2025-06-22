package linkedList;
import java.util.*;
import java.time.*;
/*
 * Design a parking lot :
 * functional requirements:
 * we need to design a multi level parking lot
 * it should have 3 kind of vehicle parking (small, medium and large)
 * it should have a ticketing system which can allot a particular space to a vehicle
 * it should have cash and online payment system
 * it should have a particular set of prices for a particular type vehicle with respect to the time it is being there.
 * 
 * non functional requirement:
 * how much traffic are we dealing with? (100 vehicle per hour)
 * how much parking space do we have (let's assume we have 1000 vehicle parking space(small 750, medium 200, large 50))
 * for how much a particular vehicle stays(small vehicle people - 1 hr, medium vehicle people - 2 hrs, large vehicle people - 3hrs)
 * small - 30 Rs/hr, medium - 50 Rs/hr, large - 80 Rs/hr
 * 
 */

 /* Class diagram
 1. ParkingLot
    - attributes:
    a) int: numberOfLevels
    b) int: levelParkingSpace
    c)String: address
    d)String: parkingLotId
    e)List<Customer>: customers
    - methods:
    a) int: getTotalVehicle
    b) int: getDailyEarning
    c) List<Object>: getVehicleCountByCategory
2. Customer
    - attributes:
    a) String: userId
    b) VechicleType: vechicleType
    c) boolean: isParked
    d) LocalDateTime: entry
    e) LocalDateTime: exit
    f) Double: payment
    g) int: visitedCount
    h)Ticket: ticket
    i)ParkingSpace: parkingSpace
3. Ticket
  * -attributes:
  a) String:ticketId
  b) String: userId
  c) LocalDateTime: entry
  d) int: price
  e) ParkingSpace: parkingSpace

4. ParkingSpace
  - attributes:
  a) String: parkingSpaceId
  b) int: level
  c) int: spaceNumber
  d) bool isAvailable
  e) Customer: customer
  */

public class ParkingLot {
     int numberOfLevels = 3;
     int levelParkingSpace = 350;
     String address;
     String parkingLotId;
     double todayEarning = 0;
     HashMap<String,Customer> customers;

     List<ParkingSpace> currentlyAvailableParkingSpace = new ArrayList<>();

    ParkingLot(String address, String parkingLotId, HashMap<String,Customer> customers){
      this.address = address;
      this.parkingLotId = parkingLotId;
      this.customers = customers;

      for(int i=0;i<numberOfLevels;i++){
        for(int j =0;j<levelParkingSpace;j++) {
          currentlyAvailableParkingSpace.add(new ParkingSpace(i, j));
        }

      }
     }

     public int getNumberOfLevels(){
      return this.numberOfLevels;
     }

     public int getLevelParkingSpace(){
      return this.levelParkingSpace;
     }

     public String getAddress(){
      return this.address;
     }

    public double getPayment(long hoursStayed, VechicleType vechicleType){
      int price = 0;
      if (vechicleType.equals(VechicleType.SMALL)){
        price = 30;
      }
      if (vechicleType.equals(VechicleType.MEDIUM)){
        price = 50;
      }
      if (vechicleType.equals(VechicleType.LARGE)){
        price = 80;
      }
      return hoursStayed * price;
     }

     public String entryCustomer(Customer customer){

      for( Customer customer1: customers.values()){
        if (customer1.isParked && customer1.getUserId().equals(customer.getUserId())){
          return "Customer is Already Parked - " + customer.userId;
        }

      }
      Ticket parkingTicket = new Ticket(customer.userId, customer.vechicleType);
      if (currentlyAvailableParkingSpace.size() == 0){
        return "Parking Lot is Full";
      }
      customer.setTicket(parkingTicket);
      customer.setEntry(LocalDateTime.now());
      customer.setParked(true);
      customer.setParkingSpace(parkingTicket.getParkingSpace());
      customer.setVisitedCount(customer.getVisitedCount() + 1);
      customers.put(customer.getUserId(), customer);

      return "Customer Parked Successfully";
     }
   
     public double exitCustomer(Customer customer){

      Ticket ticket = customer.getTicket();
      LocalDateTime localDateTime = ticket.getEntry();
      long hoursStayed = Duration.between(localDateTime, LocalDateTime.now()).toHours();
      double payment = getPayment(hoursStayed, customer.vechicleType);
      customer.setExit(LocalDateTime.now());
      customer.setParked(false);
      customer.setPayment(payment);
      currentlyAvailableParkingSpace.add(customer.getParkingSpace());
      return payment;
     }

     public ParkingSpace getAvailableParkingSpace(){

      return currentlyAvailableParkingSpace.remove(0);
     }

    public class Customer {
    
       String userId;
       VechicleType vechicleType;
       boolean isParked;
       LocalDateTime entry;
       LocalDateTime exit;
       double payment;
       int visitedCount = 0;
       Ticket ticket;
       ParkingSpace parkingSpace;

       Customer (String userId, VechicleType vechicleType){
        this.userId = userId;
        this.vechicleType = vechicleType;
       }

       public boolean getParked(){
        return this.isParked;
       }
       public void setTicket(Ticket ticket) {
           this.ticket = ticket;
       }
       public LocalDateTime getEntry() {
           return entry;
       }public void setEntry(LocalDateTime entry) {
           this.entry = entry;
       }public void setExit(LocalDateTime exit) {
           this.exit = exit;
       }public LocalDateTime getExit() {
           return exit;
       }public void setParked(boolean isParked) {
           this.isParked = isParked;
       }public ParkingSpace getParkingSpace() {
           return parkingSpace;
       }public void setParkingSpace(ParkingSpace parkingSpace) {
           this.parkingSpace = parkingSpace;
       }public double getPayment() {
           return payment;
       }public void setPayment(double payment) {
           this.payment = payment;
       }public Ticket getTicket() {
           return ticket;
       }public void setUserId(String userId) {
           this.userId = userId;
       }public String getUserId() {
           return userId;
       }public void setVechicleType(VechicleType vechicleType) {
           this.vechicleType = vechicleType;
       }public VechicleType getVechicleType() {
           return vechicleType;
       }public void setVisitedCount(int visitedCount) {
           this.visitedCount = visitedCount;
       }public int getVisitedCount() {
           return visitedCount;
       }
    }
    public class Ticket {
     String ticketId;
     String userId;
     LocalDateTime entry;
     VechicleType vechicleType;
     ParkingSpace parkingSpace;

      Ticket(String userId, VechicleType vechicleType){
        this.ticketId = getTicketId(userId);
        this.userId = userId;
        this.entry = LocalDateTime.now();
        this.vechicleType = vechicleType;
        this.parkingSpace = getAvailableParkingSpace();

      
      }
      private String getTicketId(String userId){
        return userId + LocalDateTime.now().toString();
      }
      public ParkingSpace getParkingSpace() {
          return parkingSpace;
      }public void setEntry(LocalDateTime entry) {
          this.entry = entry;
      }public LocalDateTime getEntry() {
          return entry;
      }public String getUserId() {
          return userId;
      }public VechicleType getVechicleType() {
          return vechicleType;
      }public void setParkingSpace(ParkingSpace parkingSpace) {
          this.parkingSpace = parkingSpace;
      }public void setTicketId(String ticketId) {
          this.ticketId = ticketId;
      }public void setUserId(String userId) {
          this.userId = userId;
      }public void setVechicleType(VechicleType vechicleType) {
          this.vechicleType = vechicleType;
      }
    }
    public class ParkingSpace {
      String parkingSpaceId;
      int level;
      int spaceNumber;



      ParkingSpace(int level, int spaceNumber){
        this.parkingSpaceId = Integer.toString(level) + Integer.toString(spaceNumber);
        this.level = level;
        this.spaceNumber = spaceNumber;
      }

    }

    public enum VechicleType{
      SMALL,
      MEDIUM,
      LARGE;
    }

    public int getTotalStandingVehicle(){

    return (int) customers.values().stream().filter(customer-> customer.getParked()).count();

    }
    
    public class VehicleCount {
    VechicleType vechicleType;
    int count;
    public int getCount() {
        return count;
    }
    public VechicleType getVechicleType() {
        return vechicleType;
    }
    public void setCount(int count) {
        this.count = count;
    }
    public void setVechicleType(VechicleType vechicleType) {
        this.vechicleType = vechicleType;
    }
    }
    public List<VehicleCount> getVehicleCountByCategory(List<Customer> customers){
      List<VehicleCount> vehicleCounts = new ArrayList<>();
      int smallVehicleCount = 0;
      int mediumVehicleCount = 0;
      int largeVehicleCount= 0;

      for (Customer customer : customers) {
        if (customer.vechicleType == VechicleType.SMALL) smallVehicleCount += 1;
        if (customer.vechicleType == VechicleType.MEDIUM) mediumVehicleCount += 1;
        if (customer.vechicleType == VechicleType.LARGE) largeVehicleCount += 1;
      }

      VehicleCount smallVehicle = new VehicleCount();
      smallVehicle.setVechicleType(VechicleType.SMALL);
      smallVehicle.setCount(smallVehicleCount);

      VehicleCount medVehicle = new VehicleCount();
      medVehicle.setVechicleType(VechicleType.MEDIUM);
      medVehicle.setCount(mediumVehicleCount);

      VehicleCount largeVehicle = new VehicleCount();
      largeVehicle.setVechicleType(VechicleType.LARGE);
      largeVehicle.setCount(largeVehicleCount);

      vehicleCounts.add(smallVehicle);
      vehicleCounts.add(largeVehicle);
      vehicleCounts.add(medVehicle);

      return vehicleCounts;
    }
    public static void main (String args[]){

      ParkingLot parkingLot = new ParkingLot("123 abc Parking Lot", "PKID_1234",new HashMap<>());
      Customer customer0 = parkingLot.new Customer("customer0",VechicleType.SMALL);
      Customer customer1 = parkingLot.new Customer("customer1",VechicleType.SMALL);
      Customer customer2 = parkingLot.new Customer("customer2",VechicleType.MEDIUM);
      Customer customer3 = parkingLot.new Customer("customer2",VechicleType.SMALL);
      Customer customer4 = parkingLot.new Customer("customer3",VechicleType.LARGE);

      System.out.println(parkingLot.entryCustomer(customer0));
      System.out.println(parkingLot.entryCustomer(customer1));
      System.out.println(parkingLot.entryCustomer(customer2));
      System.out.println(parkingLot.entryCustomer(customer3));
      System.out.println(parkingLot.entryCustomer(customer4));
      System.out.println(parkingLot.getTotalStandingVehicle());
      System.out.println(parkingLot.exitCustomer(customer4));
      System.out.println(parkingLot.getTotalStandingVehicle());
    }
}