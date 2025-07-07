package linkedList.RecommendationSystem;

import java.util.HashSet;
import java.util.Set;

public class CacheService {
    
    private Set<String> purchase;
    private Set<String> view;

    public CacheService() {
        this.purchase = new HashSet<>();
        this.view = new HashSet<>();
    }

    public boolean addPurchase(String purchaseKey){
        try {
        purchase.add(purchaseKey);
        return true;
        }catch(Exception ex){

        }
        return false;
    }

       public boolean addView(String viewKey){
        try {
        view.add(viewKey);
        return true;
        }catch(Exception ex){

        }
        return false;
    }

        public boolean searchKey(String searchKey){
            if (view.contains(searchKey) || purchase.contains(searchKey)){
                return false;
            }

            return true;
        }


}
