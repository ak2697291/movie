package linkedList.RecommendationSystem;

import java.util.ArrayList;
import java.util.List;

/*Problem Statement
 * 
 * Amazon has recommendation service that recommend products to users based on their previous interactions like viewing the product or buying one. 
 * You need to design a service wherein you can capture user interactions which could further be used by recommendation service. 
 * And also it should have an API to return to filtered products from the recommendation list. 
 * Filter could be like we want recommended products which the user never bought or user viewed didn’t view it in last one month.

Amazon wants to improve its product recommendation system by efficiently checking whether a customer has already viewed or purchased a product. 
This will help avoid showing the same product multiple times, enhance the relevance of recommendations, and improve the user experience.
 
Design a system that tracks the products a user has interacted with (viewed or purchased).
The system must be able to quickly check whether a given product has been viewed or purchased by a user and efficiently handle millions of users and products.

Functional requirements:
1. Checks if the user has already interacted with (viewed or purchased) the product.
2. Adds a product interaction (view or purchase) to the system.
3. Ability to bulk load previous product interactions for new users or for users who have large interaction histories.
4. Support real-time checks to avoid showing products a user has already seen or purchased.






personal thoughts:
we have one interaction service which is responsible for capturing the interaction of the customer with the product whether he buy this product before or not or has viewed this product.
it will have the API which will be open for recommandation system to filter out the product based on the query provided.

                                            BUY/VIEW
client ---> [UI] --->Product 1 ---Generate An Event to the backend---> interaction service.

interaction service---->save this event in mongoDB (persistence of the data)
interaction service ----> add this event in cache (for fast check up)
                        (GET /recommendation/product/filter)
interaction service -----------------------------------------> recommendation service
InteractionEvent 
    - String : UserId
    - String : productId
    - Enum   : eventType(BUY/VIEW)

interaction_events_collection
InteractionEventsCollection
    - String : UserId
    - String : productId
    - Enum   : eventType(BUY/VIEW)
    - long : eventTimestamp
    - Enum : status (ACTIVE/EXPIRE) ---> a job will be created to mark the status of the interaction events if they have been expired or not.

cache event push
tables:
purchase
UserID_ProductID
view
UserID_ProductID 



 */
public class RecommendationSystem {
    
    public static void main (String[] args){


        InteractionService interactionService = new InteractionService();
        interactionService.interactionEventListener(new InteractionEvent("User1", "Product1", EventType.VIEW));
        interactionService.interactionEventListener(new InteractionEvent("User1", "Product2", EventType.VIEW));
        interactionService.interactionEventListener(new InteractionEvent("User1", "Product3", EventType.BUY));
        interactionService.interactionEventListener(new InteractionEvent("User2", "Product2", EventType.BUY));
        
        RecommendedProductRequest recommendedProductRequest = new RecommendedProductRequest();
        recommendedProductRequest.setUserID("User2");
        List<String> products = new ArrayList<>();
        products.add("Product1");
        products.add("Product2");
        products.add("Product3");
        products.add("Product4");
        products.add("Product5");

        
        recommendedProductRequest.setRecommendedProducts(products);

        FilteredRecommendedProductResponse filteredRecommendedProductResponse = interactionService.getFilteredRecommendedProducts(recommendedProductRequest);
        List<String> filteredProducts = filteredRecommendedProductResponse.getFilteredRecommendedProducts();
        System.out.println(filteredProducts);

        List<InteractionEventEntity> interactionEventEntities = interactionService.getBulkInteractionEventEntities("User1");
        System.out.println(interactionEventEntities);
    }
}
