class Solution {
public:
    int fun(vector<int>& nums,int ind,vector<int> &dp){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int curr=nums[ind]+fun(nums,ind+2,dp);
        int next=0+fun(nums,ind+1,dp);
        return dp[ind]= max(curr,next);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            int nottake=dp[i+1];
            int take=nums[i]+dp[i+2];
            dp[i]=max(take,nottake);
        }

        return dp[0];



        
    }
};