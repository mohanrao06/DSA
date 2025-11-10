class Solution {
public:
    int n;
    int fun(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
        if(ind==0){
            if(target%arr[ind]==0)return target/arr[ind];
            else return 1e9;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int nottake=0+fun(ind-1,target,arr,dp);
        int take=1e9;
        if(target>=arr[ind]){
            take=1+fun(ind,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= fun(n-1,amount,coins,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};