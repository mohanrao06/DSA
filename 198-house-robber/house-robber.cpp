class Solution {
public:
    int fun(int ind,vector<int>& nums,vector<int> &dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int nottake=0+fun(ind+1,nums,dp);
        int take=nums[ind];
        if(ind+2<nums.size()){
            take+=fun(ind+2,nums,dp);
        }
        return dp[ind]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(0,nums,dp);
    }
};