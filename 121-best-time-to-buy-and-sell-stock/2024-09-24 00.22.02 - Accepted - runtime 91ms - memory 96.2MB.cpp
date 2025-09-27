class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int profit=0;
      int bbuy=prices[0];
      for(int i=1;i<prices.size();i++){
        if(prices[i]>=bbuy){
            profit=max(profit,prices[i]-bbuy);

        }
        bbuy=min(bbuy,prices[i]);
      }
      return profit;
        
    }
};