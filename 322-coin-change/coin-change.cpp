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
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake=0+dp[i-1][j];
                int take=1e9;
                if(j>=coins[i]){
                    take=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(take,nottake);
            }
        }
        if(dp[n-1][amount]==1e9){
            return -1;
        }
        return dp[n-1][amount];
        
    }
};