class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int profit=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>profit){
                max_profit=max(prices[i]-profit,max_profit);

            }
            profit=min(profit,prices[i]);
            


        }
        return max_profit;
    }
};