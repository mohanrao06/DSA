class Solution {
public:
    int fun(int ind,int t,vector<int> &arr,vector<vector<int>> &dp){
        if(ind==0){
            if(t%arr[ind]==0)return 1;
            else{
                return 0;
            }
        }
        if(dp[ind][t]!=-1)return dp[ind][t];
        int nottake=fun(ind-1,t,arr,dp);
        int take=0;
        if(arr[ind]<=t){
            take=fun(ind,t-arr[ind],arr,dp);
        }
        return dp[ind][t]=nottake+take;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return fun(n-1,amount,coins,dp);
    }
};