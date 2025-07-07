package linkedList.RecommendationSystem;

import java.util.UUID;

public class InteractionEvent {
    
    /*
     * InteractionEvent 
    - String : UserId
    - String : productId
    - Enum   : eventType(BUY/VIEW)
     */
    private String userId;
    private String interactionId;
    private String productId;
    private EventType eventType;

    public InteractionEvent (String userId, String productId, EventType eventType){
        this.userId = userId;
        this.productId = productId;
        this.eventType = eventType;
        this.interactionId = UUID.randomUUID().toString();
    }

    public String getUserId() {
        return userId;
    }

    public EventType getEventType() {
        return eventType;
    }
    public String getProductId() {
        return productId;
    }
    public String getInteractionId() {
        return interactionId;
    }
    
}
