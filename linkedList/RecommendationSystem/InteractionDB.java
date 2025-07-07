package linkedList.RecommendationSystem;

import java.util.ArrayList;
import java.util.List;
public class InteractionDB {

    private static List<InteractionEventEntity> interactionEventCollection = new ArrayList<>();

    public static InteractionEventEntity insertInteractionEvent(InteractionEventEntity interactionEvent){
        interactionEventCollection.add(interactionEvent);
        return interactionEvent;
    }

    public static List<InteractionEventEntity> getActiveInteractionEventsByUserId(String userId){
       return interactionEventCollection.stream().filter(interactionEvent -> interactionEvent.getUserId().equals(userId) && interactionEvent.getStatus().equals(StatusType.ACTIVE)).toList();
    }



    
}
