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
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                dp[i]=1;
                continue;
            }
            for(int j=1;j<=nums[i];j++){
                if(i+j<n){
                    if(dp[i+j]){
                        dp[i]=1;
                        break;
                    }
                }
            }
           
        }
        return dp[0];
    }
};