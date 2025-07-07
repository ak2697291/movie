package linkedList.RecommendationSystem;


public class InteractionEventEntity {
    /*
     * interaction_events_collection
        InteractionEventsCollection
    - String : UserId
    - String : productId
    - Enum   : eventType(BUY/VIEW)
    - long : eventTimestamp
    - Enum : status (ACTIVE/EXPIRE)
     */

    private String userId;
    private String interactionId;
    private String productId;
    private EventType eventType;
    private long eventTimestamp;
    private StatusType status;

    public InteractionEventEntity(String userId, String productId, EventType eventType, String interactionId){
        this.userId = userId;
        this.interactionId = interactionId;
        this.productId = productId;
        this.eventType = eventType;
        eventTimestamp = System.currentTimeMillis();
        status = StatusType.ACTIVE;
    }

    public long getEventTimestamp() {
        return eventTimestamp;
    }
    public String getUserId() {
        return userId;
    }
    public String getProductId() {
        return productId;
    }
    public void setStatus(StatusType status) {
        this.status = status;
    }
    public StatusType getStatus() {
        return status;
    }
    public EventType getEventType() {
        return eventType;
    }
    public String getInteractionId() {
        return interactionId;
    }
    public void setInteractionId(String interactionId) {
        this.interactionId = interactionId;
    }

    @Override
    public String toString(){
        return "userId: "+userId +" interactionId: "+ interactionId + " productId: "+ productId + " eventType: "+eventType + " eventTimeStamp: "+eventTimestamp + " status: "+ status;
    }
}
