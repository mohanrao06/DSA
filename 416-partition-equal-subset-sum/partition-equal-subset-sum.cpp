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
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<n;i++)dp[i][0]=true;
         if (nums[0] <= target) dp[0][nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool notpick=dp[i-1][j];
                bool pick=false;
                if(j>=nums[i]){
                    pick=dp[i-1][j-nums[i]];
                }
                dp[i][j]=pick||notpick;
            }
        }
        return dp[n-1][target];
    }
};