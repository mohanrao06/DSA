class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        if(totalsum - target < 0 || (totalsum - target) % 2 != 0) return 0;
        
        int sum=(totalsum-target)/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++)dp[i][0]=1;
        if(nums[0]==0)dp[0][0]=2;
        else dp[0][0]=1;
        
        if(nums[0] != 0 && nums[0] <= sum) dp[0][nums[0]] = 1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(j>=nums[i]){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=nottake+take;
            }
        }
        
        
        
        
        
        return dp[n-1][sum];

    }
};