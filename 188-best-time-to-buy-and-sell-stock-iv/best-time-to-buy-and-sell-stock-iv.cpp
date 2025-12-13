class Solution {
public:
    int fun(int ind,int buy,int k,vector<vector<vector<int>>> &dp, vector<int>& prices){
        if(k==0)return 0;
        if(ind==prices.size())return 0;
        if(dp[ind][buy][k]!=-1)return dp[ind][buy][k];
        int profit=0;
        if(buy){
            profit = max(
                -prices[ind]+fun(ind+1,0,k,dp,prices),
                fun(ind+1,1,k,dp,prices)
            );

        }else{
             profit = max(
                prices[ind]+fun(ind+1,1,k-1,dp,prices),
                fun(ind+1,0,k,dp,prices)
            );
        }
        return dp[ind][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> after(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int K=1;K<=k;K++){
                    int profit=0;
                    if(buy){
                        profit = max(
                            -prices[ind]+after[0][K],
                            after[1][K]
                        );

                    }else{
                        profit = max(
                            prices[ind]+after[1][K-1],
                            after[0][K]
                        );
                    }
                    curr[buy][K]=profit;
                }
            }
            after=curr;
        }
        return after[1][k];
    }
};