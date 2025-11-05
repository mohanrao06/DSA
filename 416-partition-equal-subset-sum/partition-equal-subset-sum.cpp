class Solution {
public:
    bool fun(int i,int target,vector<int> &nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(i==0)return(nums[i]==target);
        if(dp[i][target]!=-1)return dp[i][target];

        bool notpick=fun(i-1,target,nums,dp);
        bool pick=false;
        if(target>=nums[i]){
            pick=fun(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target]=pick||notpick;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2)return false;
        int target=sum/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return fun(n-1,target,nums,dp);
    }
};