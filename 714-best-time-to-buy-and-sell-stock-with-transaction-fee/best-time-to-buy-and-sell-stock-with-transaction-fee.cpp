class Solution {
public:
    int fun(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp,int fee){
        if(ind==prices.size())return 0;

        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+fun(ind+1,0,prices,dp,fee),fun(ind+1,1,prices,dp,fee));
        }
        else{
            profit=max(prices[ind]+fun(ind+1,1,prices,dp,fee)-fee,fun(ind+1,0,prices,dp,fee));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {

        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,1,prices,dp,fee);
        // int n=prices.size();
        // vector<long> prev(2,0),curr(2,0);
        // prev[0]=prev[1]=0;
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         int profit=0;
        //         if(buy){
        //             profit=max(-prices[ind]+prev[0],prev[1]);
        //         }
        //         else{
        //             profit=max((prices[ind]-fee)+prev[1],prev[0]);
        //         }
        //         curr[buy]=profit;
        //     }
        //     prev=curr;
        // }
        // return prev[1];

        
    }
};