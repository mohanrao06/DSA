class Solution {
public:
    int fun(int ind,int amount, vector<int>& coins,vector<vector<int>> &dp){
        if(amount==0)return 1;
        if(ind>=coins.size())return 0;
        if(dp[ind][amount]!=-1)return dp[ind][amount];

        int nottake=fun(ind+1,amount,coins,dp);
        int take=0;
        if(amount>=coins[ind]){
            take=fun(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return fun(0,amount,coins,dp);
    }
};