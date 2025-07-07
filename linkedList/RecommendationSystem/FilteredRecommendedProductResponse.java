package linkedList.RecommendationSystem;

import java.util.List;

public class FilteredRecommendedProductResponse {
     private String userID;
    private List<String> filteredRecommendedProducts;

    public void setFilteredRecommendedProducts(List<String> filteredRecommendedProducts) {
        this.filteredRecommendedProducts = filteredRecommendedProducts;
    }
    public void setUserID(String userID) {
        this.userID = userID;
    }
    public List<String> getFilteredRecommendedProducts() {
        return filteredRecommendedProducts;
    }
    public String getUserID() {
        return userID;
    }
}
