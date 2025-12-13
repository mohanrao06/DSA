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
        vector<vector<vector<int>>> dp(
            n+1,
            vector<vector<int>>(2, vector<int>(k + 1, 0))
        );
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int K=1;K<=k;K++){
                    int profit=0;
                    if(buy){
                        profit = max(
                            -prices[ind]+dp[ind+1][0][K],
                            dp[ind+1][1][K]
                        );

                    }else{
                        profit = max(
                            prices[ind]+dp[ind+1][1][K-1],
                            dp[ind+1][0][K]
                        );
                    }
                    dp[ind][buy][K]=profit;
                }
            }
        }
        return dp[0][1][k];
    }
};