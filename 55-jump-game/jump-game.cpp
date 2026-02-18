class Solution {
public:
    int dfs(vector<int>& nums,int ind,vector<int> &dp){
        if(ind==nums.size()-1)return 1;
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=1;i<=nums[ind];i++){
            if(dfs(nums,ind+i,dp)){
                return dp[ind]=1;
            }
        }
        return dp[ind]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return dfs(nums,0,dp);
    }
};