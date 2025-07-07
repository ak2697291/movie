package linkedList.RecommendationSystem;

import java.util.ArrayList;
import java.util.List;

public class InteractionService {
/*
1. it will be storing the interaction event to the interaction_event_collection -- Done
2. it will be storing the interaction event to the cache purchase/ view table --Done
3. it will be filtering the products based on the filters provided via recommendation service. -- Done
4. it will be used for bulk load previous interactions.


*/    

private CacheService cacheService = new CacheService();

public void interactionEventListener(InteractionEvent interactionEvent){

    String Key = interactionEvent.getUserId() + "_" + interactionEvent.getProductId();
    EventType eventType = interactionEvent.getEventType();

    if (eventType == EventType.BUY) cacheService.addPurchase(Key);

    else cacheService.addView(Key);

    InteractionDB.insertInteractionEvent( new InteractionEventEntity(interactionEvent.getUserId(), interactionEvent.getProductId(), eventType, interactionEvent.getInteractionId()));

}

public FilteredRecommendedProductResponse getFilteredRecommendedProducts(RecommendedProductRequest recommendedProductRequest){

    FilteredRecommendedProductResponse filteredRecommendedProductResponse = new FilteredRecommendedProductResponse();
    String userID = recommendedProductRequest.getUserID();
    filteredRecommendedProductResponse.setUserID(userID);

    List<String> recommendedProducts = recommendedProductRequest.getRecommendedProducts();
    recommendedProducts.stream().filter(product-> cacheService.searchKey(userID+"_"+product)).toList();
    
    List<String> filteredRecommendedProducts = new ArrayList<>();
    filteredRecommendedProducts = recommendedProducts.stream().filter(product-> cacheService.searchKey(userID+"_"+product)).toList();
  
    filteredRecommendedProductResponse.setFilteredRecommendedProducts(filteredRecommendedProducts);


    return filteredRecommendedProductResponse;

}


public List<InteractionEventEntity> getBulkInteractionEventEntities(String userId){

    return InteractionDB.getActiveInteractionEventsByUserId(userId);

}


}
