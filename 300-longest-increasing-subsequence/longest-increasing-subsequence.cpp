class Solution {
public:
    int fun(int ind,int prev,vector<vector<int>> &dp,vector<int>& nums){
        if(ind==nums.size())return 0;

        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

        int len=fun(ind+1,prev,dp,nums);
        
        if(prev==-1 || nums[ind]>nums[prev]){
            len=max(len,1+fun(ind+1,ind,dp,nums));
        }
        return dp[ind][prev+1]=len;

        
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fun(0,-1,dp,nums);
        
    }
};