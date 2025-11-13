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
    int change(int amount, vector<int>& arr) {
        int n=arr.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long> (amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%arr[0]==0){
                dp[0][i]=1;
            }else{
                dp[0][i]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                unsigned long long nottake=dp[i-1][j];
                unsigned long long take=0;
                if(arr[i]<=j){
                    take=dp[i][j-arr[i]];
                }
                dp[i][j]=take+nottake;
            }
        }
        return (int)dp[n-1][amount];
    }
};