class Solution {
public:
    int fun(int ind,vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(amount==0)return 0;
        if(ind>=coins.size())return 1e9;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nottake=fun(ind+1,coins,amount,dp);
        int take=1e9;
        if(amount>=coins[ind]){
            take=1+fun(ind,coins,amount-coins[ind],dp);
        }
        
        return dp[ind][amount]= min(take,nottake);   
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
       
       
        for(int ind = 0; ind <= n; ind++) {
        dp[ind][0] = 0;
    }

       for(int ind=n-1;ind>=0;ind--){
            for(int amt=0;amt<=amount;amt++){
                int nottake=dp[ind+1][amt];
                int take=1e9;
                if(amt>=coins[ind]){
                    take=1+dp[ind][amt-coins[ind]];
                }
            
                dp[ind][amt]= min(take,nottake); 
            }
       }
        int ans=dp[0][amount];
       if(ans==1e9)return -1;
       return ans;
    }
};