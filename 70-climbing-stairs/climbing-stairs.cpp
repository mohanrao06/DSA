class Solution {
public:
    int dfs(int n,int ind,vector<int> &dp){
        if(ind==n)return 1;
        if(ind>n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int stepone=dfs(n,ind+1,dp);
        int steptwo=dfs(n,ind+2,dp);
        return dp[ind]=stepone+steptwo;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return dfs(n,0,dp);
    }
};