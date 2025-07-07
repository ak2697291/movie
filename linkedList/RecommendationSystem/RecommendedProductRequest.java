package linkedList.RecommendationSystem;

import java.util.List;
public class RecommendedProductRequest {
    private String userID;
    private List<String> recommendedProducts;

    public List<String> getRecommendedProducts() {
        return recommendedProducts;
    }
    public String getUserID() {
        return userID;
    }
    public void setRecommendedProducts(List<String> recommendedProducts) {
        this.recommendedProducts = recommendedProducts;
    }

    public void setUserID(String userID) {
        this.userID = userID;
    }

}
