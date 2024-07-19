class Solution {
public: 
    int maxProfit(vector<int>& prices) {
        int currPrice = prices[0];
        int profit = 0;
        int n = prices.size();

        for(int i=1; i<n; i++){
            if(prices[i] < currPrice){
                
                currPrice = prices[i];
            }else{
                int price = prices[i] - currPrice; 
                
                if(price > profit){
                    profit = price;
                }
                
            }
        }

        return profit;
    }
};
